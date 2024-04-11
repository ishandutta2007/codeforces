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
	all.clear();
	cin>>n; 
	count0=0;
	for (i=1;i<=n;i++) {cin>>h.val; h.pos=i; all.push_back(h);}
	sort (all.begin(),all.end());
	count0++; cur=all[0].pos;
	for (i=1;i<n;i++) {if (all[i].pos>cur) {count0++; cur=all[i].pos;}}
	cout<<n-count0<<endl;
}
}