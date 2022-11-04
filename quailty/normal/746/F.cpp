#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
const int MAXN=200005;
int a[MAXN],t[MAXN];
multiset<int>full,part;
int main()
{
    int n,w,k;
    scanf("%d%d%d",&n,&w,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),a[i]+=a[i-1];
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    int res=0;
    for(int l=1,r=0;l<=n;l++)
    {
        while(k>=0 && r<=n)if((++r)<=n)
        {
            k-=(t[r]+1)/2;
            part.insert(t[r]);
            while((int)part.size()>w)
            {
                k+=(*part.begin()+1)/2;
                k-=*part.begin();
                full.insert(*part.begin());
                part.erase(part.begin());
            }
        }
        res=max(res,a[r-1]-a[l-1]);
        if(full.find(t[l])!=full.end())
        {
            full.erase(full.find(t[l]));
            k+=t[l];
        }
        else
        {
            part.erase(part.find(t[l]));
            k+=(t[l]+1)/2;
            while((int)part.size()<w && !full.empty())
            {
                k+=*(--full.end());
                k-=(*(--full.end())+1)/2;
                part.insert(*(--full.end()));
                full.erase(--full.end());
            }
        }
    }
    return 0*printf("%d",res);
}