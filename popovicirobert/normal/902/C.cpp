#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 2e5;

int cnt[MAXN + 1], sp[MAXN + 1];

int p1[MAXN + 1], p2[MAXN + 1];

int n;

inline void solve(int h) {
    int i, j;
    sp[0] = 1;
    for(i = 1; i <= h; i++) {
        sp[i] = sp[i - 1] + cnt[i];
    }
    for(i = 1; i <= h; i++) {
        for(j = sp[i - 1] + 1; j <= sp[i]; j++) {
            p1[j] = sp[i - 1];
        }
    }
    for(i = 1; i <= h; i++) {
        if(cnt[i - 1] == 1) {
            for(j = sp[i - 1] + 1; j <= sp[i]; j++) {
                p2[j] = sp[i - 1];
            }
        }
        else {
            for(j = sp[i - 1] + 1; j < sp[i]; j++) {
                p2[j] = sp[i - 1];
            }
            p2[j] = sp[i - 1] - 1;
        }
    }
    for(i = 1; i <= n; i++) {
        cout << p1[i] << " ";
    }
    cout << endl;
    for(i = 1; i <= n; i++) {
        cout << p2[i] << " ";
    }
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, x, h;
    ios::sync_with_stdio(false);
    cin >> h;
    for(i = 0; i <= h; i++) {
        cin >> cnt[i];
        n += cnt[i];
    }
    for(i = 1; i <= h; i++) {
        if(cnt[i - 1] > 1 && cnt[i] > 1) {
            cout << "ambiguous" << endl;
            solve(h);
            return 0;
        }
    }
    cout << "perfect";
    //cin.close();
    //cout.close();
    return 0;
}