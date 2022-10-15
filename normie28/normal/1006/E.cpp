#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
struct ob {int64_t val; int64_t gt[2];};
	long n,m,i,j,gd,needed,hol,remain,k,e,ee,x,y,fail,srec[200001],erec[200001], last,top, countt=0,counts=0,page,removed=0,temp,op=0,used[500001]; 
	vector <int64_t> gt[200001], recieved; 
void dfvisit(int64_t cur, int64_t prev)
{
	int64_t ii;  //cout<<"dfvisit("<<cur<<")\n";
	 srec[cur]=recieved.size(); recieved.push_back(cur);
	for (ii=0;ii<gt[cur].size();ii++) if (!used[gt[cur][ii]]) { used[cur]=1; dfvisit(gt[cur][ii],cur); 
	 used[cur]=0;}
	erec[cur]=recieved.size()-1;
//	for (ii=0;ii<recieved.size();ii++) cout<<recieved[ii]<<' '; cout<<endl;
}
int main()
{ 
	cin>>n>>e;
	for (i=1;i<=n;i++) {if (i!=1) {cin>>k; gt[k].push_back(i); gt[i].push_back(k);}}
	for (i=1;i<=n;i++) sort(gt[i].begin(),gt[i].end());
	recieved.clear(); dfvisit(1,0);
	for (i=1;i<=e;i++) {cin>>x>>y;  if (erec[x]-srec[x]+1<y) cout<<-1<<endl; else cout<<recieved[srec[x]+y-1]<<endl;}
}