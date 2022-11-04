#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
char s[MAXN];
int solve()
{
    int n,k;
    scanf("%d%d%s",&n,&k,s+1);
    vector<int> one;
    for(int i=1;i<=n;i++)
        if(s[i]=='1')one.push_back(i);
    if(one.empty())return 0*printf("0\n");
    int fir=one.front(),las=one.back();
    if(fir==las)
    {
        if(n-las<=k)printf("1\n");
        else if(fir-1<=k)printf("10\n");
        else printf("11\n");
    }
    else
    {
        int res=(int)one.size()*11;
        if(n-las<=k)res-=10,k-=n-las;
        if(fir-1<=k)res-=1;
        printf("%d\n",res);
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}