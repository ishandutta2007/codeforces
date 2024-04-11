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
	int64_t n,m,i,j,gd,needed,remain,a,b,c,d,e,f,x,y,z=1000000000001,t,t1,fail,k, last,po=0, count0=0,count1=0,cur,izlake,page,removed=0,temp,op=0,al[200001]; char map[52][52]; 
	vector <int64_t> bl[200001];
	long double r,xx,yy,dist,aa,bb,cc,dd;
	vector <ob> all; ob h;

int main()
{ 	t=1;
	for (t1=1;t1<=t;t1++)
{z=1000000000001;
	cin>>n>>k;
	for (i=1;i<=n;i++) cin>>al[i];
	for (i=1;i<=n;i++) {
	x=al[i];
	count0=0;
	while (x>0) {bl[x].push_back(count0); x/=2; count0++;}
	bl[x].push_back(count0);
}
	for (i=0;i<=200000;i++) if (bl[i].size()>=k) {sort(bl[i].begin(),bl[i].end()); count1=0; for (j=0;j<k;j++) {count1+=bl[i][j];} 
	if (count1<z) z=count1; } 
	cout<<z;
}
}