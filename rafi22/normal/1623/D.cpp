#include <bits/stdc++.h>

#define int long long
#define ll long long
#define ld long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;
struct S
{
    int x,y,dx,dy;
};
int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}

vector<int>odw[100007][3][3];

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
        int n,m,rx,ry,cx,cy,p;
        cin>>n>>m>>rx>>ry>>cx>>cy>>p;
        for(int i=1;i<=n;i++)
        {
            odw[i][0][0]=vector<int>(m+3,0);
            odw[i][0][2]=vector<int>(m+3,0);
            odw[i][2][0]=vector<int>(m+3,0);
            odw[i][2][2]=vector<int>(m+3,0);
        }
        p=p*pot(100,mod-2)%mod;
        int t=0,dx=1,dy=1,P=1;
        vector<pair<int,int>>V;
        while(true)
        {
            if(rx+dx>n||rx+dx<1) dx=-dx;
            if(ry+dy>m||ry+dy<1) dy=-dy;
            if(odw[rx][dx+1][dy+1][ry]) break;
            odw[rx][dx+1][dy+1][ry]=1;
            if(rx==cx||ry==cy)
            {
                V.pb({P*p%mod,t});
                P=P*(1-p+mod)%mod;
               // cout<<t<<endl;
            }
            t++;
            rx+=dx;
            ry+=dy;
        }
       // cout<<t<<endl;
        int e=0;
        for(auto x:V) e=(e+x.st*x.nd)%mod;
        cout<<(e+P*t)%mod*pot((1-P+mod)%mod,mod-2)%mod<<endl;
    }

    return 0;
}