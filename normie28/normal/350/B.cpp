#include <iostream> 
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
struct ob {int64_t izht; int64_t gt; int64_t ma=0;};
	int64_t n,m,i,j,gd,needed,hol,remain,k,e,ee,maxxi,maxx=0,fail, last,top, countt=0,counts=0,page,removed=0,temp,op=0,gt[100001],izht[100001],ma[100001],cou[100001]; vector <int64_t> vqueue; ob hol1; 

int main()
{ vqueue.clear();
	cin>>n;
	maxx=0;
	for(i=1;i<=n;i++) {cin>>izht[i]; if (izht[i]) vqueue.push_back(i);}
	for(i=1;i<=n;i++) {cin>>gt[i]; cou[gt[i]]++;}
	for (i=0;i<vqueue.size();i++) {j=vqueue[i]; countt=1; while ((izht[gt[j]]==0)and(cou[gt[j]]==1)and(gt[j]!=0)) {countt++; j=gt[j];} if (maxx<countt) {maxx=countt; maxxi=vqueue[i];}}
	cout<<maxx<<endl; vqueue.clear(); vqueue.push_back(maxxi);
	j=maxxi; countt=0; while ((izht[gt[j]]==0)and(cou[gt[j]]==1)and(gt[j]!=0)) {vqueue.push_back(gt[j]); j=gt[j];}
	for (i=vqueue.size()-1;i>=0;i--) cout<<vqueue[i]<<' ';
}