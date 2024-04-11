#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;



void solve()
{
    int n; cin>>n;
    vector<int> a;
    int s = 0;
    bool ok = false;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        a.pb(x);
        s += x;
        if(x == 1) ok = true;
    }

    if(s%2!=0) cout<<"NO"<<"\n";
    else
    {
        s /= 2;
        if(s % 2 == 0)
        {
            cout<<"YES"<<"\n";
        }
        else
        {
            if(ok) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
    }



}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin>>tt;
    while(tt--) solve();

    return 0;
}