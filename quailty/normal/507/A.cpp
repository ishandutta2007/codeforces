#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>ans;
struct ins
{
    int d,c;
}a[105];
bool comp(ins a,ins b)
{
    return a.c<b.c;
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].c);
        a[i].d=i;
    }
    sort(a+1,a+n+1,comp);
    for(int i=1;i<=n;i++){
        k-=a[i].c;
        if(k<0)break;
        ans.push_back(a[i].d);
    }
    int t=ans.size();
    printf("%d\n",t);
    for(int i=0;i<t;i++){
        if(i==0)printf("%d",ans[i]);
        else printf(" %d",ans[i]);
    }
    return 0;
}