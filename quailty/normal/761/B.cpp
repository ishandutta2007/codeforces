#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
int a[55],b[55];
int main()
{
    int n,L;
    scanf("%d%d",&n,&L);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    a[n+1]=a[1]+L;
    deque<int>da;
    for(int i=1;i<=n;i++)
        da.push_back(a[i+1]-a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    b[n+1]=b[1]+L;
    deque<int>db;
    for(int i=1;i<=n;i++)
        db.push_back(b[i+1]-b[i]);
    for(int i=0;i<n;i++)
    {
        if(da==db)return 0*printf("YES");
        da.push_back(da.front());
        da.pop_front();
    }
    return 0*printf("NO");
}