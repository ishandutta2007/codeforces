#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define INF (1LL<<60)
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

string s[100005];
string t[100005];
int c[100005];
ll dp[100005][2];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	fore(i,0,n)cin>>c[i];
	fore(i,0,n){
		cin>>s[i];
		t[i]=s[i];
		reverse(t[i].begin(),t[i].end());
	}
	dp[n][0]=dp[n][1]=0;
	for(int i=n-1;i>0;--i){
		for(int j=0;j<2;++j){
			string w;
			if(j)w=t[i-1];
			else w=s[i-1];
			dp[i][j]=INF;
			if(s[i]>=w)dp[i][j]=min(dp[i][j],dp[i+1][0]);
			if(t[i]>=w)dp[i][j]=min(dp[i][j],c[i]+dp[i+1][1]);
		}
	}
	ll r=min(dp[1][0],c[0]+dp[1][1]);
	if(r>=INF)cout<<-1<<endl;
	else cout<<r<<endl;
	return 0;
}