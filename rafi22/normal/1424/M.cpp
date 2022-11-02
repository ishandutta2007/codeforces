#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int n,k;
int nr[1007];
string str[1000007];
vector <int> G[30];
int ile[30];
bool is[30];
vector <int> ans;
deque<int> kolejka;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        cin>>n>>k;
        int a;
        for(int i=1;i<=n;i++)
        {
            cin>>a;
            for(int j=1;j<=k;j++)
            {
                cin>>str[a*k+j];
                for(int l=0;l<str[a*k+j].size();l++)
                {
                    is[str[a*k+j][l]-97]=1;
                }
            }
        }
        for(int i=2;i<=n*k;i++)
        {
            bool r=0;
            for(int l=0;l<min(str[i].size(),str[i-1].size());l++)
            {
                if(str[i][l]!=str[i-1][l])
                {
                    r=1;
                    G[str[i-1][l]-97].pb(str[i][l]-97);
                    ile[str[i][l]-97]++;
                    break;
                }
            }
            if(!r&&str[i-1].size()>str[i].size())
            {
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
        for(int i=0;i<26;i++)
        {
            if(!ile[i])
            {
                kolejka.pb(i);
            }
        }
        while(!kolejka.empty())
        {
            int u=kolejka[0];
            kolejka.pop_front();
            ans.push_back(u);
            for(auto v:G[u])
            {
                ile[v]--;
                if(ile[v]==0) kolejka.pb(v);
            }
        }
        if(ans.size()!=26)
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
        for(int i=0;i<26;i++)
        {
            if(is[ans[i]]) cout<<(char)(ans[i]+97);
        }
    }

    return 0;
}