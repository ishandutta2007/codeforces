#include <iostream>
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
	int n,m;
	cin>>n>>m;
	if(n == 3)
	{
		cout << ">.v\n...\n..<\n1 1"<<endl;
	}
	else if(n == 5)
	{
		cout << ".....\n>>.vv\n.....\n^..<<\n.....\n2 2"<<endl;
	}
	else
	{
		rep(i,33)
			cout<<'>';
		rep(i,33)
			cout<<".>";
		cout<<'v'<<endl;
		rep(i,49)
		{
			cout<<"^v";
			rep(j,32)
				cout<<"<.";
			rep(j,34)
				cout<<'<';
			cout<<endl;
			
			cout<<'^';
			rep(j,34)
				cout<<'>';
			rep(j,32)
				cout<<".>";
			cout<<'v'<<endl;
		}
		cout<<'^';
		rep(i,33)
			cout<<"<.";
		rep(i,33)
			cout<<'<';
		cout<<endl;
		cout<<"1 1"<<endl;
	}
	return 0;
}