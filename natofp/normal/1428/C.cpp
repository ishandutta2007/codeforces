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
    string x; cin>>x;
    int n = x.length();
    for(int i=1;i<=n;i++) s[i] = x[i-1];

    int cntA = 0;
    int cntB = 0;
    int prefB = 0;
    int sufA = 0;
    for(int i=1;i<=n;i++)
    {
        if(s[i] == 'A') cntA++;
        else cntB++;
    }

    if(cntA == 0)
    {
        cout<<n%2<<"\n";
        return;
    }
    if(cntB == 0)
    {
        cout<<n<<"\n";
        return;
    }
    int bal = 0;
    int ans = 0;
    for(int i=n;i>=1;i--)
    {
        if(s[i] == 'B') bal--;
        else bal++;

        ans = max(ans,bal);
    }

    if(ans % 2 != n % 2) ans++;
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