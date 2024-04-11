#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#define WT '.'
#define LA '*'
using namespace std;
struct lk {int64_t ox; int64_t oy; int64_t size;};
struct ob {int64_t val; int64_t stps;};
	int64_t n,m,i,j,gd,needed,remain,e,f,x,y,z=1000000000001,t2,t1,fail,k,clrs, last,po=0,poo, count0=0,count1=0,cur,izlake,page,removed=0,temp,op=0,
	a[2002],b[2002],c[2002],d[2002],dp[2002][1001]; 
	char res[200001]; 
	vector <int64_t> gt[200001],con[200001];
	long double r,xx,yy,dist,aa,bb,cc,dd;
	vector <ob> all; ob h;
	string s,t;



int main()
{ 	t2=1;
	for (t1=1;t1<=t2;t1++)
{
	cin>>n>>m>>c[0]>>d[0];
	for (i=1;i<=m;i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
	for (i=0;i<=m;i++) for (j=1;j<=n;j++) if (i==0) dp[i][j]=j/c[i]*d[i]; else { //cout<<"dp["<<i<<"]["<<j<<"]=";
	if ((j/c[i])<(a[i]/b[i])) x=j/c[i]; else x=a[i]/b[i];
	for (k=0;k<=x;k++) { if (dp[i][j]<dp[i-1][j-k*c[i]]+k*d[i]) dp[i][j]=dp[i-1][j-k*c[i]]+k*d[i];}
	//cout<<dp[i][j]<<endl;
}
	cout<<dp[m][n];
}
}