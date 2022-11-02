#include <bits/stdc++.h>

using namespace std;

vector <int> G[100007];
bool odw[100007];
int ile[100007];
int ans[100007];
deque <int> kolejka;
int cost=0;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,a,b;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
        ile[a]++;
        ile[b]++;
    }
    for(int i=1;i<=n;i++) ans[i]=i;
    for(int i=1;i<=n;i++) if(G[i].size()==1) kolejka.push_back(i);
    while(!kolejka.empty())
    {
        int u=kolejka[0];
        kolejka.pop_front();
        int p=-1;
        for(auto v:G[u])
        {
            if(!odw[v]) p=v;
        }
        if(p==-1)
        {
            if(ans[u]==u)
            {
                cost+=2;
                swap(ans[u],ans[G[u][0]]);
            }
        }
        else
        {
            if(ans[u]==u)
            {
                cost+=2;
                swap(ans[u],ans[p]);
            }
            ile[p]--;
            if(ile[p]==1)
            {
                kolejka.push_back(p);
            }
        }
        odw[u]=1;

    }
    cout<<cost<<endl;
    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    return 0;
}