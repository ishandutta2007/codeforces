#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
struct ob {int64_t x; int64_t y;};
	int64_t n,m,i,j,k,l,gd,needed,rec=0,c,d,x,y,maxx,maxy,maxp,done=0,all=0,countt=0,countc=0,page,removed=0,temp,op=0,pill[200010];
	string s; long double aa,bb,cc;


int main()
{ 
	cin>>l; for (k=1;k<=l;k++) { x=-1;y=-1; countt=0;
	cin>>n>>c>>d;
	aa=c;bb=d;
	cc=(aa/bb*2);
	maxx=floor(cc);
	cin>>s;
	for (i=0;i<=n;i++) if ((i==0)or(i==n)) pill[i]=1;
	else pill[i]=(s[i]>s[i-1])?s[i]-47:s[i-1]-47;
//	for (i=0;i<=n;i++) cout<<pill[i]; cout<<endl;
	for (i=0;i<=n;i++) {if (pill[i]==2) if (x==-1) x=i+1; else {y=i-1; if ((y-x+1>0)and(y-x+1<=maxx)) for (j=x;j<=y;j++) pill[j]=2; x=i+1; }}
	for (i=1;i<=n;i++) {if (pill[i]!=pill[i-1]) countt+=c; countt+=pill[i]*d;} countt+=pill[0]*d;
//	for (i=0;i<=n;i++) cout<<pill[i]; cout<<endl;
	countt+=n*c;
	cout<<countt<<endl;
}
}
// floor(2a/b)=k