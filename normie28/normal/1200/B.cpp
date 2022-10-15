#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
using namespace std;
 
	long long n,m,i,j,sum,needed,hol,remain,k,e,ee,xx,yy,x,y; vector <long long> d; 
int main()
{
	sum=0; cin>>e;
	for (ee=1;ee<=e;ee++)
	{
	cin>>n>>m>>k; d.clear();
	d.push_back(-1);
	for (i=1;i<=n;i++) {cin>>x; d.push_back(x);} i=1;
	while (i<n) {if (d[i+1]-k<0) m+=d[i]; else m+=d[i]-(d[i+1]-k); if (m<0) {cout<<"NO"; break;} else i++;}
	if (i==n) cout<<"YES";
	cout<<endl;
	}
}