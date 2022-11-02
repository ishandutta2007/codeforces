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
        int n,m,rx,ry,cx,cy;
        cin>>n>>m>>rx>>ry>>cx>>cy;
        int c=0;
        int dx=1,dy=1;
        while(true)
        {
            if(rx==cx||ry==cy) break;
            c++;
            if(rx+dx>n||rx+dx<1) dx=-dx;
            if(ry+dy>m||ry+dy<1) dy=-dy;
            rx+=dx;
            ry+=dy;
        }
        cout<<c<<endl;
    }

    return 0;
}