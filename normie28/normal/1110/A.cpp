#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
	long long n,m,i,j,k,x,y,countt=0,counts=0,minn,maxx, found,fr,bk; vector<string> a; 
 
int main()
{
	cin>>n>>k;
	countt=0;
	for (i=1;i<=k;i++) {cin>>x; countt+=x;}
	if (n%2==0) countt=x;
	if (countt%2) cout<<"odd"; else cout<<"even";
}