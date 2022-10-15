#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
struct ob {int64_t val; int64_t gt[2];};
	long n,m,i,j,gd,needed,hol,remain,k,e,ee,x,y,fail, last,top, countt=0,counts=0,page,removed=0,temp,op=0,og[500001],used[500001]; vector <int64_t> gt[50001]; 
	vector <int64_t> path; ob hol1; 
void dfvisit(int64_t cur, int64_t prev)
{
	int64_t ii; used[cur]=1; //cout<<"dfvisit("<<cur<<")\n";
	og[cur]=prev; 
	for (ii=0;ii<gt[cur].size();ii++) if (!used[gt[cur][ii]]) { dfvisit(gt[cur][ii],cur);}
}
int main()
{ 
	cin>>n>>e>>ee;
	for (i=1;i<=n;i++) {if (i!=e) {cin>>k; gt[k].push_back(i); gt[i].push_back(k);}}
	dfvisit(ee,0);
	for (i=1;i<=n;i++) {if (i!=ee) cout<<og[i]<<' ';}
}