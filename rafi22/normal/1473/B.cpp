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

int a[100007];

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
        string s,t;
        cin>>s>>t;
        int g=__gcd(sz(s),sz(t));
        string s1="",s2="";
        for(int i=0;i<sz(t)/g;i++) s1+=s;
        for(int i=0;i<sz(s)/g;i++) s2+=t;
        if(s1==s2) cout<<s1<<endl;
        else cout<<-1<<endl;
    }

    return 0;
}