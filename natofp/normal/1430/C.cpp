#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair

using namespace std;

vector<pii> ans;
int n;

void go(int n)
{
    if(n == 2)
    {
        ans.pb(mp(1,3));
        return;
    }

    ans.pb(mp(n-1,n+1));
    go(n-1);
}

void solve()
{
    cin>>n;
    ans.clear();
    if(n == 2)
    {
        ans.pb(mp(1,2));
        return;
    }
    if(n == 3)
    {
        ans.pb(mp(2,3));
        ans.pb(mp(1,3));
        return;
    }
    ans.pb(mp(n-2,n));
    ans.pb(mp(n-1,n-1));
    go(n-2);
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        solve();
        cout<<2<<"\n";
        for(auto akt : ans) cout<<akt.st<<" "<<akt.nd<<"\n";
    }

    return 0;
}