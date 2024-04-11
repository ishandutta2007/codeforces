#include <cstdio>
#include <vector>

using namespace std;

int main() {
	//freopen("input.txt","r",stdin);
	int n,k,q;
	scanf("%d%d",&n,&k);
	vector <bool> used(n+1,false);
	int bil[n/k+1];
	double a[n+1];
	for (int i=1;i<=n;i++)
		{scanf("%lf",&a[i]);}
	
	double min=10000; double max=-1;
	scanf("%d",&q);
	int us=0;
	for (int i=1;i<=q;i++)
	{ for (int j=1;j<=n/k;j++)
		{scanf("%d",&bil[j]);if (!used[bil[j]]) {used[bil[j]]=true;us++;}}
	  double sum=0;	
	  for (int j=1;j<=n/k;j++)
		  sum+=a[bil[j]];
	  if (sum/(n/k)>max) max=sum/(n/k);
	  if (sum/(n/k)<min) min=sum/(n/k);
	}
    
	if (us/(n/k)>=k) {	printf("%.10lf %.10lf",min,max); return 0;}
	//printf("%.7lf %.7lf\n",min,max);
	vector <int> mmin; vector <int> mmax;
	vector <bool> maxused(n+1,false);vector <bool> minused(n+1,false);
	
	for (int i=1;i<=n/k;i++)
	{   double maxx=-1; int imax=-1;
		for (int j=1;j<=n;j++)
		{ if (a[j]>maxx&!maxused[j]&!used[j]) {maxx=a[j];imax=j;} }
		maxused[imax]=true;
		mmax.push_back(imax);
	}
	double sum=0;
	for (int i=0;i<(int)mmax.size();i++)
		{sum+=a[mmax[i]];}	
	if (sum/(n/k)>max) max=sum/(n/k);
	if (sum/(n/k)<min) min=sum/(n/k);
	
	//printf("%.7lf %.7lf\n",min,max);
	for (int i=1;i<=n/k;i++)
	{   double minn=10000; int imin;
		for (int j=1;j<=n;j++)
		  if (a[j]<minn&!minused[j]&!used[j]) {minn=a[j];imin=j;} 
		minused[imin]=true;  
		mmin.push_back(imin);
	}
	sum=0;
	for (int i=0;i<(int)mmin.size();i++)
		{sum+=a[mmin[i]];}
	if (sum/(n/k)>max) max=sum/(n/k);
	if (sum/(n/k)<min) min=sum/(n/k);
	
	
	printf("%.10lf %.10lf",min,max);
	return 0;
}