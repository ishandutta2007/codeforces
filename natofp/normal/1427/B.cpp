#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair

using namespace std;

const int nax = 1e5 + 5;
char s[nax];

void solve()
{
    int n,k; cin>>n>>k;
    string x; cin>>x;
    for(int i=1;i<=n;i++) s[i] = x[i-1];

    int won = 0;
    for(int i=1;i<=n;i++) won += (s[i] == 'W');
    if(won + k >= n)
    {
        cout<<2 * n - 1<<"\n";
        return;
    }

    vector<int> lens;
    int cur = 0;

    int fi = n + 5;
    int last = 0;
    for(int i=1;i<=n;i++)
    {
        if(s[i] == 'W') last = i;
    }
    for(int i=n;i>=1;i--)
    {
        if(s[i] == 'W') fi = i;
    }
    int xd = 0;
    for(int i=1;i<=n;i++)
    {
        xd += (s[i] == 'W');
    }
    if(xd == 0)
    {
        cout<<max(0,2*k-1)<<"\n";
        return;
    }


    for(int i=fi;i<=last;i++)
    {
        if(s[i] == 'L') cur++;
        else
        {
            if(cur)
            {
                lens.pb(cur);
                cur = 0;
            }
        }
    }
    if(cur > 0) lens.pb(cur);

    int groups = lens.size() + 1;
    sort(lens.begin(),lens.end());
    int ok = 0;
    int tmp = k;
    for(int i=0;i<lens.size();i++)
    {
        if(tmp >= lens[i])
        {
            tmp -= lens[i];
            ok++;
        }
    }

    cout<<(won + k) * 2 - (groups - ok)<<"\n";

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