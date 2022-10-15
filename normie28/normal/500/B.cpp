#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
struct ob {int64_t val; int64_t pos;};
	long n,m,i,j,gd,needed,remain,k,e,ee,x,y,fail, last,po=0, countt=0,counts=0,page,removed=0,temp,op=0,fina[500001],used[500001]; 
	vector <int64_t> gt[200001],lt[301],lp[301];vector<ob> nds; ob hol; char c;
void dfvisit(int64_t cur, int64_t prev)
{
	int64_t ii; used[cur]=1; //cout<<"dfvisit("<<cur<<")\n"; 
	lt[po].push_back(nds[cur].val); lp[po].push_back(nds[cur].pos);
	
	for (ii=0;ii<gt[cur].size();ii++) if (!used[gt[cur][ii]]) { dfvisit(gt[cur][ii],cur);}
}
int main()
{ 
	hol.val=0; hol.pos=0; nds.push_back(hol);
	cin>>n;
	for (i=1;i<=n;i++) {cin>>hol.val; hol.pos=i; nds.push_back(hol);}
	for (i=1;i<=n;i++) {for (j=1;j<=n;j++) { cin>>c; if (c=='1') {gt[i].push_back(j); 
//	cout<<i<<' '<<j<<endl;
	} }}
	while (true) {po++; x=1; while (used[x]) x++; if (x>n) break; dfvisit(x,0); } 
	for (i=1;i<=po;i++) {sort(lt[i].begin(),lt[i].end()); sort(lp[i].begin(),lp[i].end()); for (j=0;j<lt[i].size();j++) {fina[lp[i][j]]=lt[i][j]; 
//	cout<<lp[po][j]<<' '<<lt[po][j]<<endl;
	}}
	for (i=1;i<=n;i++) {cout<<fina[i]<<' ';}
}