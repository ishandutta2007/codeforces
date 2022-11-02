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
char c[305][305];
void solve(){
	int n;
	cin>>n;
	int cnt[3]={};
	FOR(i,1,n){
		FOR(j,1,n){
			cin>>c[i][j];
			if(c[i][j]!='.')cnt[(i+j)%3]++;
		}
	}
	if(cnt[0]<=cnt[1]&&cnt[0]<=cnt[2]){
		FOR(i,1,n){
			FOR(j,1,n){
				if((i+j)%3==0){
					if(c[i][j]=='.'){
						cout<<'.';
					}else cout<<'O';
				}else {
					if(c[i][j]=='.'){
						cout<<'.';
					}else cout<<'X';
				}
			}
			cout<<'\n';
		}
	}else if(cnt[1]<=cnt[0]&&cnt[1]<=cnt[2]){
		FOR(i,1,n){
			FOR(j,1,n){
				if((i+j)%3==1){
					if(c[i][j]=='.'){
						cout<<'.';
					}else cout<<'O';
				}else {
					if(c[i][j]=='.'){
						cout<<'.';
					}else cout<<'X';
				}
			}
			cout<<'\n';
		}
	}else{
		FOR(i,1,n){
			FOR(j,1,n){
				if((i+j)%3==2){
					if(c[i][j]=='.'){
						cout<<'.';
					}else cout<<'O';
				}else {
					if(c[i][j]=='.'){
						cout<<'.';
					}else cout<<'X';
				}
			}
			cout<<'\n';
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}