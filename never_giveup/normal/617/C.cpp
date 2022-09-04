#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

pair<ll, int> q[2000];

ll a[2000];

ll dist(ll x1, ll y1, ll x2, ll y2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main(){
    //ifstream cin("queries.in");
    //ofstream cout("queries.out");
    ios::sync_with_stdio(0);
    ll n, x1, x2, y1, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    for (int i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        a[i] = dist(x, y, x2, y2);
        q[i] = make_pair(dist(x, y, x1, y1), i);
    }
    sort(q, q + n);
    ll mx = 0, answer = 1e18;
    for (int i = n - 1; i >= 0; i--){
        answer = min(answer, mx + q[i].first);
        mx = max(mx, a[q[i].second]);
    }
    answer = min(answer, mx);
    cout << answer;
}