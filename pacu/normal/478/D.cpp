#include <iostream>
using namespace std;
long long dp[200001];
int main()
{
	int R,G;
	cin >> R >> G;
	int H = (-1+pow(1+8*(R+G),0.5))/2;
	dp[0] = 1;
	for(int i=1;i<=R;i++)
		dp[i] = 0;
	for(int h=1;h<=H;h++)
	{
		for(int i=R;i>0;i--)
		{
			if(i>=h)
			{
				dp[i] += dp[i-h];
				dp[i] %= 1000000007;
			}
		}
	}
	long long sm = 0;
	for(int i=0;i<=R;i++)
	{
		if(((H*(H+1)/2)-i)<=G)
			sm += dp[i];
		sm %= 1000000007;
	}
	cout << sm << endl;
}