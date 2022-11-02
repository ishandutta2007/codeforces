#include <bits/stdc++.h>
using namespace std;
int cnt[2][200007];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,l,r,br=0;
        scanf("%d%d%d",&n,&l,&r);
        for(int i=1;i<=n;i++) cnt[0][i]=cnt[1][i]=0;
        for(int i=0;i<l;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            cnt[0][tmp]++;
        }
        for(int i=0;i<r;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            if(cnt[0][tmp]) {cnt[0][tmp]--; br++;}
            else cnt[1][tmp]++;
        }
        r-=br; l-=br;
        int le=0,de=1;
        if(l<r) {swap(le,de); swap(l,r);}
        int pr=0;
        for(int i=1;i<=n;i++) pr+=cnt[le][i]/2;
        if(r+2*pr>l) printf("%d\n",n/2-br);
        else printf("%d\n",r+pr+(l-r-2*pr));
    }
}