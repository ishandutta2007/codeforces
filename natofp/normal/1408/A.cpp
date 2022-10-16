#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define pii pair<int,int>

using namespace std;

const int nax = 105;
int a[nax];
int b[nax];
int c[nax];


void solve()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cin>>c[i];

    int p = -1;
    int fi = -1;
    for(int i=1;i<=n;i++)
    {
        int akt = -1;
        if(a[i] != p && a[i] != fi)
        {
            akt = a[i];
        }
        else if(b[i] != p && b[i] != fi) akt = b[i];
        else akt = c[i];
        cout<<akt<<" ";
        p = akt;
        if(i == 1) fi = akt;
    }
    cout<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int t; cin>>t;
    while(t--) solve();

    return 0;
}