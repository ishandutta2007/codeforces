// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
int p[200005],a[200005],maxa[200005],mx[200005],now[200005],pre[200005];
pii b[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) p[i]=a[i]=readint();
		for(int i=1;i<=m;i++) b[i].fi=readint(),b[i].se=readint();
		sort(p+1,p+n+1);
		for(int i=1;i<=n;i++) a[i]=lower_bound(p+1,p+n+1,a[i])-p;
		sort(b+1,b+m+1);
		for(int i=1;i<=n;i++) maxa[i]=mx[i]=0;
		for(int i=1;i<=m;i++) maxa[b[i].fi]=b[i].se;
		for(int i=1;i<=n;i++) chkmax(maxa[i],maxa[i-1]);
		for(int i=1;i<=n;i++) now[i]=0;
		for(int i=1;i<=n;i++){
			pre[i]=now[a[i]];
			now[a[i]]=i;
		}
		int L=n,R=0;
		for(int i=1;i<=n;i++){
			if(pre[pre[i]]){
				if(maxa[pre[pre[i]]]>=i){
					chkmin(L,pre[i]);
					chkmax(R,pre[i]);
				}
			}
		}
//		cout<<"test "<<L<<' '<<R<<endl;
		for(int i=1;i<=n;i++){
			if(pre[i]&&maxa[pre[i]]>=i){
				int u=i;
				while(pre[u]&&maxa[pre[u]]>=i) u=pre[u];
//				cout<<"?? "<<u<<' '<<i<<endl;
				chkmax(mx[1],u);
				chkmax(mx[u+1],i);
				chkmax(mx[i+1],1<<30);
			}
		}
		int tmp=R,ans=n+1;
		for(int i=1;i<=L;i++){
			chkmax(tmp,mx[i]);
			chkmax(tmp,i-1);
//			cout<<"tmp "<<i<<' '<<tmp<<' '<<ans<<endl;
			chkmin(ans,tmp-i+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}