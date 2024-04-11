#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair

using namespace std;

const int nax = 3e5 + 5;

char s[nax];

void solve()
{
    int n; cin>>n;
    string x; cin>>x;
    for(int i=0;i<n;i++) s[i] = x[i];

    bool circ = false;
    bool ok = true;
    for(int i=0;i<n;i++)
    {
        if(s[i] == '<') ok = false;
    }
    if(ok) circ = true;
    ok = true;
    for(int i=0;i<n;i++)
    {
        if(s[i] == '>') ok = false;
    }
    if(ok) circ = true;


    int ans = n;
    if(circ == false)
    {
        ans = 0;
        for(int i=0;i<n;i++)
        {
            int cur = i;
            int pop = i + 1;
            pop %= n;
            if(s[cur] == '-' || s[pop] =='-') ans++;
        }
    }
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