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
struct ob {int64_t val; int64_t pos;};
	int64_t n,m,i,j,gd,needed,remain,a,b,c,d,e,f,x,y,z,t,t1,fail, last,po=0, count0=0,count1=0,cur,izlake,page,removed=0,temp,op=0,used[52][52]; char map[52][52]; 
	long double r,xx,yy,dist,aa,bb,cc,dd;
	vector <ob> all; ob h;

int operator<(ob a, ob b) {if (a.val!=b.val) return a.val<b.val; else return a.pos<b.pos;}
int main()
{ 	cin>>t;
	for (t1=1;t1<=t;t1++)
{
	cin>>n>>m;
	b=0; a=0;
	for (i=1;i<=10;i++) b+=(m*i)%10;
	 a+=b*(n/(m*10));
	i=(n/(m*10)); x=i*(m*10);

	while (true) {x+=m; if (x<=n) a+=x%10; else break;}
	cout<<a<<endl;
}
}