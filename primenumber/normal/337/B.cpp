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

int gcd(int lhs,int rhs)
{
	if(lhs<rhs)return gcd(rhs,lhs);
	else if(rhs == 0)return lhs;
	else return gcd(rhs,lhs%rhs);
}

int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a*d>b*c)
	{
		int g = gcd(a*d,a*d-b*c);
		int chl = (a*d-b*c)/g;
		int par = a*d/g;
		cout<<chl<<'/'<<par<<endl;
	}
	else if(a*d<b*c)
	{
		int g = gcd(b*c,b*c-a*d);
		int chl = (b*c-a*d)/g;
		int par = b*c/g;
		cout<<chl<<'/'<<par<<endl;
	}
	else
		cout<<"0/1"<<endl;
	return 0;
}