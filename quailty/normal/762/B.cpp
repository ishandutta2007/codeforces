#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<int>val[2];
int main()
{
    int a[3],m;
    scanf("%d%d%d%d",&a[0],&a[1],&a[2],&m);
    for(int i=1;i<=m;i++)
    {
        int p;
        char ty[15];
        scanf("%d%s",&p,ty);
        val[*ty=='P'].push_back(p);
    }
    for(int i=0;i<2;i++)
        sort(val[i].begin(),val[i].end(),greater<int>());
    ll tot=0,res=0;
    for(int i=0;i<2;i++)
        while(a[i]-- && !val[i].empty())
        {
            res+=val[i].back();
            tot++;
            val[i].pop_back();
        }
    for(int i=0;i<(int)val[1].size();i++)
        val[0].push_back(val[1][i]);
    sort(val[0].begin(),val[0].end(),greater<int>());
    while(a[2]-- && !val[0].empty())
    {
        res+=val[0].back();
        tot++;
        val[0].pop_back();
    }
    printf("%lld %lld",tot,res);
    return 0;
}