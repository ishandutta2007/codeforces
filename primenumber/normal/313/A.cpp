#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <numeric>
#include <utility>

#define rep(i,n)	for(int i = 0;i < n;i++)
#define rep2(i,n)	for(int i = 1;i <= n;i++)
#define each(i,x)	for(auto & i : x)

using namespace std;

int main()
{
	int n;
	cin >> n;
	/*string str,str2,str3;
	cin >> str;
	str2 = string(str);
	str2[str2.size()-1] = ' ';
	str3 = string(str);
	str2[str2.size()-2] = str2[str2.size()-1];
	str2[str2.size()-1] = ' ';
	stringstream ss,ss2,ss3;
	ss << str;
	ss2 << str2;
	ss3 << str3;*/
	int a,b,c;
	a = n;b = n/10;c = (n/100)*10+(n%10);
	if(a > b)
	{
		if(a > c)
		{
			cout << a << endl;
		}
		else
		{
			cout << c << endl;
		}
	}
	else if(b > c)
	{
		cout << b << endl;
	}
	else
	{
		cout << c << endl;
	}
	return 0;
}