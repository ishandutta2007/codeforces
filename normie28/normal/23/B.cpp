#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
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
	cin>>n;
	for (i=1;i<=n;i++) {cin>>e; if (e-2<0) cout<<0<<endl; else cout<<e-2<<endl;}
}