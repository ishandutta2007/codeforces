#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    vector<ll> v;
    for(ll i=3;i*i<=3e9;i+=2){
        v.push_back((i*i)/2 + 1);
    }
    while(t--){
        ll n;
        cin >> n;
        cout << lower_bound(v.begin(), v.end(), n + 1) - v.begin() << "\n";
    }
}