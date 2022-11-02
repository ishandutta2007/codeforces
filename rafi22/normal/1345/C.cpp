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

const bool multi=1;

map <int,bool> mapa;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    if(multi)
        cin>>t;
    else t=1;
    while(t--)
    {
        mapa.clear();
        int n,a;
        cin>>n;
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            cin>>a;
            if(mapa[((a+i)%n+inf)%n]) ok=0;
            else mapa[((a+i)%n+inf)%n]=1;
        }
        if(ok) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}