#include<bits/stdc++.h>
using namespace std;

const int MAXN=100005;
char str[MAXN],res[MAXN];
int mask[MAXN],lef[6],rig[64],sum[64];

bool check()
{
    int all=0;
    for(int i=0;i<64;i++)
        all+=(sum[i]=rig[i]);
    for(int i=0;i<6;i++)
        for(int j=0;j<64;j++)
            if(~j>>i&1)sum[j|(1<<i)]+=sum[j];
    for(int i=0;i<(1<<6);i++)
    {
        int now=0;
        for(int j=0;j<6;j++)
            if(i>>j&1)now+=lef[j];
        if(now>all-sum[63-i])return 0;
    }
    return 1;
}

int main()
{
    int m;
    scanf("%s%d",str+1,&m);
    int n=strlen(str+1);
    for(int i=1; i<=n; i++)
        mask[i]=63;
    for(int i=1; i<=m; i++)
    {
        int p;
        char ban[15];
        scanf("%d%s",&p,ban);
        mask[p]=0;
        for(int j=0; ban[j]; j++)
            mask[p]|=(1<<(ban[j]-'a'));
    }
    for(int i=1; i<=n; i++)
    {
        lef[str[i]-'a']++;
        rig[mask[i]]++;
    }
    if(!check())return 0*printf("Impossible\n");
    for(int i=1; i<=n; i++)
    {
        bool isok=0;
        for(int j=0; j<6 && !isok; j++)
            if(lef[j] && (mask[i]>>j&1))
            {
                lef[j]--;
                rig[mask[i]]--;
                if(check())
                {
                    res[i]=j+'a';
                    isok=1;
                    break;
                }
                lef[j]++;
                rig[mask[i]]++;
            }
        if(!isok)return 0*printf("Impossible\n");
    }
    return 0*printf("%s\n",res+1);
}