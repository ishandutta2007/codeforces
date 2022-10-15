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
struct sq {int64_t x; int64_t y;};
	int64_t n,m,i,j,gd,needed,remain,a,b,c,d,e,f,x,y,z,fail, last,po=0, countl=0,izlake,page,removed=0,temp,op=0,used[52][52]; char map[52][52]; 
	long double r,xx,yy,dist,aa,bb,cc,dd;
	vector <sq> patches[51][51]; vector <lk> lakes; lk h; sq hl;
void df(int64_t x, int64_t y)
{
	used[x][y]=1;
	hl.x=x;
	hl.y=y;
	patches[i][j].push_back(hl);
	if (map[x][y-1]==0) izlake=0;
	if (map[x][y+1]==0) izlake=0;
	if (map[x-1][y]==0) izlake=0;
	if (map[x+1][y]==0) izlake=0;

	if ((map[x][y-1]==WT)and(!used[x][y-1])) df(x,y-1);
	if ((map[x][y+1]==WT)and(!used[x][y+1])) df(x,y+1);
	if ((map[x-1][y]==WT)and(!used[x-1][y])) df(x-1,y);
	if ((map[x+1][y]==WT)and(!used[x+1][y])) df(x+1,y);
}
int operator<(lk a, lk b) {return a.size>b.size;}
int main()
{ 	cin>>n>>m>>a;
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) cin>>map[i][j];
	for (i=1;i<=n;i++) for (j=1;j<=m;j++) if (!used[i][j]) {used[i][j]=1; if (map[i][j]==WT) {izlake=1; df(i,j); 
	if (izlake) {h.ox=i;h.oy=j;h.size=patches[i][j].size(); lakes.push_back(h);}
	}}
	sort(lakes.begin(),lakes.end());
	for (i=a;i<lakes.size();i++) {countl+=lakes[i].size; c=lakes[i].ox; d=lakes[i].oy; for (j=0;j<patches[c][d].size();j++) map[patches[c][d][j].x][patches[c][d][j].y]=LA;}
	cout<<countl<<endl;
	for (i=1;i<=n;i++) {for (j=1;j<=m;j++) cout<<map[i][j]; cout<<endl;}
		
}