#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn=1005;
int num[maxn],d[maxn],pop[maxn];
bool cmp(int a,int b){return d[a]<d[b];}
int main()
{
 	int n,s,x,y;
 	scanf("%d%d",&n,&s);
 	for(int i=0;i<n;i++)scanf("%d%d%d",&x,&y,&pop[i]),num[i]=i,d[i]=x*x+y*y;
 	sort(num,num+n,cmp);
 	int res;
 	for(int i=0;i<n&&s<1000000;i++)res=d[num[i]],s+=pop[num[i]];
 	if(s<1000000)printf("-1");else printf("%.10lf",sqrt(res));
 	//system("pause");
 	return 0;
}