#include <bits/stdc++.h>

using namespace std;

vector <int> G[200007];
int ojciec[200007];
int pre[200007];
int add[200007];
int post[200007];
bool odw[200007];
int counter=0;

void dfs(int v,int o)
{
    pre[v]=++counter;
    odw[v]=1;
    ojciec[v]=o;
    for(int i=0;i<G[v].size();i++)
    {
        if(!odw[G[v][i]]) dfs(G[v][i],v);
    }
    post[v]=counter;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,a,b,k,v,u;
    bool ok;
    cin>>n>>m;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1,0);
    vector <int > querry;
    set < int > events;
    map<int,int> mapa;
    for(int i=0;i<m;i++)
    {
        querry.clear();
        events.clear();
        mapa.clear();
        ok=0;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            cin>>a;
            querry.push_back(a);
        }
        for(int j=0;j<querry.size();j++)
        {
            if(querry[j]==1)
            {
                events.insert(pre[1]);
                mapa[pre[1]]++;
                events.insert(post[1]+1);
                mapa[post[1]+1]++;
            }
            else
            {
                events.insert(pre[ojciec[querry[j]]]);
                mapa[pre[ojciec[querry[j]]]]++;
                events.insert(post[ojciec[querry[j]]]+1);
                mapa[post[ojciec[querry[j]]]+1]--;
            }
        }
        int act=0,p;
        for(set<int>::iterator it=events.begin();it!=events.end();it++)
        {
            if(act==k) ok=1;
            act+=mapa[*it];
        }
        if(ok) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';


    }
    return 0;
}