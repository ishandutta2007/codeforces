#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair

using namespace std;

const int nax = 2e5 + 5;
char s[nax];

void solve()
{
    int n; cin>>n;
    string x; cin>>x;
    for(int i=1;i<=n;i++) s[i] = x[i-1];
    vector<int> lens;
    int cur = 1;
    for(int i=2;i<=n;i++)
    {
        if(s[i] == s[i-1]) cur++;
        else
        {
            lens.pb(cur);
            cur = 1;
        }
    }
    if(cur) lens.pb(cur);
    int ans = 0;
    int wsk = 0;
    int akt = 0;
    int sz = lens.size();
    while(1)
    {
        wsk = max(wsk,akt);
        if(wsk > sz - 1) break;
        while(wsk < sz - 1 && lens[wsk] == 1)
        {
            wsk++;
        }
        if(wsk == sz - 1 && lens[wsk] == 1) break;
        lens[wsk]--;
        ans++;
        akt++;
        if(akt == n) break;
    }

    int ile = sz - akt;

    ans += (ile + 1) / 2;
    cout<<ans<<"\n";


}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}