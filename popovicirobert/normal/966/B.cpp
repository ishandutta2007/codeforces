#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 3e5;

pair <int, int> c[MAXN + 1];

inline void check(int x1, int x2, int n, bool t) {
    int i, last = -1;
    for(i = n; i >= 1; i--) {
        if(1LL * (n - i + 1) * c[i].first >= x2) {
            last = i;
            break;
        }
    }
    if(last == -1)
        return ;
    for(i = 1; i < last; i++) {
        int len = (x1 + c[i].first - 1) / c[i].first;
        if(i + len - 1 >= last)
            continue;
        cout << "Yes" << "\n";
        if(t == 0) {
            cout << last - i << " " << n - last + 1 << "\n";
            for(int j = i; j < last; j++) {
                cout << c[j].second << " ";
            }
            cout << "\n";
            for(int j = last; j <= n; j++) {
                cout << c[j].second << " ";
            }
        }
        else {
            cout << n - last + 1 << " " << last - i << "\n";
            for(int j = last; j <= n; j++) {
                cout << c[j].second << " ";
            }
            cout << "\n";
            for(int j = i; j < last; j++) {
                cout << c[j].second << " ";
            }
        }
        exit(0);
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x1, x2;
    ios::sync_with_stdio(false);
    cin >> n >> x1 >> x2;
    for(i = 1; i <= n; i++) {
        cin >> c[i].first;
        c[i].second = i;
    }
    sort(c + 1, c + n + 1);
    check(x1, x2, n, 0);
    check(x2, x1, n, 1);
    cout << "No";
    //cin.close();
    //cout.close();
    return 0;
}