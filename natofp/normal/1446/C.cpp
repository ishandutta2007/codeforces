#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>

using namespace std;

int go(vector<int> a,int lvl)
{
    if(a.size() == 0) return 0;
    vector<int> b;
    vector<int> c;
    for(int x : a)
    {
        if(x & (1<<lvl)) c.pb(x);
        else b.pb(x);
    }

    if(lvl == 0) return b.size() + c.size();

    if(b.size() == 0) return go(c,lvl-1);
    if(c.size() == 0) return go(b,lvl-1);

    return 1 + max(go(b,lvl-1),go(c,lvl-1));

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> a;
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        a.pb(x);
    }

    cout<<n-go(a,29);

    return 0;
}