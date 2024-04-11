#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[100010],last;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(last=3;last<n&&a[last+1]==a[3];last++);
	if(a[1]==a[3])printf("%I64d",(long long)last*(last-1)*(last-2)/6);
	else if(a[2]==a[3])printf("%I64d",(long long)(last-1)*(last-2)/2);
	else printf("%d",last-2);
	return 0;
}