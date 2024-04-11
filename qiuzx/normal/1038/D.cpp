#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <utility>
#include <functional>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main(){
	long long n,i,x,ans,ans2;
	vector<long long> a,p,up;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>x;
		a.push_back(x);
	}
	if(n==1)
	{
		cout<<x<<endl;
		return 0;
	}
	sort(a.begin(),a.end());
	if(a[0]>=0)
	{
		ans=a[0];
		for(i=1;i<n-1;i++)
		{
			ans-=a[i];
		}
		cout<<a[n-1]-ans<<endl;
	}
	else if(a[n-1]<=0)
	{
		ans=a[n-1];
		for(i=1;i<n-1;i++)
		{
			ans-=a[i];
		}
		cout<<ans-a[0]<<endl;
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(a[i]>=0)
			{
				p.push_back(a[i]);
			}
			else
			{
				up.push_back(a[i]);
			}
		}
		ans=p[0];
		ans2=up[0];
		for(i=1;i<up.size();i++)
		{
			ans-=up[i];
		}
		for(i=1;i<p.size();i++)
		{
			ans2-=p[i];
		}
		cout<<ans-ans2<<endl;
	}
	return 0;
}