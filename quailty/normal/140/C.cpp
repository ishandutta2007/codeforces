#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int a[100005];
vector<int>t;
void build(int n,int m)
{
    t.clear();
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(i>1 && a[i]==a[i-1])cnt++;
        else cnt=1;
        if(cnt<=m)t.push_back(a[i]);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int l=0,r=n/3;
    while(l<r)
    {
        int m=(l+r+1)/2;
        build(n,m);
        if((int)t.size()>=3*m)l=m;
        else r=m-1;
    }
    printf("%d\n",l);
    build(n,l);
    for(int i=0;i<l;i++)
        printf("%d %d %d\n",t[i+2*l],t[i+l],t[i]);
    return 0;
}