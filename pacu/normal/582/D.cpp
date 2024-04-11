#include <iostream>
#include <string>
using namespace std;
#define MOD 1000000007

string A;
int cur,nxt;

long long P,alpha;

int bound[3500];

int div()
{
	long long sm = 0;
	for(int i=0;i<A.size();i++)
	{
		sm = 10*sm + (A[i]-'0');
		A[i] = (char)(sm/P + '0');
		sm %= P;
	}
	return sm;
}

long long dp[3500][2];
long long dpCarry[3500][2];
long long tot[3500][2];
long long totCarry[3500][2];

long long ways(long long b) 		//ways for two digits to sum to at most bound
{
	if(b < P)
		return (((b+1)*(b+2))/2)%MOD;
	else if(b > P)
		return (P*P-(((2*P-3-b+1)*(2*P-3-b+2))/2))%MOD;
	else
		return (P-1+((P)*(P+1))/2)%MOD;
}

long long wayseq(long long b)		//ways to sum to exactly bound
{
	if(b<P) return b+1;
	else return 2*P-1-b;
}

int main()
{
	cin >> P >> alpha >> A;
	if(alpha >= 3500)
	{
		cout << 0 << '\n';
		return 0;
	}
	for(int i=0;i<3500;i++)
	{
		bound[i] = div();
	}
	long long ans = 0;
	int cur = 0;
	int nxt = 1;
	for(int c=0;c<3500;c++,swap(cur,nxt))
	{
		if(c==0)
			dp[0][nxt] = ways(bound[0]);
		else
			dp[0][nxt] = 0;
		if(c==1)
			dpCarry[0][nxt] = (MOD+ways(bound[0]+P)-ways(P-1))%MOD;
		else
			dpCarry[0][nxt] = 0;
		if(c==0)
			tot[0][nxt] = ways(P-1);
		else
			tot[0][nxt] = 0;
		if(c==1)
			totCarry[0][nxt] = (MOD+ways(2*P-2)-ways(P-1))%MOD;
		else
			totCarry[0][nxt] = 0;
		for(int i=1;i<3500;i++)
		{
			dp[i][nxt] = wayseq(bound[i])*dp[i-1][nxt];
			if(bound[i]>0)
			{
				dp[i][nxt] += ways(bound[i]-1)*tot[i-1][nxt];
				dp[i][nxt] += wayseq(bound[i]-1)*dpCarry[i-1][nxt];
				if(bound[i]>1)
					dp[i][nxt] += ways(bound[i]-2)*totCarry[i-1][nxt];
			}
			dp[i][nxt] %= MOD;
			
			dpCarry[i][nxt] = wayseq(bound[i]+P)*dp[i-1][cur];
			if(bound[i]>0)
				dpCarry[i][nxt] += ((MOD+ways(bound[i]-1+P)-ways(P-1))*tot[i-1][cur])%MOD;
			dpCarry[i][nxt] += wayseq(bound[i]-1+P)*dpCarry[i-1][cur];
			if(bound[i]>0)
				dpCarry[i][nxt] += ((MOD+ways(bound[i]-2+P)-ways(P-2))*totCarry[i-1][cur])%MOD;
			dpCarry[i][nxt] %= MOD;
			
			tot[i][nxt] = (ways(P-1)*tot[i-1][nxt] + ways(P-2)*totCarry[i-1][nxt])%MOD;
			
			totCarry[i][nxt] = ((MOD+ways(2*P-2)-ways(P-1))*tot[i-1][cur] + (MOD+ways(2*P-2)-ways(P-2))*totCarry[i-1][cur])%MOD;
			//totCarry[i][nxt] = (totCarry[i][nxt]%MOD + MOD - tot[i][cur])%MOD;
		}
		if(c >= alpha)
		{
			ans = (ans+dp[3499][nxt])%MOD;
			//if(c <= 10)
				//cout << dp[3499][nxt] << '\n';
		}
	}
	cout << ans << '\n';
}