#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
	int64_t z,n,t,t1,k,fla,i,j,m,count,min=2000001; vector<char> s,rgb[4]; char c; const char cycle[3]={'R','G','B'};
	cin>>t;
	for (t1=1;t1<=t;t1++)
	{count=0; min=2000001; s.clear(); rgb[1].clear(); rgb[2].clear();rgb[3].clear();
	cin>>n>>k;
	m=0;
	for (i=1;i<=n;i++) {cin>>c;  s.push_back(c); for (j=1;j<=3;j++) {rgb[j].push_back(cycle[m]); m++; m%=3; } m++; m%=3; } 
	count=0;
//	for (j=1;j<=3;j++) {{for (i=0;i<n;i++) cout<<rgb[j][i];} cout<<endl;}
	for (j=1;j<=3;j++) 
	{
	count=0; for (i=0;i<n;i++) { 
	if (s[i]!=rgb[j][i]) count++; 
	if ((i>k-1)and(s[i-k]!=rgb[j][i-k])) count--;
	
	
	if (i>=k-1) {
	if (min>count) min=count;}}}
	
	cout<<min<<endl;
}
}