#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
	long long n,m,i,j,k,x,y,countt=0,counts=0,minn,maxx, found,fr,bk; vector<long long> a; 
 
int main()
{
	cin>>n>>m>>k;
	cin>>x;
	for (i=1;i<n;i++) {y=x; cin>>x; a.push_back(x-y-1);}
	sort(a.begin(),a.end());
	countt=n;
	if (k!=n) for (i=1;i<=n-k;i++) countt+=a[i-1];
	cout<<countt;
}