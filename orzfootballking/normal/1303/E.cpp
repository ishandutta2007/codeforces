#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
string a,b;
int nxt[405][30],dp[405][405],maxi=1e9;
bool check(int x){
	int la=x,lb=b.size()-x;
	FOR(i,0,la)FOR(j,0,lb)dp[i][j]=maxi;
	dp[0][0]=-1;
	FOR(i,0,la){
		FOR(j,0,lb){
			if(!i&&!j)continue;
			if(i&&dp[i-1][j]<maxi)dp[i][j]=min(dp[i][j],nxt[dp[i-1][j]+1][b[i-1]-'a']);
			if(j&&dp[i][j-1]<maxi)dp[i][j]=min(dp[i][j],nxt[dp[i][j-1]+1][b[la+j-1]-'a']);
		}
	}
	RE (dp[la][lb]<a.size());
}
void solve(){
	cin>>a>>b;
	rep(i,0,26){
		nxt[a.size()][i]=maxi;
		for(int j=a.size()-1;j>=0;j--){
			if(a[j]==i+'a'){
				nxt[j][i]=j;
			}else nxt[j][i]=nxt[j+1][i];
		}
	}
	FOR(i,0,b.size()){
		if(check(i)){
			cout<<"YES\n";RE ;
		}
	}
	cout<<"NO\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}