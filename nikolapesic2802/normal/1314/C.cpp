#include <bits/stdc++.h>

#define ll long long

using namespace std;

const int N=1e3+2;
const ll oo=2e18;
int n,m;
ll k;
string s;
vector<string> substrs;
vector<int> l(N);
void initNxt(int t){
	string my=substrs[t];
	for(int i=0;i<n;i++){
		l[i]=N-1;
		bool isto=true;
		for(int j=i;j<n;j++){
			int d=j-i;
			if(isto&&my[d]>s[j])
				break;
			if(isto&&(my[d]<s[j]||d==(int)my.size()-1))
				isto=0;
			if(!isto){
				l[i]=j+1;
				break;
			}
		}
	}
}
ll add(ll a,ll b){
	a+=b;
	if(a>=oo)
		a=oo;
	return a;
}
ll dp[N][N];
ll doDp(){
	memset(dp,0,sizeof dp);
	dp[n][0]=1;
	for(int j=1;j<=m;j++){
		for(int i=n-1;i>=0;i--)
			dp[i][j-1]=add(dp[i][j-1],dp[i+1][j-1]);
		for(int i=0;i<n;i++)
			dp[i][j]=dp[l[i]][j-1];
	}
	return dp[0][m];
}
int main()
{
	cin >> n >> m >> k >> s;
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
			substrs.push_back(s.substr(i,j-i+1));
	sort(substrs.begin(),substrs.end());
	int l=0,r=substrs.size()-1;
	while(l<r){
		int m=(l+r+1)>>1;
		initNxt(m);
		if(doDp()>=k)
			l=m;
		else
			r=m-1;
	}
	cout << substrs[l] << endl;
	return 0;
}