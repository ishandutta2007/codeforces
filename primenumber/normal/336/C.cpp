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

#define rep(i,n)	for(int i = 0;i < (n);i++)
#define rep2(i,n)	for(int i = 1;i <= (n);i++)
#define each(i,x)	for(auto & i : x)

using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<unsigned int> ary(n);
	rep(i,n)cin>>ary[i];
	vector<unsigned int> ands(31,0xFFFFFFFF);
	unsigned int j = 1;
	rep(i,n)
	{
		for(;j<=30;j++)
		{
			if(ary[i] < (1 << j))
				break;
		}
		ands[j] &= ary[i];
		for(unsigned int k = 1;k < j;k++)
		{
			if((1 << (k-1)) & ary[i])
			{
				ands[k] &= ary[i];
			}
		}
	}
	//rep2(i,30)
	//	cout << ands[i] << endl;;
	int maxj = 0;
	rep2(i,30)
	{
		if(ands[i] >= (1 << (i-1)) && !(ands[i] & ((1 << (i-1))-1)))
		{
			maxj = i;
		}
	}
	if(maxj)
	{
		int cnt = 0;
		vector<unsigned int> outputs;
		rep(i,n)
		{
			if(ary[i] & (1 << (maxj-1)))
			{
				cnt++;
				outputs.push_back(ary[i]);
			}
		}
		int s = outputs.size();
		cout << s << endl;
		rep(i,s-1)
		{
			cout << outputs[i] << ' ';
		}
		cout << outputs[s-1] << endl;
	}
	else
	{
		cout << n << endl;
		rep(i,n-1)
		{
			cout << ary[i] << ' ';
		}
		cout << ary[n-1] << endl;
	}
	return 0;
}