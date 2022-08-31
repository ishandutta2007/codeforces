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

    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));

    int m;
    cin >> m;

    vi b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(all(b));

    a.push_back(inf); b.push_back(inf);
    int ptr1 = 0, ptr2 = 0;

    int d = 0;
    int best_a = 3 * (a.size() - 1), best_b = 3 * (b.size() - 1);
    int cur_a = best_a, cur_b = best_b;

    while (ptr1 < a.size() - 1 or ptr2 < b.size() - 1) {
        if (a[ptr1] < b[ptr2]) {
            ptr1 += 1;
            cur_a -= 1;
//            cur_b = 2 * ptr2 + 3 * (b.size() - 1 - ptr2);
        }
        else if (a[ptr1] > b[ptr2]) {
            ptr2 += 1;
//            cur_a = 2 * ptr1 + 3 * (a.size() - 1 - ptr1);
            cur_b -= 1;
        }
        else {
            int temp = a[ptr1];

            while (a[ptr1] == temp) {
                cur_a -= 1;
                ptr1 += 1;
            }
            temp = b[ptr2];

            while (b[ptr2] == temp) {
                cur_b -= 1;
                ptr2 += 1;
            }
        }

        if (cur_a - cur_b > best_a - best_b) {
            best_a = cur_a;
            best_b = cur_b;
        }
        else if (cur_a - cur_b == best_a - best_b and cur_a > best_a) {
            best_a = cur_a;
            best_b = cur_b;
        }
    }

    cout << best_a << ":" << best_b << "\n";
    return 0;
}