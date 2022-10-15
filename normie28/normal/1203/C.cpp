#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
 
	int64_t n,m,i,j,gd,needed,hol,remain,k,e,ee,minn,maxx,fail, last,top, countt=0,counts=0,page,removed=0,temp,op=0,pc[10001]; vector <int64_t> d,sd; 
int64_t gccd(int64_t x, int64_t y)
{
	int64_t a=x>y?x:y,b=x<y?x:y,z;
	while ((a!=0)and(b!=0)) {a%=b; z=a; a=b; b=z;}
	return a;
}
int main()
{
	cin>>n; cin>>gd;
	for (i=1;i<=n;i++) {cin>>k; gd=gccd(gd,k);}
	j=0; last=1; i=1;
	while (gd!=1) {last=i; i=2; {while(gd%i!=0) {i++; if (i>sqrt(gd)) i=gd;}} if (last<i) j++; pc[j]++; gd/=i; }
	countt=1;
	for (i=1;i<=j;i++) countt*=pc[i]+1; cout<<countt;
}