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
	int x,y;
	cin>>x>>y;
	if(x < 0)
	{
		if(y < 0)
		{
			cout <<x+y<<" 0 0 "<<x+y<<endl;
		}
		else
			cout <<x-y<<" 0 0 "<<y-x<<endl;
	}
	else if(y < 0)
		cout <<"0 "<<y-x<<' '<<x-y<<" 0"<<endl;
	else
		cout <<"0 "<<x+y<<' '<<x+y<<" 0"<<endl;
	return 0;
}