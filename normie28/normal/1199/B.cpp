#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
	long long n,m,i,j,k,x,y,countp=0,counts=0,minn,maxx, found,a[100001]; long double h,l,res;

int main()
{
	cin>>h>>l;
	res=((pow(h,2)+pow(l,2))/(h*2))-h;
	cout<<fixed<<setprecision(10)<<res;
}