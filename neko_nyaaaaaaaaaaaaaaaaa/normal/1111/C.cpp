#include <bits/stdc++.h>
using namespace std;

int n, k, A, B;
vector<int> p;

long long divideAndDestroy(int l, int r) { // current base: [l ... r]
    
    /*if (l >= r) {
        return 0;
    } */

    // >= l, index of p
    int l_pos = lower_bound(p.begin(), p.end(), l) - p.begin();

    // > r. index of p
    int r_pos = upper_bound(p.begin(), p.end(), r) - 1 - p.begin(); // <= r

    // total damage
    long long total_damage = A;
    if (l_pos <= r_pos) {
        total_damage = 1LL * B * (r_pos - l_pos + 1) * (r - l + 1);
    }
    if (l == r) {
        return total_damage;
    }
    if (l_pos > r_pos) {
        return total_damage;
    }
    // l == r
    
    // two choices:
    // divide and destroy separately
    // destroy the entire thing

    // 1 -> 16
    // 1 -> 8 ; 9 -> 16
    // 9 -> 12 ; 13 -> 16

    int m = l + (r - l) / 2;
    return min(total_damage, divideAndDestroy(l, m) + divideAndDestroy(m + 1, r));
}

int main() { // Creative Snap

    // Input
	  cin >> n >> k >> A >> B;
    p = vector<int>(k);
    for (int i = 0; i < k; ++i) {
        cin >> p[i];
    }
    sort(p.begin(), p.end());

    // DC 
    cout << divideAndDestroy(1, 1 << n) << endl;

	return 0;
}