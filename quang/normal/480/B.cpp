#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

int n, l, x, y;
int a[100100];
int flag = 0;

int Tim(int kc) {
    int cur = 1;
    for(int i = 1; i <= n; i++) {
        while(cur < n && a[i] + kc >= a[cur + 1])
            cur++;
        if(a[cur] == a[i] + kc) {
            if(flag == 1) {
                cout << 1 << endl;
                cout << a[i] + x;
                exit(0);
            }
            if(flag == 2) {
                if(a[i] - x >=0) {
                    cout << 1 << endl << a[i] - x;
                    exit(0);
                }
                if(a[cur] + x <= l) {
                    cout << 1 << endl << a[cur] + x;
                    exit(0);
                }
                continue;
            }
            return 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> n >> l >> x >> y;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int sl = 0;
    flag = 0;
    sl += Tim(x);
    sl += Tim(y);
    if(sl == 2) cout << 0;
    if(sl == 1) {
        cout << 1 << endl;
        if(Tim(x)) cout << y;
        else cout << x;
    }
    if(sl == 0) {
        flag = 1;
        Tim(x + y);
        flag = 2;
        Tim(y - x);
        cout << 2 << endl << x << " " << y;
    }
    return 0;
}