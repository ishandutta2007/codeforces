#include <iostream>
#include <vector>
#include <algorithm>

#define N 500

using namespace std;

typedef long long ll;

int n, q;
ll power[202020];
ll sum[202020/N+5];
vector<ll> wish[202020/N+5];

void check() {
    ll cur = 0;
    for (int i = 0; i < n/N+1; i++) {
        if (binary_search(wish[i].begin(),wish[i].end(),cur)) {
            for (int j = i*N; ; j++) {
                if (power[j] == cur) {
                    cout << j+1 << "\n";
                    return;
                }
                cur += power[j];
            }
        }
        cur += sum[i];
    }
    cout << "-1\n";
}

void update(int pos, int val) {
    power[pos] = val;
    int z = pos/N;
    int a = z*N;
    int b = min(n-1,a+N-1);
    wish[z].clear();
    sum[z] = 0;
    for (int i = a; i <= b; i++) {
        if (power[i]-sum[z] >= 0) wish[z].push_back(power[i]-sum[z]);
        sum[z] += power[i];
    }
    sort(wish[z].begin(),wish[z].end());
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    ll part = 0;
    for (int i = 0; i < n; i++) {
        cin >> power[i];
        sum[i/N] += power[i];
        if (i%N == 0) part = 0;
        if (power[i]-part >= 0) wish[i/N].push_back(power[i]-part);
        part += power[i];
    }
    for (int i = 0; i < n/N+1; i++) sort(wish[i].begin(),wish[i].end());
    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        update(a,b);
        check();
    }
}