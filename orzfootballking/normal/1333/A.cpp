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
int n,m,a[105][105];
void solve(){
	cin>>n>>m;
	bool f=0;FILL(a,0);
	if((n&1)&&(m&1)){
		FOR(i,1,n){
			FOR(j,1,m)a[i][j]=f,f=1-f;
		}
	}else if((n&1)&&!(m&1)){
		FOR(i,1,m){
			FOR(j,1,n)a[j][i]=(i+j)&1;
		}
		a[n][m]=0;
	}else if(!(n&1)&&(m&1)){
		FOR(i,1,n){
			FOR(j,1,m)a[i][j]=(i+j)&1;
		}
		a[n][m]=0;
	}else{
		FOR(i,1,n){
			FOR(j,1,m)a[i][j]=(i+j)&1;
		}
		a[1][m]=0;
	}
	FOR(i,1,n){
		FOR(j,1,m)if(a[i][j])cout<<"W";else cout<<"B";
		cout<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}