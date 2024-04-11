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
    int w,h,n; cin>>w>>h>>n;
    int ile1 = 1;
    int ile2 = 1;
    while(w % 2 == 0)
    {
        w /= 2;
        ile1 *= 2;
    }
    while(h % 2 == 0)
    {
        h /= 2;
        ile2 *= 2;
    }
    if(ile1 * ile2 >= n) cout<<"YES"<<"\n";
    else cout<<"NO"<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tt = 1;
    cin>>tt;
    while(tt--) solve();

    return 0;
}