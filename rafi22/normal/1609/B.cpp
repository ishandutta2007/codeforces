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

const bool multi=0;

set<int>S;
int n;
string s;

void check(int i)
{
    if(i<1||i>n-2) return ;
    if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c') S.insert(i);
    else S.erase(i);
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
        S.clear();
        int q;
        cin>>n>>q;
        cin>>s;
        s='#'+s;
        for(int i=1;i<=n-2;i++) check(i);
        while(q--)
        {
            int p;
            char c;
            cin>>p>>c;
            s[p]=c;
            check(p-2);
            check(p-1);
            check(p);
            cout<<sz(S)<<endl;
        }
    }

    return 0;
}