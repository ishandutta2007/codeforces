#include <cstdio>

int min(int a,int b) { return a>b?b:a; }
int abs(int a) { return a>0?a:-a; }

int a[1010];
int b[1010];

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;++i) scanf("%1d",a+i);
    for(i=0;i<n;++i) scanf("%1d",b+i);
    int ans=0;
    for(i=0;i<n;++i){
        ans+=min(abs(a[i]-b[i]),10-abs(a[i]-b[i]));
    }
    printf("%d\n",ans);
    return 0;
}