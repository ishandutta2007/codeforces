#include <bits/stdc++.h>
using namespace std;

    seed_seq seq{
        (uint64_t) chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
        (uint64_t) __builtin_ia32_rdtsc(),
        (uint64_t) (uintptr_t) make_unique<char>().get()
    };
    mt19937 rng(seq);

int n,m,i,j,k,t,t1,u,v,a,b;
map<int,int> mp[100001];
vector<int> g;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (i=1;i<=m;i++)
    {
        cin>>u>>v;
        mp[u][v]=1;
        mp[v][u]=1;
    }
    for (i=1;i<=n;i++) g.push_back(i);
    for (j=1;j<=200;j++)
    {
        u=0;
        shuffle(g.begin(),g.end(),rng);
        for (i=0;i<m;i++) if (mp[g[i]][g[(i+1)%n]]) {u=1; break;}
        if (!u) break;
    }
    if (j==201) cout<<-1;
    else
    {
        for (i=0;i<m;i++) cout<<g[i]<<' '<<g[(i+1)%n]<<endl;
    }
}