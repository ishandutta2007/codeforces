#include <iostream>
#include <iomanip>
using namespace std;

long double dp[101][101][101];

long double prob(int a,int b,int c)
{
	return ((long double)(a*b))/((long double)(a*b+a*c+b*c));
}

long double test(int R,int S,int P)
{
	for(int i=0;i<=R;i++)
		for(int j=0;j<=S;j++)
			for(int k=0;k<=P;k++)
			{
				if((i>0)&&(j==0)&&(k==0)) dp[i][j][k] = 1;
				if(i==0) dp[i][j][k] = 0;
			}
	for(int i=0;i<=R;i++)
		for(int j=0;j<=S;j++)
			for(int k=0;k<=P;k++)
			{
				if((i>0)&&(j==0)&&(k==0)) {dp[i][j][k] = 1;continue;}
				else if(i==0) {dp[i][j][k] = 0;continue;}
				else dp[i][j][k] = 0;
				if((i>0)&&(j>0)) dp[i][j][k] += prob(i,j,k)*dp[i][j-1][k];
				if((i>0)&&(k>0)) dp[i][j][k] += prob(i,k,j)*dp[i-1][j][k];
				if((j>0)&&(k>0)) dp[i][j][k] += prob(j,k,i)*dp[i][j][k-1];
			}
	return dp[R][S][P];
}

int main()
{
	int R,S,P;
	cin >> R >> S >> P;
	cout << setprecision(20) << test(R,S,P) << " " << test(S,P,R) << " " << test(P,R,S) << endl;
	return 0;
}