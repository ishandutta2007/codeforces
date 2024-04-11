#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int f[3005],finv[3005],inv[3005];
int p[100],mod=998244353,a[100],cnt;
map<int,V<int> > m;
V<int> v;
void dfs(int now,int s){
	if(now==cnt+1){
		m[s]=v;RE ;
	}
	FOR(i,0,p[now]){
		v.PB(i);
		dfs(now+1,s);
		v.pop_back();
		s=s*a[now];
	}
}
int solve(int x){
	V<int> tv=m[x];
	int sum=0;
	FOR(i,1,cnt)sum+=tv[i];
	int re=f[sum];
	FOR(i,1,cnt)re=re*finv[tv[i]]%mod;
	RE re; 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,x,y,t;
	cin>>n;
	t=n;
	for(int i=2;i*i<=n;i++){
		if(t%i==0){
			cnt++;a[cnt]=i;
			while(t%i==0){
				p[cnt]++;
				t/=i;
			}
		}
	}
	if(t>1){
		cnt++;a[cnt]=t;
		p[cnt]=1;
	}
	finv[0]=1;finv[1]=1;inv[1]=1;
	f[0]=1;f[1]=1;
	FOR(i,2,3000){
		f[i]=f[i-1]*i%mod;
		inv[i]=mod-inv[mod%i]*(mod/i)%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	v.PB(0);
	dfs(1,1);
	int q;
	cin>>q;
	FOR(i,1,q){
		cin>>x>>y;
		t=__gcd(x,y);
		x=x/t;y=y/t;
		cout<<solve(x)*solve(y)%mod<<'\n';
	}
	RE 0;
}