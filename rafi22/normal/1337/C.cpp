#include <bits/stdc++.h>

using namespace std;

vector<long long>G[200007];
priority_queue< pair<long long ,long long> > kolejka;
long long ojciec[200007];
long long stopien[200007];
long long rozmiar[200007];
long long ile[200007];
void dfs(long long v,long long o,long long s)
{
    ojciec[v]=o;
    stopien[v]=s;
    for(long long i=0;i<G[v].size();i++)
    {
        if(ojciec[G[v][i]]==0)
        {
            dfs(G[v][i],v,s+1);
            rozmiar[v]+=rozmiar[G[v][i]]+1;
        }
    }
}


int main()
{
    long long n,k,a,b;
    cin>>n>>k;

    for(long long i=0;i<n-1;i++)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1,-1,0);
    long long ans=0;
    for(long long i=1;i<=n;i++)
    {
        ile[i]=G[i].size();
        kolejka.push(make_pair(stopien[i]-rozmiar[i],i));
    }
    long long p;
    while(!kolejka.empty()&&k>0)
    {

        k--;
        p=kolejka.top().second;
        //cout<<p<<endl;
        ans+=stopien[p];
        ans-=rozmiar[p];
        kolejka.pop();
    }
    cout<<ans;
    return 0;
}