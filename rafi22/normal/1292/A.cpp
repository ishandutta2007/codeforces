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

bool is[3][100007];

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
        int n,q;
        cin>>n>>q;
        set<int>zle;
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            is[x][y]=!is[x][y];
            if((is[1][y]&&is[2][y-1])||(is[2][y]&&is[1][y-1])||(is[2][y]&&is[1][y])) zle.insert(y);
            else zle.erase(y);
            if((is[1][y+1]&&is[2][y])||(is[2][y+1]&&is[1][y])||(is[2][y+1]&&is[1][y+1])) zle.insert(y+1);
            else zle.erase(y+1);
            if(zle.empty()) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }

    return 0;
}