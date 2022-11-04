#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1005;
pair<int,int> h[MAXN];
int main()
{
    int n,t;
    scanf("%d%d",&n,&t);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&h[i].first,&h[i].second);
    sort(h+1,h+n+1);
    int res=2;
    for(int i=1;i<n;i++)
    {
        int g=2*(h[i+1].first-h[i].first)-(h[i].second+h[i+1].second);
        res+=(g>=2*t)+(g>2*t);
    }
    return 0*printf("%d",res);
}