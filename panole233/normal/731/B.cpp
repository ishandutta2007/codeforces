#include<cstdio>
#include<cstring>

int a[200001];
int n;

int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
        if (a[i]) a[i]-=((a[i]+1)/2-1)<<1;
    }
    for (int i=1; i<=n+1; i++)
    {
        if(a[i]<0) {printf("NO"); return 0;}
        else if (a[i]==0) continue;
        else if (a[i]==1) a[i]--,a[i+1]--;
        else a[i]-=2;
    }
	printf("YES");
	return 0;
}