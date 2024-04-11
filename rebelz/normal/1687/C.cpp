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
ll a[200005],s[200005],du[200005],q[200005],f[200005];
vector<int> adj[200005];
pii b[200005];

int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

void solve(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) a[i]-=readint();
//	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
//	cout<<endl;
	for(int i=1;i<=m;i++) b[i].fi=readint()-1,b[i].se=readint();
	vector<int> vec(1,0);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		if(s[i]==0) vec.pb(i);
	}
	if(s[n]!=0) return (void)(printf("No\n"));
	for(int i=1;i<=vec.size();i++) adj[i].clear();
	for(int i=1;i<=m;i++) du[i]=0;
	for(int i=1;i<=m;i++){
		int pl=lower_bound(vec.begin(),vec.end(),b[i].fi)-vec.begin();
		if(vec[pl]!=b[i].fi) adj[pl].pb(i),du[i]++;
		pl=lower_bound(vec.begin(),vec.end(),b[i].se)-vec.begin();
		if(vec[pl]!=b[i].se) adj[pl].pb(i),du[i]++;
	}
	int front=0,rear=0;
	for(int i=1;i<=m;i++) if(!du[i]) q[rear++]=i;
	for(int i=1;i<=vec.size();i++) f[i]=i;
	for(int i=1;i<vec.size();i++) if(vec[i-1]+1==vec[i]) f[i]=i+1;
	while(front<rear){
		int t=q[front++];
//		cout<<"test "<<t<<endl;
		int pl1=upper_bound(vec.begin(),vec.end(),b[t].fi)-vec.begin();
		int pl2=lower_bound(vec.begin(),vec.end(),b[t].se)-vec.begin();
		for(int x=getf(pl1);x<=pl2;x=getf(x+1)){
			for(auto v:adj[x]) if(!(--du[v])) q[rear++]=v;
			f[x]=x+1;
		}
	}
	if(getf(1)==vec.size()) printf("Yes\n");
	else printf("No\n");
}

int main(){
	int T=readint();
	while(T--) solve();
	return 0;
}