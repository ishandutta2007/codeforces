#include <bits/stdc++.h>
#define ll long long int

using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin>>q;
    while(q--)
    {
        ll n,k; cin>>n>>k;
        ll ile=n/k;
        ll wyn=ile*k+k/2;
        cout<<min(n,wyn)<<"\n";
    }
    return 0;
}