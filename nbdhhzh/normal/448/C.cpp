#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,i,a[5010],m1;
int play(int x,int y,int z)
{
    int ans=0,sg;
    if (z>m1)return 0;sg=x-1;
    for (int i=x;i<=y;i++)
    if (a[i]==z)
    {
        if (sg!=i-1)ans+=play(sg+1,i-1,z+1);
        ans+=1;sg=i;
    }
    ans+=play(sg+1,y,z+1);
    return max(ans-1,0);
}
int main()
{
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]>m1)m1=a[i];
    }
    if (m1>n)m1=n;a[0]=m1+1;
    printf("%d",n-play(1,n,1));
}