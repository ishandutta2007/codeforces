#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
	long long n,m,i,j,k,x,y,countt=0,counts=0,minn,maxx, found,fr,bk; vector<long long> a,b;
 
int main()
{
	cin>>n>>maxx; maxx*=8;
	for (i=1;i<=n;i++) {cin>>k; a.push_back(k);}
	if (maxx/n>32) maxx=4000000001; else maxx=pow(2,maxx/n); 
	sort(a.begin(),a.end());
	countt=1;
	if (a.size()==1) {cout<<0; return 0; }
	for (i=1;i<a.size();i++) {if (a[i]==a[i-1]) countt++; else {b.push_back(countt); countt=1;}} {b.push_back(countt); countt=1;}
//	for (i=0;i<b.size();i++) cout<<b[i]<<' ';
//		cout<<endl<<b.size()<<' '<<maxx<<endl;
	if (b.size()<=maxx) {cout<<0; return 0; }
	fr=0; bk=b.size()-1; minn=0;
	countt=0;
	for (i=0;i<b.size(); i++) {countt+=b[i]; if (i>=maxx) countt-=b[i-maxx]; if (i>=maxx-1) if (countt>minn) minn=countt;}
	cout<<n-minn;
}