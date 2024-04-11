#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[100005][3],a[100005],n;
string s[100005],t,c;
int main(){
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i];
	for(ll j=1;j<=n;j++)cin>>s[j];
	s[0]="A";
	for(ll i=1;i<=n;i++){
		string t=s[i-1],c=s[i];
		dp[i][1]=100000000000000000;
		dp[i][2]=100000000000000000;
		if(c>=t){
			dp[i][1]=dp[i-1][1];
		}
		reverse(t.begin(),t.end());
		if(c>=t){
			dp[i][1]=min(dp[i][1],dp[i-1][2]);
		}
		reverse(c.begin(),c.end());
		if(c>=t){
			dp[i][2]=dp[i-1][2]+a[i];
		}
		reverse(t.begin(),t.end());
		if(c>=t){
			dp[i][2]=min(dp[i][2],dp[i-1][1]+a[i]);
		}
		if(dp[n][1]>=100000000000000000&&
			dp[n][2]>=100000000000000000){
			cout<<-1;return 0;
		}
	}
	if(dp[n][1]>=100000000000000000&&
		dp[n][2]>=100000000000000000){
		cout<<-1;return 0;
	}
	cout<<min(dp[n][1],dp[n][2]);
	return 0;
}