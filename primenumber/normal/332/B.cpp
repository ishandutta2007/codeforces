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

#define fr(i,k,n)	for(int i = (k);i < (n);i++)
#define rep(i,n)	for(int i = 0;i < (n);i++)
#define rep2(i,n)	for(int i = 1;i <= (n);i++)
#define each(i,x)	for(auto & i : x)

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> x(n);
	vector<long long> s(n-k+1,0);
	rep(i,n)cin>>x[i];
	rep(i,k)s[0]+=x[i];
	rep2(i,n-k)s[i]=s[i-1]+x[i+k-1]-x[i-1];
	long long m=-k;
	int ma=0,mb=0;
	int mma=0;
	for(int i=0;i<=n-2*k;i++)
	{
		if(m<max(s[mma],s[i])+s[i+k])
		{
			m=max(s[mma],s[i])+s[i+k];
			mb=i+k;
			if(s[mma]<s[i])
			{
				ma=i;
			}
			else
			{
				ma=mma;
			}
		}
		if(s[mma]<s[i])
		{
			mma=i;
		}
	}
	cout<<ma+1<<' '<<mb+1<<endl;
	return 0;
}