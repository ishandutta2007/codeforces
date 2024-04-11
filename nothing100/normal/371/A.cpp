#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,ans,num[100][3],tmp;
int main()
{
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        num[i%k][tmp]++;
    }
    for (int i=0;i<k;i++) ans=ans+min(num[i][1],num[i][2]);
    printf("%d",ans);
}