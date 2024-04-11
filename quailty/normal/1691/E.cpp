#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int c[MAXN],l[MAXN],r[MAXN],usd[MAXN];
int init(int n)
{
    static int d[MAXN*2-5];
    for(int i=1;i<=n;i++)
        d[i*2-1]=l[i],d[i*2]=r[i];
    sort(d+1,d+2*n+1);
    int t=unique(d+1,d+2*n+1)-(d+1);
    for(int i=1;i<=n;i++)
    {
        l[i]=lower_bound(d+1,d+t+1,l[i])-d;
        r[i]=lower_bound(d+1,d+t+1,r[i])-d;
    }
    return t;
}
int filter_single(int n,int m)
{
    int res=0;
    static int cnt[MAXN*2-5];
    for(int c=0;c<2;c++)
    {
        for(int i=1;i<=m;i++)cnt[i]=0;
        for(int i=1;i<=n;i++)
            if(::c[i]==c)cnt[l[i]]++,cnt[r[i]+1]--;
        for(int i=1;i<=m;i++)cnt[i]+=cnt[i-1];
        for(int i=1;i<=m;i++)cnt[i]=(cnt[i]>0)+cnt[i-1];
        for(int i=1;i<=n;i++)
            if(::c[i]!=c && cnt[r[i]]==cnt[l[i]-1])
                res++,usd[i]=1;
    }
    return res;
}
bool cmp(int x,int y)
{
    return l[x]==l[y] ? r[x]>r[y] : l[x]<l[y];
}
void filter_contain(int n)
{
    for(int c=0;c<2;c++)
    {
        vector<int> idx;
        for(int i=1;i<=n;i++)
            if(::c[i]==c && !usd[i])
                idx.push_back(i);
        sort(idx.begin(),idx.end(),cmp);
        int rig=0;
        for(size_t i=0;i<idx.size();i++)
        {
            if(r[idx[i]]<=rig)usd[idx[i]]=1;
            rig=max(rig,r[idx[i]]);
        }
    }
}
int cal(int n)
{
    vector<int> red,blue;
    for(int i=1;i<=n;i++)
    {
        if(usd[i])continue;
        if(c[i]==0)red.push_back(i);
        else blue.push_back(i);
    }
    sort(red.begin(),red.end(),cmp);
    sort(blue.begin(),blue.end(),cmp);
    auto check=[](int x,int y){
        return r[x]>=l[y] && r[y]>=l[x];
    };
    int res=0;
    size_t i=0,j=0;
    while(i<red.size() && j<blue.size())
    {
        if(i+1<red.size() && check(red[i+1],blue[j]))
        {
            i++;
            continue;
        }
        if(j+1<blue.size() && check(red[i],blue[j+1]))
        {
            j++;
            continue;
        }
        i++,j++,res++;
    }
    return res;
}
int solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d%d",&c[i],&l[i],&r[i]),usd[i]=0;
    int res=filter_single(n,init(n));
    filter_contain(n);
    return 0*printf("%d\n",res+cal(n));
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}