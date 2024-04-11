#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

int v[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
    }
    int y = -1;
    for(i = 1; i < n; i++) {
        if(v[i] < v[i + 1]) {
            if(v[i + 1] - v[i] > 1) {
                if(y == -1)
                    y = v[i + 1] - v[i];
                else if(y != v[i + 1] - v[i]) {
                    cout << "NO";
                    return 0;
                }
            }
        }
        else if(v[i] > v[i + 1]) {
            if(v[i] - v[i + 1] > 1) {
                if(y == -1)
                    y = v[i] - v[i + 1];
                else if(y != v[i] - v[i + 1]) {
                    cout << "NO";
                    return 0;
                }

            }
        }
        else {
            cout << "NO";
            return 0;
        }
    }
    if(y == -1) {
        y = 1;
    }
    if(y > 1) {
        int c = v[1] % y;
        int l = (v[1] - 1) / y + 1;
        if(c == 0)
            c = y;
        for(i = 2; i <= n; i++) {
            if(v[i] - v[i - 1] == 1) {
               c++;
            }
            else if(v[i] - v[i - 1] == -1) {
               c--;
            }
            else if(v[i] < v[i - 1]) {
                l--;
            }
            else {
                l++;
            }
            if(c < 1 || c > y || l < 1) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES" << "\n";
    cout << 1000000000 << " " << y;
    //cin.close();
    //cout.close();
    return 0;
}