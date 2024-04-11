// NOT MY CODE

#include<bits/stdc++.h>
using namespace std;
int n,m,T,ans,sum;
pair<int,int>a[20];
vector<pair<int,int>>v,l,sol,ts;
bool dfs(int p)
{
    int mx=-1,fe=0;
    for(int i=0;i<v.size();i++)
    {
        mx++;
        fe+=max(0,mx-v[i].first);
        mx=max(mx,v[i].first);
    }
    if(fe>sum)return 0;
    if(p==l.size())return 1;
    else
    {
        for(int i=1;i<v.size();i++)
        {
            v[i].first+=l[p].first;
            sum-=l[p].first;
            if(dfs(p+1))
            {
                ts.push_back({l[p].second,v[i].second});
                return 1;
            }
            v[i].first-=l[p].first;
            sum+=l[p].first;
        }
        return 0;
    }
}
struct vector_hash
{
    inline size_t operator()(const vector<int> & p) const 
    {
        size_t res=0,d=1;
        for(int x:p)res+=x*d,d*=17;
        return res;
    }
};
unordered_set<vector<int>,vector_hash>st;
bool cmp(pair<int,int>x,pair<int,int>y)
{
    return x.second<y.second;
}
void cal(int state)
{
    sum=0;
    v.clear(),l.clear(),ts.clear();
    vector<int>pb;
    for(int i=0;i<n;i++)
    {
        if((1<<i)&state)v.push_back({a[i].first,a[i].second+1});
        else l.push_back({a[i].first,a[i].second+1}),sum+=a[i].first;
    }
    if(ans<=l.size())return;
    sort(v.begin(),v.end(),cmp);
    for(auto x:v)pb.push_back(x.first);
    if(st.count(pb))return;
    else st.insert(pb);
    sort(l.begin(),l.end(),greater<pair<int,int>>());
    if(dfs(0))
    {
        if(ans>l.size())
        {
            ans=l.size();
            sol=ts;
        }
    }
}
vector<pair<int,int>> change(vector<pair<int,int>>v)
{
    bool f[20];
    for(int i=1;i<=n;i++)f[i]=1;
    vector<pair<int,int>>res;
    for(auto d:v)
    {
        int l=0;
        for(int i=1;i<=d.first;i++)l+=f[i];
        int r=0;
        for(int i=1;i<=d.second;i++)r+=f[i];
        res.push_back({l,r});
        f[d.first]=0;
    }
    return res;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        st.clear(),sol.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&a[i].first),a[i].second=i;
        sort(a,a+n);
        ans=n-1;
        for(int i=2;i<=n;i++)sol.push_back({i,1});
        for(int i=1;i<(1<<n);i++)cal(i);
        printf("%d\n",ans);
        sol=change(sol);
        for(auto d:sol)printf("%d %d\n",d.first,d.second);
    }
    return 0;
}