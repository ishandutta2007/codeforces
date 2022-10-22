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
	string s;
	cin>>s;
	int l = (s.size()-1)/n;
	int num = 0;
	rep2(i,l)
	{
		if(s[i*n-3]==s[i*n-2]&&s[i*n-2]==s[i*n-1])
		{
			num++;
		}
	}
	cout << num << endl;
	return 0;
}