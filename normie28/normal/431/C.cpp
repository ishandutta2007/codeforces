#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
struct ob {int64_t val; int64_t pos;};
	int64_t n,m,i,j,k,gd,needed,remain,a,b,c,d,e,f,x,y,z,fail, last,po=0, countt=0,counts=0,page,removed=0,temp,op=0,dp[101][2],used[500001]; 
	long double r,xx,yy,dist,aa,bb,cc,dd;
vector <int64_t> bui(int64_t x)
{
	vector <int64_t> ii,jj; 
	if (x>=2) {ii=bui(x/2); jj=ii; ii.push_back(x%2); ii.insert(ii.end(),jj.begin(),jj.end());} else {ii.push_back(x);}
	return ii;
}
int main()
{ 	
	cin>>n>>k>>d;
	dp[0][0]=0; dp[0][1]=1;
	for (i=1;i<=n;i++) for (j=0;j<=1;j++) if ((j==0)and(i<d)) dp[i][j]=0;
	else	{
	for (a=1;a<=k;a++) if (i-a>=0) {if ((a>=d)or(j==1))
	dp[i][j]+=dp[i-a][1]; else dp[i][j]+=dp[i-a][0]; dp[i][j]%=1000000007;}
}
	cout<<dp[n][0];
}