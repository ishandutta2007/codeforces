#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
 
	int64_t n,m,i,j,gd,needed,hol,remain,k,e,ee,minn,maxx,fail, last,top, countt=0,counts=0,page,removed=0,temp,op=0,pc[10001]; vector <int64_t> d; 
int64_t gccd(int64_t x, int64_t y)
{
	int64_t a=x>y?x:y,b=x<y?x:y,z;
	while ((a!=0)and(b!=0)) {a%=b; z=a; a=b; b=z;}
	return a;
}
int main()
{
	d.clear();
	cin>>n>>m>>k;
	for(i=1;i<=n;i++) if (i!=k) d.push_back(i);
	if ((m<n-1)or(m>(n-1)+((n-2)*(n-3)/2))) {cout<<-1; return 0;}
	for (i=0;i<n-1;i++) cout<<k<<' '<<d[i]<<endl;
	m-=n-1;
	for (i=0;i<n-3;i++) for (j=i+1;j<n-2;j++) {if (m<=0) break; else {cout<<d[i]<<' '<<d[j]<<endl; m--;}}
}