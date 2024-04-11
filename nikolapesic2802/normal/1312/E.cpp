#include <bits/stdc++.h>

using namespace std;

const int N=501;
vector<int> a(N),dp(N);
vector<unordered_map<int,int> > x(N);
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=0;i<n;i++)
		scanf("%i",&a[i]);
	for(int i=n-1;i>=0;i--){
		x[i][a[i]]=i+1;
		int tr=i+1,xx=a[i];
		while(true){
			if(x[tr].find(xx)!=x[tr].end())
				x[i][xx+1]=x[tr][xx],tr=x[tr][xx],xx++;
			else
				break;
		}
	}
	for(int i=n-1;i>=0;i--){
		dp[i]=n-i;
		for(auto p:x[i])
			dp[i]=min(dp[i],1+dp[p.second]);
	}
	printf("%i\n",dp[0]);
	return 0;
}