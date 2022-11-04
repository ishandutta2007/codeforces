#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int a[MAXN],loc[MAXN],ins[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%d",&a[i]);
        loc[a[i]]=i;
    }
    vector<int> stk;
    stk.push_back(n+1);
    int now=1,ptr=1;
    for(now=1;now<=n;now++)
    {
        if(!loc[now])break;
        while(ptr<=loc[now])stk.push_back(a[ptr++]);
        if(stk.back()!=now)return 0*printf("-1\n");
        stk.pop_back();
    }
    while(ptr<=k)stk.push_back(a[ptr++]);
    stk.push_back(now-1);
    for(int i=0;i+1<(int)stk.size();i++)
        if(stk[i]<stk[i+1])return 0*printf("-1\n");
    for(int i=(int)stk.size()-1;i>0;i--)
        for(int j=stk[i-1]-1;j>stk[i];j--)a[++k]=j;
    assert(n==k);
    for(int i=1;i<=n;i++)
        printf("%d%c",a[i]," \n"[i==n]);
    return 0;
}