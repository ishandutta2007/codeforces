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

string a[100007];

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
        int n;
        cin>>n;
        set<string>S,S1;
        bool ans=0;
        for(int i=1;i<=n;i++)
        {
            string s,x;
            cin>>s;
            x=s;
            reverse(all(x));
            if(S1.count(x)) ans=1;
            S.insert(x);
            if(S.count(s)) ans=1;
            if(sz(s)==3)
            {
                x="";
                x+=s[0];
                x+=s[1];
                S1.insert(x);
                x="";
                x+=s[1];
                x+=s[2];
                if(S.count(x)) ans=1;
            }
        }
        if(ans) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}