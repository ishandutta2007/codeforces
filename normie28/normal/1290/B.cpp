#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ios ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
int n,m,k,i,j,dp[100][200010],t,t1,maxx,l,r;
string s;
vector<int> all;
deque<int> st;
int main() {
	ios;
	cin>>s;
	n=s.length();
	for (j=0;j<26;j++)
	{
		dp[j][0]=0;
	}
	for (i=0;i<n;i++)
	{
	for (j=0;j<26;j++)
	{
		dp[j][i+1]=dp[j][i];
		char c=(j+97);
		if (s[i]==c) dp[j][i+1]++;
//		cout<<dp[j][i+1]<<' ';
	}
//	cout<<endl;
}
	cin>>t;
	for (t1=0;t1<t;t1++)
	{
		cin>>l>>r;
		if (l==r) cout<<"Yes";
		else 
		{
			int cnt=0;
			for (j=0;j<26;j++) if (dp[j][r]>dp[j][l-1]) cnt++;
			if (cnt==1) cout<<"No";
			else if ((cnt==2)and(s[l-1]==s[r-1])) cout<<"No";
			else cout<<"Yes";
		}
	cout<<endl;
	}
}