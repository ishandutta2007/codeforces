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

    int n, k;
    cin >> n >> k;

    vi a(k);
    for (int i = 0; i < k; i++) cin >> a[i];

    int ptr = 1;
    vi visited(n * k + 1);

    for (int i : a) visited[i] = 1;

    for (int i = 0; i < k; i++) {
        cout << a[i] << " ";

        for (int j = 0; j < n - 1; j++) {
            while (visited[ptr] and ptr < n*k) ptr++;
            cout << ptr << " ";
            visited[ptr] = 1;
        }
        cout << "\n";
    }
    return 0;

}