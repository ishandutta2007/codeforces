#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
 
	int64_t n,m,i,j,sum,needed,hol,remain,k,e,ee,minn,maxx,fail, bot,top, countt=0,counts=0,page,removed=0,temp,op=0,po2for2ttpon[64]; vector <int64_t> d,sd; 
int main()
{
	sum=0;
	cin>>e;
	for (ee=1;ee<=e;ee++) { fail=0; sum=0; d.clear();sd.clear();
	cin>>n; n*=4; 
	for (i=1;i<=n;i++) {cin>>k; d.push_back(k);}
	sort (d.begin(),d.end()); 
	sd.push_back(d[0]);
	sum=1;
	sort (d.begin(),d.end());
	for (i=1;i<n;i++) {if (d[i]==d[i-1]) {sum++; if (sum%2) sd.push_back(d[i]);} else {if (sum%2) {fail=1; break;} else {sum=1; sd.push_back(d[i]);}}}
	sort (sd.begin(),sd.end());
	k=sd[0]*sd[sd.size()-1]; 
	for (i=1;i<sd.size()/2;i++) if (sd[i]*sd[sd.size()-1-i]!=k) fail=1;
	if (fail) cout<<"NO"; else cout<<"YES";
cout<<endl; 
}
}