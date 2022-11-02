#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int xd[4][4];
int pokor[4][4];
int ans=0;
vector<pair<int,int>>v;
set<vector<pair<int,int>>>S;

void bt(int i)
{
    if(i==3)
    {
        vector<pair<int,int>> t=v;
        sort(t.begin(),t.end());
        if(S.count(t)) return ;
        S.insert(t);
        int lol=0;
        if(abs(v[0].st-v[1].st)==2||abs(v[0].nd-v[1].nd)==2) lol+=2;
        if(abs(v[1].st-v[2].st)==2||abs(v[1].nd-v[2].nd)==2) lol+=2;
        if(abs(v[2].st-v[0].st)==2||abs(v[2].nd-v[0].nd)==2) lol+=2;
        if(lol%4==0)
        {
            int ways=1;
            memset(pokor,0,sizeof pokor);
            for(auto x:v) pokor[x.st][x.nd]++;
            for(int x=0; x<=2; x+=2)
            {
                for(int y=0; y<=2; y+=2)
                {
                    int ile=1;
                    for(int c=0;c<pokor[x][y];c++) ile*=xd[x][y]-c;
                    for(int c=1;c<=pokor[x][y];c++) ile/=c;
                    ways*=ile;
                }
            }
            ans+=ways;
        }
        return ;
    }
    for(int x=0;x<=2;x+=2)
    {
        for(int y=0;y<=2;y+=2)
        {
            v.pb({x,y});
            bt(i+1);
            v.pop_back();
        }
    }
}

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
        int n,x,y;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y;
            xd[x%4][y%4]++;
        }
        bt(0);
        cout<<ans;
    }

    return 0;
}