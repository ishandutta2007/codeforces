#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int id[MAXN];
int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++)
    {
        int s,d;
        scanf("%d%d",&s,&d);
        for(int j=s;j<MAXN;j+=d)
            id[j]=i;
    }
    for(int i=t;i<MAXN;i++)
        if(id[i])return 0*printf("%d\n",id[i]);
    return 0;
}