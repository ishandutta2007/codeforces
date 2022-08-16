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
const int N = 8e3;

int n, a[N];

bool isSpecial(int x) {
    int ptr1 = 0, ptr2 = 2;
    int sum = a[0] + a[1];

    if (sum == x)
        return true;

    while (ptr1 <= ptr2 and ptr2 < n) {
        while (ptr2 < n and sum < x) {
            sum += a[ptr2];
            ptr2 += 1;
        }
        if (ptr2 - ptr1 >= 2 and sum == x)
            return true;
        while (sum >= x) {
            sum -= a[ptr1];
            ptr1 += 1;
        }
        if (ptr2 - ptr1 >= 2 and sum == x)
            return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];

        if (n == 1) {
            cout << "0\n";
            continue;
        }

        multiset<int> s;
        for (int i = 0; i < n; i++) s.insert(a[i]);

        int c = 0;
        for (int i = 0; i < n; i++) {
            int sum = a[i];

            for (int j = i + 1; j < n; j++) {
                sum += a[j];
                if (s.find(sum) != s.end()) {
                    c += s.count(sum);
                    s.erase(sum);
                }
            }
        }

        cout << c << "\n";
    }
    return 0;
}