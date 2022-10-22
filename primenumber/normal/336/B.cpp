#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <ctime>

#define rep(i,n)	for(long long i = 0;i < (n);i++)
#define rep2(i,n)	for(long long i = 1;i <= (n);i++)
#define each(i,x)	for(auto & i : x)

using namespace std;

int main()
{
	long long m,r;
	cin>>m>>r;
	double sum = 0.0;
	cout.precision(10);
	if(m < 100)
	{
		for(long long i = 0;i < m*m;i++)
		{
			long long v = i/m+1;
			long long u = m+1+i%m;
			if(u-v==m)
			{
				sum += 2.0*r;
			}
			else if(abs(u-v-m)<= 1)
			{
				sum += (2.0+sqrt(2.0))*r;
			}
			else
			{
				sum += 2.0*sqrt(2.0)*r;
				sum += (abs(u-v-m)-1.0)*2.0*r;
			}
		}
	}
	else
	{
		for(long long i = 1;i < m-1;i++)
		{
			long long dist = i*(i-1)/2 + (m-2-i)*(m-1-i)/2;
			sum += (m-3)*2.0*sqrt(2.0)*r;
			sum += dist*2.0*r;
			sum += 2.0*(2.0+sqrt(2.0))*r;
			sum += 2.0*r;
		}
		for(long long i = 0;i < m;i++)
		{
			long long v = 1;
			long long u = m+1+i%m;
			if(u-v==m)
			{
				sum += 2.0*2.0*r;
			}
			else if(abs(u-v-m)<= 1)
			{
				sum += 2.0*(2.0+sqrt(2.0))*r;
			}
			else
			{
				sum += 2.0*2.0*sqrt(2.0)*r;
				sum += 2.0*(abs(u-v-m)-1.0)*2.0*r;
			}
		}
	}
	cout << sum/(m*m) << endl;
	return 0;
}