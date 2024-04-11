#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
 
	int64_t n,m,i,j,sum,needed,fail=0,remain,k,e,ee,minn,maxx,po,lol1,lol2,lol3, dd[40001]; vector <int64_t> d; 
int main()
{
	sum=0;
	cin>>e;
	for (ee=1;ee<=e;ee++) { fail=0;
	cin>>n; 
	if (n==1) {cin>>lol1; cout<<"YES";} else if (n==2) {cin>>lol1>>lol2; cout<<"YES";} else if (n==3) {cin>>lol1>>lol2>>lol3; cout<<"YES";} else {
	for (i=0;i<n;i++) {cin>>dd[i]; if (dd[i]==1) po=i;} d.clear();
	for (i=1;i<=n;i++) {d.push_back(dd[po]); po++; po%=n;}
	if (d[1]==n) k=-1; else if (d[1]==2) k=1; else fail=1;
//	for (i=0;i<n;i++) cout<<d[i]<<' '; 
	for (i=2;i<n;i++) if (d[i]-d[i-1]!=k) fail=1; 
	if (fail==0) cout<<"YES"; else cout<<"NO";
} 
cout<<endl; 
}
}