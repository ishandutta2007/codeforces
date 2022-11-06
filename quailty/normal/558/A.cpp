#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
pair<int,int>p[105],m[105];
int cntp,cntm;
int main()
{
    int n;
    scanf("%d",&n);
    int x,a;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&x,&a);
        if(x<0)m[cntm++]=make_pair(-x,a);
        else p[cntp++]=make_pair(x,a);
    }
    sort(p,p+cntp);
    sort(m,m+cntm);
    int tot=0;
    int loc;
    for(loc=0;loc<min(cntp,cntm);loc++)
    {
        tot+=m[loc].second+p[loc].second;
    }
    int res1=tot,res2=tot;
    if(loc<cntp)res1+=p[loc].second;
    else res2+=m[loc].second;
    printf("%d\n",max(res1,res2));
    return 0;
}