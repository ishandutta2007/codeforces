#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n - k - 1; i++) cout << i + 1 << " ";
    for (int i = 0; i <= k; i++) cout << n - i << " ";
    return 0;
}