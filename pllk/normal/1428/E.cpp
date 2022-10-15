#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

int a[101010];
int c[101010];

ll what(ll n, ll k) {
    if (k > n) return 1e18;
    if (n%k == 0) return (n/k)*(n/k)*k;
    ll u = n/k;
    ll a = (u+1)*k-n;
    return (k-a)*(u+1)*(u+1)+a*u*u;
}

int main() {
    int n, k;
    cin >> n >> k;
    ll s = 0;
    set<pair<ll,int>> z;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[i] = 1;
        s += what(a[i],c[i]);
        z.insert({what(a[i],c[i])-what(a[i],c[i]+1),i});
    }
    while (n < k) {
        auto u = *z.rbegin();
        z.erase(u);
        int i = u.second;
        s -= what(a[i],c[i]);
        c[i]++;
        s += what(a[i],c[i]);
        z.insert({what(a[i],c[i])-what(a[i],c[i]+1),i});
        n++;
    }
    cout << s << "\n";
}