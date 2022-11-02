#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void print() {
    cout << -1;
    exit(0);
}

int main() { 
    ll n, k;
    cin >> n >> k;
    vector<ll> inp(k);
    for (auto &i : inp) cin >> i;
    stack<ll> s;
    s.push(n + 1);
    ll p = 0;
    for (ll i = 0; i < k; ++i) {
        while(s.size() > 0 && s.top() < inp[i]) {
            if (s.top() != p + 1) print();
            else {
                p = s.top();
                s.pop();
            }
        }
        s.push(inp[i]);
    } 
    for (auto i : inp) cout << i << ' ';
    vector<bool> arr(n + 1, 0);
    ll last = 0;
    for (auto i : inp) arr[i] = 1;
        while (s.size() > 0) {
            for (int i = s.top() - 1; i > last; --i) {
                if (arr[i]) continue;
                cout << i << ' ';
                arr[i] = true;
            }
        last = s.top();
        s.pop();
    }
    //system("pause");     
    return 0; 
}