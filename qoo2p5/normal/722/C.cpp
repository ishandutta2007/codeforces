#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const ll INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld EPS = 1e-9;

#define TASK ""

const int N = (int) 1e5 + 123;

int n;
int a[N];
ll p[N];

ll get(int l, int r) {
    ll res = p[r];
    if (l > 0) {
        res -= p[l - 1];
    }
    
    return res;
}

int run() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        p[i] = a[i] + (i == 0 ? 0 : p[i - 1]);
    }
    
    multiset<ll> q;
    map<int, int> p;
    
    q.insert(get(0, n - 1));
    p[n - 1] = 0;
    
    for (int i = 0; i < n; i++) {
        int ind;
        cin >> ind;
        ind--;
        
        auto el = *p.lower_bound(ind);
        int right = el.first;
        int left = el.second;
        
        q.erase(q.find(get(left, right)));
        p.erase(left);
        
        p[ind - 1] = left;
        p[right] = ind + 1;
        q.insert(get(left, ind - 1));
        q.insert(get(ind + 1, right));
        
        
        cout << (q.size() == 0 ? 0 : *q.rbegin()) << "\n";
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return run();
}