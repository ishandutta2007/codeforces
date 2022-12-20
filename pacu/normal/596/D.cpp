#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

double dp[2000][2000][2][2];

int N;
int x[2000];
int rReach[2000],lReach[2000];
int H;
double p;

int ldist(int i,int a)
{
	if(i==0) return 1000000000;
	if(a==0)
		return x[i]-x[i-1];
	else
		return x[i]-(x[i-1]+H);
}
int rdist(int i,int b)
{
	if(i==N-1) return 1000000000;
	if(b==1)
		return x[i+1]-x[i];
	else
		return (x[i+1]-H)-x[i];
}


int main()
{
	cin >> N >> H >> p;
	for(int i=0;i<N;i++)
		cin >> x[i];
	sort(x,x+N);
	lReach[0] = 0;
	for(int i=1;i<N;i++)
	{
		if(x[i]-x[i-1] >= H)
			lReach[i] = i;
		else
			lReach[i] = lReach[i-1];
	}
	rReach[N-1] = N-1;
	for(int i=N-2;i>=0;i--)
	{
		if(x[i+1]-x[i] >= H)
			rReach[i] = i;
		else
			rReach[i] = rReach[i+1];
	}
	for(int i=N-1;i>=0;i--)
	{
		for(int a=0;a<2;a++) for(int b=0;b<2;b++)
			dp[i][i][a][b] = p*min(H,ldist(i,a))+(1-p)*min(H,rdist(i,b));
		//cout << i << ' ' << i << ' ' << dp[i][i] << '\n';
		for(int j=i+1;j<N;j++)
		{
			for(int a=0;a<2;a++) for(int b=0;b<2;b++)
			{
				dp[i][j][a][b] = 0.5*p*(min(H,ldist(i,a))+dp[i+1][j][0][b]);
				if(rReach[i] < j)
					dp[i][j][a][b] += 0.5*(1-p)*(x[rReach[i]]+H-x[i]+dp[rReach[i]+1][j][1][b]);
				else
					dp[i][j][a][b] += 0.5*(1-p)*(min(H,rdist(j,b))+x[j]-x[i]);
				dp[i][j][a][b] += 0.5*(1-p)*(min(H,rdist(j,b))+dp[i][j-1][a][1]);
				if(i < lReach[j])
					dp[i][j][a][b] += 0.5*p*(x[j]+H-x[lReach[j]]+dp[i][lReach[j]-1][a][0]);
				else
					dp[i][j][a][b] += 0.5*p*(min(H,ldist(i,a))+x[j]-x[i]);
			}
		}
	}
	cout << fixed << setprecision(20) << dp[0][N-1][0][1] << '\n';
}