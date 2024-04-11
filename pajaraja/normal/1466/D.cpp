#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
long long w[MAXN];
bool vi[MAXN];
vector<long long> a;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        a.clear();
        for(int i=1;i<=n;i++) scanf("%lld",&w[i]);
        for(int i=1;i<=n;i++) vi[i]=false;
        for(int i=0;i<2*n-2;i++)
        {
            int t; scanf("%d",&t);
            if(!vi[t]) {vi[t]=true; continue;}
            a.push_back(w[t]);
        }
        long long sol=0;
        for(int i=1;i<=n;i++) sol+=w[i];
        printf("%lld ",sol);
        sort(a.begin(),a.end(),greater<int>());
        for(int i=0;i<n-2;i++)
        {
            sol+=a[i];
            printf("%lld ",sol);
        }
        printf("\n");
    }
}