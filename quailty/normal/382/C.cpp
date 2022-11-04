#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int INF=0x3f3f3f3f;
int a[MAXN];
vector<int>res;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    if(n==1)return 0*printf("-1");
    if(n==2 && (a[0]+a[1])%2==0)
        res.push_back((a[0]+a[1])/2);
    int mi=INF;
    for(int i=1;i<n;i++)
        mi=min(mi,a[i]-a[i-1]);
    int cnt=0,isok=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]-a[i-1]==mi)continue;
        cnt++;
        if(a[i]-a[i-1]!=2*mi)isok=0;
    }
    if(isok)
    {
        if(cnt==0)
        {
            res.push_back(2*a[0]-a[1]);
            res.push_back(2*a[n-1]-a[n-2]);
        }
        else if(cnt==1)
        {
            for(int i=1;i<n;i++)
                if(a[i]-a[i-1]==2*mi)
                    res.push_back((a[i-1]+a[i])/2);
        }
    }
    sort(res.begin(),res.end());
    res.erase(unique(res.begin(),res.end()),res.end());
    printf("%d\n",(int)res.size());
    for(int i=0;i<(int)res.size();i++)
        printf("%d ",res[i]);
    return 0;
}