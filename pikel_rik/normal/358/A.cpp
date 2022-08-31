#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int flag = 0;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j + 1 < n; j++) {
            if (((a[j] > a[i-1] and a[j] < a[i]) and (a[j+1] < a[i-1] or a[j+1] > a[i])) or ((a[j+1] > a[i-1] and a[j+1] < a[i]) and (a[j] < a[i-1] or a[j] > a[i]))) {
                flag = 1;
                break;
            }
            if (((a[j] > a[i] and a[j] < a[i-1]) and (a[j+1] < a[i] or a[j+1] > a[i-1])) or ((a[j+1] > a[i] and a[j+1] < a[i-1]) and (a[j] < a[i] or a[j] > a[i-1]))) {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            break;
    }

    if (flag == 1)
        cout << "yes\n";
    else
        cout << "no\n";
    return 0;
}