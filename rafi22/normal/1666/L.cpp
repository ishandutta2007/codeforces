#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define ll long long
ll mod=1000000007;
int inf=1000000007;
ll infl=1000000000000000007;

const int N=200007;

vector<int>G[N];
bool was[N];
bool odw[N];
int o[N],o1[N];
int s;

vector<int>V;

void bfs(int p)
{
    deque<int>Q;
    Q.pb(p);
    odw[p]=1;
    while(sz(Q)>0)
    {
        int v=Q[0];
        Q.pop_front();
        if(v==s) continue;
        V.pb(v);
        if(was[v])
        {
            vector<int>ans,ans1;
            int x=v;
            while(x)
            {
                ans.pb(x);
                x=o[x];
            }
            x=v;
            while(x)
            {
                ans1.pb(x);
                x=o1[x];
            }
            reverse(all(ans));
            reverse(all(ans1));
            cout<<"Possible"<<endl;
            cout<<sz(ans)+1<<endl;
            cout<<s<<" ";
            for(auto x:ans) cout<<x<<" ";
            cout<<endl;
            cout<<sz(ans1)+1<<endl;
            cout<<s<<" ";
            for(auto x:ans1) cout<<x<<" ";
            cout<<endl;
            exit(0);
        }
        for(auto u:G[v])
        {
            if(!odw[u])
            {
                odw[u]=1;
                Q.pb(u);
                o1[u]=v;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,a,b;
    cin>>n>>m>>s;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        G[a].pb(b);
    }
    for(auto u:G[s])
    {
        V.clear();
        bfs(u);
        for(auto u:V)
        {
            odw[u]=0;
            was[u]=1;
            o[u]=o1[u];
            o1[u]=0;
        }
    }
    cout<<"Impossible";

    return 0;
}