#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
struct road {int64_t to; int64_t len;};
	long n,m,i,j,gd,needed,hol,remain,k,e,ee,x,y,fail,srec[200001],erec[200001], last,top, coun=0,s=0,page,removed=0,temp,op=0,used[500001]; 
	vector <road> gt[200001], recieved; road hold;
void dfvisit(int64_t cur, int64_t prev)
{
	int64_t ii;  //cout<<"dfvisit("<<cur<<")\n";
	coun++;
	for (ii=0;ii<gt[cur].size();ii++) if (!used[gt[cur][ii].to]) { used[cur]=1; if (coun<n) s+=gt[cur][ii].len; dfvisit(gt[cur][ii].to,cur); 
	if (coun<n) s+=gt[cur][ii].len;}

//	for (ii=0;ii<recieved.size();ii++) cout<<recieved[ii]<<' '; cout<<endl;
}
int main()
{ 
	cin>>n>>x>>y;
	if ((x<=(2*y))and(!((x==y)and(y==1)and(n>=3)))) {
	if (x!=y) for (i=2;i<=n;i++) {if ((i==2)or(i==y+2)or(i>x+1)) cout<<1<<' '<<i; else cout<<i-1<<' '<<i; cout<<endl;} else if (x!=2)
	for (i=2;i<=n;i++) {if (i>x+1) cout<<x<<' '<<i; else cout<<i-1<<' '<<i; cout<<endl;} else
	for (i=2;i<=n;i++) {if (i>x+1) cout<<2<<' '<<i; else cout<<i-1<<' '<<i; cout<<endl;}
} else cout<<-1;
}