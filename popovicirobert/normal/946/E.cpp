#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

char str[MAXN + 1];

int fr[10];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int t, i, j, dig;
    ios::sync_with_stdio(false);
    cin >> t;
    while(t > 0) {
        t--;
        memset(fr, 0, sizeof(fr));
        cin >> (str + 1);
        int n = strlen(str + 1);
        for(i = 1; i <= n; i++) {
            str[i] -= '0';
            fr[str[i]] ^= 1;
        }
        bool ok = 0;
        for(int len = n; len >= 1 && !ok; len--) {
            dig = 0;
            if(len == 1)
                dig = 1;
            fr[str[len]] ^= 1;
            for(i = str[len] - 1; i >= dig && !ok; i--) {
                fr[i] ^= 1;
                int cnt = 0;
                for(j = 0; j < 10; j++) {
                    cnt += fr[j];
                }
                if(len + cnt <= n && (n - len - cnt) % 2 == 0) {
                    str[len] = i;
                    for(j = len + 1; j <= n - cnt; j++) {
                        str[j] = 9;
                    }
                    int p = 9;
                    for(j = n - cnt + 1; j <= n; j++) {
                        while(fr[p] == 0) {
                            p--;
                        }
                        str[j] = p;
                        fr[p] ^= 1;
                    }
                    ok = 1;
                }
                fr[i] ^= 1;
            }
        }
        if(!ok) {
            for(i = 1; i <= n - 2; i++) {
                cout << 9;
            }
        }
        else {
            for(i = 1; i <= n; i++) {
                cout << (int) str[i];
            }
        }
        cout << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}