#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
struct leg
{
    int l,d;
}a[100005];
int s[100005],sum;
vector<int>e[205];
map<int,int>cnt;
map<int,int>::iterator itr;
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i].l);
    for(int i=1;i<=n;i++)scanf("%d",&a[i].d);
    for(int i=1;i<=n;i++)
    {
        cnt[a[i].l]++;
        s[a[i].l]+=a[i].d;
        sum+=a[i].d;
        e[a[i].d].push_back(a[i].l);
    }
    for(int i=1;i<=200;i++)
    {
        sort(e[i].begin(),e[i].end());
    }
    int ans=0x3f3f3f3f;
    for(itr=cnt.begin();itr!=cnt.end();itr++)
    {
        int l=(*itr).first;
        int leg=(*itr).second;
        int res=s[l];
        int all=leg;
        for(int i=200;i>=1;i--)
        {
            int loc=lower_bound(e[i].begin(),e[i].end(),l)-e[i].begin();
            res+=loc*i;
            all+=loc;
            if(all>=2*leg)
            {
                res-=(all-2*leg+1)*i;
                break;
            }
        }
        ans=min(ans,sum-res);
    }
    printf("%d\n",ans);
    return 0;
}