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
	int64_t n,m,i,j,gd,needed,remain,a,b,c,d,e,f,x,y,z=1000000000001,t2,t1,fail,k, last,po=0, count0=0,count1=0,cur,izlake,page,removed=0,temp,op=0,al[200001]; char map[52][52]; 
	vector <int64_t> bl[200001];
	long double r,xx,yy,dist,aa,bb,cc,dd;
	vector <ob> all; ob h;
	string s,t,res;

int main()
{ 	t2=1;
	for (t1=1;t1<=t2;t1++)
{
	cin>>n>>s>>t; cout<<"YES"<<endl;
	x=((s[1]%3)-(s[0]%3)); if (x==-2)  x=1; if (x==2)  x=-1;
	y=((t[1]%3)-(t[0]%3)); if (y==-2)  y=1; if (y==2)  y=-1;
	if ((x*y)!=-1)
	{if (x==1) for (i=1;i<=n;i++) cout<<"cba"; else if (x==-1) for (i=1;i<=n;i++) cout<<"abc"; 
	else if (y==1) for (i=1;i<=n;i++) cout<<"cba"; else for (i=1;i<=n;i++) cout<<"abc"; }
	else {
	if (s=="ab") {for (i=1;i<=n;i++) cout<<'b'; for (i=1;i<=n;i++) cout<<'c'; for (i=1;i<=n;i++) cout<<'a';} else
	if (s=="bc") {for (i=1;i<=n;i++) cout<<'c'; for (i=1;i<=n;i++) cout<<'a'; for (i=1;i<=n;i++) cout<<'b';} else
	if (s=="ca") {for (i=1;i<=n;i++) cout<<'a'; for (i=1;i<=n;i++) cout<<'b'; for (i=1;i<=n;i++) cout<<'c';} else
	if (s=="ac") {for (i=1;i<=n;i++) cout<<'c'; for (i=1;i<=n;i++) cout<<'b'; for (i=1;i<=n;i++) cout<<'a';} else
	if (s=="cb") {for (i=1;i<=n;i++) cout<<'b'; for (i=1;i<=n;i++) cout<<'a'; for (i=1;i<=n;i++) cout<<'c';} else
	if (s=="ba") {for (i=1;i<=n;i++) cout<<'a'; for (i=1;i<=n;i++) cout<<'c'; for (i=1;i<=n;i++) cout<<'b';}
}
}
}