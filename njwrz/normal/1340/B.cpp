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
string s[10]={
"1110111","0010010","1011101","1011011","0111010","1101011","1101111","1010010","1111111","1111011"
};
string a[2005];
int n,c[2005][10];
bool dp[2005][2005];
int cost(string &l,string &r){
	int re=0;
	rep(i,0,7){
		if(r[i]=='0'&&l[i]=='1')RE -1;
		re+=(l[i]=='0'&&r[i]=='1');
	}
	RE re;
}
int m;
void dfs(int p,int x){
	if(!p)RE;
	for(int i=9;i>=0;i--){
		if(c[p][i]==-1||x+c[p][i]>m)continue;
		if(dp[p-1][x+c[p][i]]){
			cout<<i;
			dfs(p-1,x+c[p][i]);
			RE;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=n;i>=1;i--)cin>>a[i];
	FOR(i,1,n)FOR(j,0,9)c[i][j]=cost(a[i],s[j]);
	dp[0][m]=1;
	FOR(i,1,n){
		FOR(j,0,m){
			if(!dp[i-1][j])continue;
			FOR(k,0,9){
				if(c[i][k]==-1||j<c[i][k])continue;
				dp[i][j-c[i][k]]|=dp[i-1][j];
			}
		}
	}
	if(!dp[n][0]){
		cout<<-1;RE 0;
	}
	dfs(n,0);
	RE 0;
}