/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
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
int cnt[1505],a[1505][1505],b[1505][1505],tap;P<int,int> iter[1505];
bool used[1505];
bool cmp(P<int,int> x,P<int,int> y){
	RE MP(a[x.F][tap],x.S)<MP(a[y.F][tap],y.S);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	FOR(i,1,n){
		FOR(j,1,m)cin>>a[i][j]; 
	}
	FOR(i,1,n){
		FOR(j,1,m){
			cin>>b[i][j];
			if(i>1&&b[i][j]<b[i-1][j]){
				cnt[j]++;
			}
		}
	}
	V<int> v;
	FOR(i,1,m){
		if(!cnt[i])v.PB(i);
	}
	int it=0;
	while(it<v.size()){
		int t=v[it];it++;
		FOR(i,2,n){
			if(used[i])continue;
			if(b[i][t]>b[i-1][t]){
				used[i]=1;
				FOR(j,1,m){
					if(b[i][j]<b[i-1][j]){
						if(--cnt[j]==0){
							v.PB(j);
						}
					}
				}
			}
		}
	}
	reverse(ALL(v)); 
	FOR(i,1,n){
		iter[i].F=i;
	}
	for(auto u:v){
		tap=u;
		FOR(i,1,n)iter[i].S=i;
		sort(iter+1,iter+n+1,cmp);
	}
	FOR(i,1,n){
		FOR(j,1,m){
			if(a[iter[i].F][j]!=b[i][j]){
				cout<<-1;RE 0;
			}
		}
	}
	cout<<v.size()<<'\n';
	for(auto u:v)cout<<u<<' ';
	RE 0;
}