#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>
using namespace std;
 
	int64_t n,m,i,j,sum,needed,hol,remain,k,e,ee,xx,yy,x,y; vector <int64_t> d; 
int main()
{
	sum=0;
	cin>>n>>m;
	k=gcd(m,n);
	cin>>e; 
	for (i=1;i<=e;i++){cin>>x>>xx>>y>>yy; xx--; yy--;
	if (x==1) xx/=(n/k); else xx/=(m/k);
	if (y==1) yy/=(n/k); else yy/=(m/k);
	if (xx==yy) cout<<"YES"; else cout<<"NO"; cout<<endl; }
}