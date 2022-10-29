#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll query(ll x, ll y){
    cout << "? " << x << ' ' << y << endl;
    cin >> x;
    return x;
}
void answer(ll x1, ll x2, ll y1, ll y2){
    cout << "! " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    exit(0);
}
int main(){
    const ll MAX = 1e9;
    ll a = query(1, 1), b = query(MAX, 1), c = query(MAX, MAX), d = query(1, MAX);
    const ll y1 = 1 + query((a - b + MAX + 1) / 2, 1);
    const ll x1 = 1 + query(1, (a - d + MAX + 1) / 2);
    const ll y2 = MAX - query((d - c + MAX + 1) / 2, MAX);
    const ll x2 = MAX - query(MAX, (b - c + MAX + 1) / 2);
    answer(x1, x2, y1, y2);
}