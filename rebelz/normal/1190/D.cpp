#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot;
pair<ll,ll> a[200005];
unordered_map<ll,int> b;
ll p[200005],pp[200005],c[200005];

int lowbit(int x){return x&(-x);}
void add(int x,int g){for(;x<=n;x+=lowbit(x))c[x]+=g;}
ll ask(int x){ll ret=0;for(;x;x-=lowbit(x))ret+=c[x];return ret;}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i].se=readint(),a[i].fi=readint();
	for(int i=1;i<=n;i++) pp[i]=a[i].se;
	sort(pp+1,pp+n+1);
	for(int i=1;i<=n;i++) a[i].se=lower_bound(pp+1,pp+n+1,a[i].se)-pp;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) p[i]=a[i].fi;
	ll now=1,cnt=0;
	for(int i=1;i<=n;i++){
		if(b[a[i].se]==0) cnt++,add(a[i].se,1);
		b[a[i].se]++;
	}
	tot=unique(p+1,p+n+1)-p-1;
	ll ans=1ll*cnt*(cnt+1)/2,lst;
	for(int i=1;i<=tot;i++){
		lst=0;
		while(now<=n&&a[now].fi<=p[i]){
			b[a[now].se]--;
			ll tmp=ask(a[now].se-1)-ask(lst);
			if(tmp>0) ans-=tmp*(tmp+1)/2;
//			cout<<"now "<<now<<' '<<p[i]<<' '<<a[now].fi<<' '<<b[a[now].se]<<endl;
			if(b[a[now].se]==0) cnt--,add(a[now].se,-1);
			lst=a[now].se;
			now++;
		}
//		cout<<"TEST "<<p[i]<<' '<<cnt<<endl;
		ll tmp=ask(n)-ask(lst);
		if(tmp>0) ans-=tmp*(tmp+1)/2;
		ans+=cnt*(cnt+1)/2;
	}
	cout<<ans<<endl;
	return 0;
}