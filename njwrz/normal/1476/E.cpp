/*

DP





ll int
 dp 










*/
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
int n,m,k;
int in[100005];
V<int> v[100005];
string s[100005];
int iter[27*27*27*27];
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>n>>m>>k;
	FOR(i,1,n){
		cin>>s[i];
		int now=0;
		rep(j,0,k){
			now=now*27;
			if(s[i][j]=='_'){
				now+=26;
			}else now+=s[i][j]-'a';
		}
		iter[now]=i;
	} 
	FOR(i,1,m){
		string x;
		cin>>x;
		int it;
		cin>>it;
		rep(j,0,k){
			if(s[it][j]!='_'&&s[it][j]!=x[j]){
				cout<<"NO";RE 0;
			}
		}
		V<int> tv;
		rep(j,0,1<<k){
			int nowv=0;
			rep(p,0,k){
				nowv*=27;
				if(j&(1<<p)){
					nowv+=26;
				}else nowv+=x[p]-'a';
			}
			if(iter[nowv]){
				tv.PB(iter[nowv]);
			}
		}
		for(auto u:tv){
			if(u!=it){
				v[it].PB(u);
				in[u]++;
			}
		}
	}
	queue<int> q;
	FOR(i,1,n){
		if(!in[i])q.emplace(i);
	}
	V<int> ans;
	while(!q.empty()){
		int cur=q.front();ans.PB(cur);q.pop()
;		for(auto u:v[cur]){
			--in[u];
			if(!in[u]){
				q.emplace(u);
			}
		}
	}
	if(ans.size()==n){
		cout<<"YES\n";
		for(auto u:ans)cout<<u<<' ';
	}else cout<<"NO";
	RE 0;
}