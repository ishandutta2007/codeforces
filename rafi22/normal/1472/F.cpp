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

const bool multi=1;

bool DP[1000007][4];
bool tab[1000007][2];

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
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>>pole;
        pole.pb({n+1,0});
        pole.pb({n+1,1});
        pole.pb({0,0});
        pole.pb({0,1});
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            a--;
            pole.pb({b,a});
        }
        sort(pole.begin(),pole.end());
        int it=1;
        for(int i=0;i<sz(pole);i++)
        {
            tab[it][pole[i].nd]=1;
            if(i!=sz(pole)-1)
            {
                if((pole[i+1].st-pole[i].st)%2==0) it+=min(4LL,pole[i+1].st-pole[i].st);
                else it+=min(3LL,pole[i+1].st-pole[i].st);
            }
        }
        DP[0][3]=1;
        for(int i=1;i<=it;i++)
        {
            if(!tab[i][0]&&DP[i-1][2])
            {
                if(tab[i][1]) DP[i][3]=1;
                else DP[i][1]=1;
            }
            if(!tab[i][1]&&DP[i-1][1])
            {
                if(tab[i][0]) DP[i][3]=1;
                else DP[i][2]=1;
            }
            if(!tab[i][0]&&!tab[i][1]&&DP[i-1][3]) DP[i][3]=1;
            if(tab[i][0]&&tab[i][1]&&DP[i-1][3]) DP[i][3]=1;
            if(tab[i][0]&&!tab[i][1]&&DP[i-1][3]) DP[i][1]=1;
            if(!tab[i][0]&&tab[i][1]&&DP[i-1][3]) DP[i][2]=1;
        }
        if(DP[it][3]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        for(int i=1;i<=it;i++)
        {
            DP[i][1]=0;
            DP[i][2]=0;
            DP[i][3]=0;
            tab[i][0]=0;
            tab[i][1]=0;
        }
    }

    return 0;
}