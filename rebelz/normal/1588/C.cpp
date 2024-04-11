// xtqqwq
#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,top1,top2;
ll a[300005],s[300005];
pll s1[300005],s2[300005],p[300005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=1;i<=n;i++) s[i]=s[i-1]+(i&1?a[i]:-a[i]);
		for(int i=1;i<=n;i++) p[i]=mp(s[i],i);
		p[n+1]=mp(0,0);
		sort(p+1,p+n+2);
		top1=top2=0;
		s2[++top2]=mp(0,0);
		ll ans=0;
		for(int i=1;i<=n;i++){
			ll mx=1;
			if(i&1){
				int pl=lower_bound(s2+1,s2+top2+1,mp(-s[i],0ll))-s2-1;
				if(pl) chkmax(mx,s2[pl].se+2);
				pl=lower_bound(s1+1,s1+top1+1,mp(s[i],0ll))-s1-1;
				if(pl) chkmax(mx,s1[pl].se+2);
				while(top1&&s1[top1].fi>=s[i]) top1--;
				s1[++top1]=mp(s[i],i);
			}
			else{
				int pl=lower_bound(s1+1,s1+top1+1,mp(s[i],0ll))-s1-1;
				if(pl) chkmax(mx,s1[pl].se+2);
				pl=lower_bound(s2+1,s2+top2+1,mp(-s[i],0ll))-s2-1;
				if(pl) chkmax(mx,s2[pl].se+2);
				while(top2&&s2[top2].fi>=-s[i]) top2--;
				s2[++top2]=mp(-s[i],i);
			}
			int pl1=lower_bound(p+1,p+n+2,mp(s[i],mx-1))-p;
			int pl2=lower_bound(p+1,p+n+2,mp(s[i],(ll)i))-p;
//			cout<<"test "<<i<<' '<<mx<<' '<<pl1<<' '<<pl2<<endl;
			ans+=pl2-pl1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}