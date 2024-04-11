#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
int mob[60];
long long ppw[1002][60];

long long pw(long long a, long long p)
{
	if(p==0) return 1;
	long long tmp = pw(a,p/2);
	if(tmp > 1000000000) return 1000000000000000001LL;
	tmp = tmp*tmp;
	if(p%2)
	{
		if(tmp > 1e18/((double)a)) return 1000000000000000001LL;
		tmp = tmp*a;
	}
	return tmp;
}

long long getroot(long long a, long long p)
{
	if(p >= 6)
	{
		int low = 1;
		int high = 1001;
		while(low != high)
		{
			int mid = (low+high)/2;
			if(ppw[mid][p] <= a)
				low = mid+1;
			else
				high = mid;
		}
		//cout << a << ' ' << p << ": " << low << '\n';
		return low;
	}
	double k = (double)pow((double)a, 1.0/p);
	long long ans = floor(k);
	//cout << a << ' ' << p << ": " << ans << '\n';
	while(pw(ans,p) <= a)
		ans++;
	//cout << a << ' ' << p << ": " << ans << '\n';
	return ans;
}

long long answerQuery(long long a)
{
	if(a==0) return 0;
	long long ans = 0;
	for(int i=2;i<=59;i++)
	{
		if(mob[i] != 0)
			ans += -mob[i]*(getroot(a, i) - 2);
		//cout << i << ": " << ans << '\n';
	}	
	return ans+1;
}

int main()
{
	for(int i=1;i<60;i++)
	{
		mob[i] = 1;
		int v = i;
		for(int j=0;j<17;j++)
		{
			if(v%(prime[j]*prime[j]) == 0)
				mob[i] = 0;
			else if(v%prime[j] == 0)
				mob[i] *= -1;
		}
	}
	for(int i=1;i<=1001;i++)
		for(int j=1;j<60;j++)
			ppw[i][j] = pw(i,j);
//cout << mob[2] << ' ' << mob[3] << ' ' << mob[6] << '\n';
	int Q;
	long long a,b;
	cin >> Q;
	for(int i=0;i<Q;i++)
	{
		cin >> a >> b;
		cout << answerQuery(b) - answerQuery(a-1) << '\n';
	}
}