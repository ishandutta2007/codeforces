#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
struct ob {int64_t x; int64_t y;};
	int64_t n,m,i,j,gd,needed,remain,c,d,x,y,maxx,maxy,maxp,done=0,all=0,countb=0,countc=0,page,removed=0,temp,op=0,a[51][51],b[51][51]; 
	vector <ob> lis; ob hold;
int64_t check(int64_t x, int64_t y)
{
	int64_t painted=0;
	if (!((a[x][y])and(a[x][y+1])and(a[x+1][y])and(a[x+1][y+1]))) return 0;
	if (!(b[x][y])) painted++;
	if (!(b[x+1][y])) painted++;
	if (!(b[x][y+1])) painted++;
	if (!(b[x+1][y+1])) painted++;
	return painted;
}


int main()
{ 
	cin>>n>>m;
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) {cin>>a[i][j]; if (a[i][j]) all++;}
	while (done<all) {maxx=0; maxy=0; maxp=0;
	for (i=1;i<n;i++) for (j=1;j<m;j++) {d=check(i,j); if (maxp<d) {maxx=i;maxy=j;maxp=d;}}
	if (maxp==0) {cout<<-1; return 0;}
	b[maxx][maxy]=1; 
	b[maxx][maxy+1]=1;
	b[maxx+1][maxy]=1;
	b[maxx+1][maxy+1]=1;
	done+=maxp;
	hold.x=maxx; hold.y=maxy; lis.push_back(hold);
}
	cout<<lis.size()<<endl;
	for (i=0;i<lis.size();i++) cout<<lis[i].x<<' '<<lis[i].y<<endl;
}