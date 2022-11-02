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
string ans[100005];
int len[100005],top,it[100005];
char c[100005],lst[100005];
void solve(){
	if(top==1||c[top]!=c[top-1]||it[top]!=it[top-1]-1)RE;
	if(top==2||c[top]>lst[top]){
		top-=2;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;cin>>s;
	int n=s.size();lst[0]=' ';
	for(int i=n;i>=1;i--){
		c[++top]=s[i-1];it[top]=i;
		if(c[top]!=c[top-1])lst[top]=c[top-1];else lst[top]=lst[top-1];
		if(i==n)lst[top]=' ';
		solve();
		len[i]=top;
		if(top>10){
			for(int j=top;j>=top-4;j--)ans[i]+=c[j];
			ans[i]+="...";
			ans[i]+=c[2];ans[i]+=c[1]; 
		}else{
			for(int j=top;j>=1;j--)ans[i]+=c[j];
		}
	}
	FOR(i,1,n){
		cout<<len[i]<<' ';
		cout<<ans[i]<<'\n';
	}
	RE 0;
}