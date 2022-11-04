#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int a[MAXN],go[MAXN],res[MAXN];
vector<pair<int,int> > vec[MAXN];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        vec[a[i]%m].push_back({a[i],i});
    for(int i=0;i<m;i++)
        go[i]=(int)vec[i].size()-n/m;
    for(int i=1;i<m;i++)
        go[i]+=go[i-1];
    int rig=0;
    for(int i=0;i<m;i++)
        rig=min(rig,go[i]);
    for(int i=0;i<m;i++)
        go[i]-=rig;
    long long res=0;
    for(int i=0;i<m;i++)
        res+=go[i];
    printf("%lld\n",res);
    int st=0;
    for(int i=0;i<m;i++)
        if(go[i]==0)st=(i+1)%m;
    int off=0;
    vector<pair<int,int> > scan;
    for(int i=0;i<m;i++)
    {
        while((int)scan.size()<go[st])
        {
            pair<int,int> t=vec[st].back();
            vec[st].pop_back();
            scan.push_back({t.first-off,t.second});
        }
        while((int)scan.size()>go[st])
        {
            pair<int,int> t=scan.back();
            scan.pop_back();
            vec[st].push_back({t.first+off,t.second});
        }
        off++,st=(st+1)%m;
    }
    for(int i=0;i<m;i++)
        for(auto &t:vec[i])
            a[t.second]=t.first;
    for(int i=1;i<=n;i++)
        printf("%d%c",a[i]," \n"[i==n]);
    return 0;
}