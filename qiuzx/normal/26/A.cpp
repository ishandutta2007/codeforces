#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
bool prime(int x)
{
	int i;
	for(i=2;i<x;i++)
	{
		if(x%i==0)
		{
			return false;
		}
	}
	return true;
}
bool check(int x)
{
	int i,num=0;
	for(i=2;i*i<x;i++)
	{
		if(x%i)
		{
			continue;
		}
		if(prime(i))
		{
			num++;
		}
		if(prime(x/i))
		{
			num++;
		}
		if(num>2)
		{
			return false;
		}
	}
	if(num==2)
		return true;
	return false;
}
int main(){
	int n,ans=0,i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		if(check(i))
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}