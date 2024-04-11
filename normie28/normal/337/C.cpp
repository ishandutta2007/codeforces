#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

	int64_t n,m,i,j,cycles,needed,hol,remain,k,e,minn,maxx, si,sj, countt=0,counts=0,page,removed=0,temp,op=0,po2for2ttpon[32]; 
int main()
{
	po2for2ttpon[0]=2;
	for (i=1;i<=31;i++) {po2for2ttpon[i]=(po2for2ttpon[i-1]*po2for2ttpon[i-1])%1000000009;}
	cin>>n>>m>>k;
	cycles=n/(k);
	if (m<=cycles*(k-1)+(n%(k))) needed=0; else needed=m-(cycles*(k-1)+(n%(k)));
	e=1; i=0; hol=needed;
	while (hol>0) {if (hol%2) e*=po2for2ttpon[i]; e%=1000000009; i++; hol/=2; } e-=1; e%=1000000009; e*=(2*k); e%=1000000009;
	 e+=m-((k)*needed); e%=1000000009;
	cout<<e;
}