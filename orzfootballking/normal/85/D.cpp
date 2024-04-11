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
int n,q[100005],p[100005];
V<int> v;
const int N=1<<17;
int sum[N<<1][5],cnt[N<<1];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int x;
	cin>>n;
	FOR(i,1,n){
		cin>>s;
		if(s=="sum"){
			p[i]=2;
		}else if(s=="add"){
			cin>>x;
			p[i]=0;q[i]=x;
			v.PB(x);
		}else{
			cin>>x;
			p[i]=1;q[i]=x;
			v.PB(x);
		}
	}
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	FOR(i,1,n){
		if(p[i]!=2)q[i]=lower_bound(ALL(v),q[i])-v.begin();
	}
	FOR(i,1,n){
		if(p[i]==2){
			cout<<sum[1][2]<<'\n';
		}else{
			cnt[N+q[i]]=1^p[i];sum[N+q[i]][0]=v[q[i]]*(1^p[i]);
			for(int j=(N+q[i])>>1;j;j>>=1){
				cnt[j]=cnt[(j<<1)^1]+cnt[j<<1];
				rep(k,0,5)sum[j][k]=sum[(j<<1)^1][((k-cnt[j<<1])%5+5)%5]+sum[j<<1][k];
			}
		}
	}
	RE 0;
}