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
char c[1005][1005];
void solve(){
	int n,m;
	cin>>n>>m;
	FOR(i,1,n){
		FOR(j,1,n){
			cin>>c[i][j];
		}
	}
	if(m%2==1){
		cout<<"YES\n";
		FOR(i,1,m+1){
			cout<<i%2+1<<' ';
		}
		cout<<"\n";RE;
	}
	FOR(i,1,n){
		FOR(j,i+1,n){
			if(c[i][j]==c[j][i]){
				cout<<"YES\n";
				FOR(k,1,m+1){
					if(k%2==1){
						cout<<j<<' ';
					}else cout<<i<<' ';
				}
				cout<<'\n';RE;
			}
		}
	}
	FOR(i,1,n){
		int ta=0,tb=0;
		FOR(j,1,n){
			if(c[i][j]=='a'){
				ta=j;
			}else if(c[i][j]=='b'){
				tb=j;
			}
		}
		if(ta&&tb){
			if(m%4==0){
				cout<<"YES\n";
				FOR(j,1,m/2){
					if(j%2==1){
						cout<<i<<' '; 
					}else cout<<ta<<' ';
				}
				cout<<i<<' ';
				FOR(j,1,m/2){
					if(j%2==1){
						cout<<tb<<' ';
					}else cout<<i<<' ';
				}
			}else{
				cout<<"YES\n";
				FOR(j,1,m/2){
					if(j%2==1){
						cout<<ta<<' '; 
					}else cout<<i<<' ';
				}
				cout<<i<<' ';
				FOR(j,1,m/2){
					if(j%2==1){
						cout<<tb<<' ';
					}else cout<<i<<' ';
				}
			}
			cout<<'\n';RE;
		}
	}
	cout<<"NO\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}