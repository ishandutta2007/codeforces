#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int a[MAXN];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int lef=1,rig=n,las=0,mov=0,suml=0,sumr=0;
        while(lef<=rig)
        {
            int cur=0;
            while(lef<=rig && cur<=las)
                cur+=a[lef++];
            mov++,suml+=cur,las=cur,cur=0;
            if(lef>rig)break;
            while(lef<=rig && cur<=las)
                cur+=a[rig--];
            mov++,sumr+=cur,las=cur,cur=0;
        }
        printf("%d %d %d\n",mov,suml,sumr);
    }
    return 0;
}