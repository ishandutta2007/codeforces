#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
	long long n,m,i,j,k,x,y; string s,t; long double coun=0,pl=0,res=0,maxx=0,bonus; vector<long long> a;
 
int main()
{
	cin>>n>>k>>m;
	a.clear(); a.push_back(-1);
	for (i=1;i<=n;i++) {cin>>x; a.push_back(x); coun+=x;}
	pl=n;
	bonus=(m<(n*k))?m:n*k;
	res=(coun+bonus)/pl;
	maxx=res;
	sort(a.begin(),a.end());
	for (i=1;i<=((m<(n-1))?m:n-1);i++) {coun-=a[i];
	bonus=((m-i)<((n-i)*k))?m-i:(n-i)*k; pl--;
	res=(coun+bonus)/pl;
	if (res>maxx) maxx=res;
}
	cout<<fixed<<setprecision(10)<<maxx;
}