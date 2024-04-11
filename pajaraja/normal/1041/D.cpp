#include <bits/stdc++.h>
#define MAXN 200007
using namespace std;
pair<int,int> a[MAXN];
int b[MAXN];
int main()
{
	int n,h,sl=0;
	scanf("%d%d",&n,&h);
	for(int i=0;i<n;i++) {scanf("%d%d",&a[i].first,&a[i].second);}
	sort(a,a+n);
	for(int i=1;i<n;i++) b[i]=a[i].first-a[i-1].second;
	int t1=0,t2=0,s=0;
	while(t2<=n)
	{
		while(s>=h) s-=b[++t1];
		sl=max(sl,a[t2].second-a[t1].first-s);
		s+=b[++t2];
	}
	printf("%d\n",sl+h);
}