#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;



bool ok(int u, int v)
{
    int bal = 0;
    while(u || v)
    {
        bal += u % 2;
        bal -= v % 2;
        if(bal < 0) return false;
        u /= 2;
        v/= 2;
    }
    return true;
}

void solve()
{
    int q; cin>>q;
    while(q--)
    {
        int x,y; cin>>x>>y;
        if(x <= y && ok(x,y)) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt = 1;
   // cin >> tt;
    while(tt--) solve();

    return 0;
}