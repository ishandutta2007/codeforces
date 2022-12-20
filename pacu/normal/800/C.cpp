#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
bool good[200005];
int num[200005];
int dp[200005];
int nxt[200005];
vector<int> lst[200005];
vector<int> prod;
int phi;

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int mexp(int a,int e)
{
	if(e==0) return 1;
	int tmp = mexp(a,e/2);
	tmp = (tmp*((long long)tmp))%M;
	if(e%2) tmp = (tmp*((long long)a))%M;
	return tmp;
}

int inv(int a)
{
	return mexp(a,phi-1);
}

int getMult(int a,int b)
{
	int g = gcd(a,b);
	a /= g;
	b /= g;
	return (b*((long long)inv(a)))%M;
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> N >> M;
	int a;
	for(int i=0;i<M;i++)
	{
		good[i] = 1;
		if(gcd(i,M)==1) phi++;
	}
	for(int i=0;i<N;i++)
	{
		cin >> a;
		good[a] = 0;
	}
	for(int i=0;i<M;i++)
		if(good[i])
		{
			int g = gcd(i,M);
			num[g]++;
			lst[g].push_back(i);
		}
	for(int i=M;i>0;i--)
	{
		nxt[i] = -1;
		for(int j=2*i;j<=M;j+=i)
		{
			if(dp[j] > dp[i])
			{
				nxt[i] = j;
				dp[i] = dp[j];
			}
		}
		dp[i] += num[i];
	}
	cout << dp[1] << '\n';
	int cur = 1;
	while(cur != -1)
	{
		for(int j=0;j<lst[cur].size();j++)
			prod.push_back(lst[cur][j]);
		cur = nxt[cur];
	}
	cout << prod[0];
	for(int i=1;i<dp[1];i++)
		cout << ' ' << getMult(prod[i-1],prod[i]);
	cout << '\n';
}