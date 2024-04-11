#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const int MAXM=100005;
int sz;
struct query
{
    int l,r,id;
}q[MAXM];
bool cmp(query a,query b)
{
    if(a.l/sz==b.l/sz)return a.r<b.r;
    else return a.l/sz<b.l/sz;
}
int a[MAXN],mp[1<<20];
ll res[MAXN];
void work(int m,int k)
{
    ll now=0;
    int l=1,r=0;
    mp[a[l-1]]++;
    for(int i=0;i<m;i++)
    {
        while(r<q[i].r)
        {
            r++;
            now+=mp[a[r]^k];
            mp[a[r]]++;
        }
        while(l>q[i].l)
        {
            l--;
            now+=mp[a[l-1]^k];
            mp[a[l-1]]++;
        }
        while(r>q[i].r)
        {
            mp[a[r]]--;
            now-=mp[a[r]^k];
            r--;
        }
        while(l<q[i].l)
        {
            mp[a[l-1]]--;
            now-=mp[a[l-1]^k];
            l++;
        }
        res[q[i].id]=now;
    }
}
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    sz=(int)sqrt(n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        a[i]^=a[i-1];
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].id=i;
    }
    sort(q,q+m,cmp);
    work(m,k);
    for(int i=0;i<m;i++)
        printf("%I64d\n",res[i]);
    return 0;
}