#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

string s;
int m, d = 0, tr, L, R;
int a[20];
bool flag = 0;

bool check() {
    for(int i = 2; i <= m; i++) {
        int kc = abs(L - R);
        int vt = upper_bound(a, a + d + 2, kc) - a;
        while(vt == tr) vt++;
        if(vt > d) return 0;
        if(flag) cout << " " << a[vt];
        if(i % 2) L += a[vt];
        else R += a[vt];
        tr = vt;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> s;
    cin >> m;
    for(int i = 0; i < (int)s.size(); i++)
        if(s[i] == '1') a[++d] = i + 1;
    a[d + 1] = 20;
    for(int i = 1; i <= d; i++) {
        L = a[i], R = 0, tr = i;
        if(check()) {
            flag = 1;
            L = a[i], R = 0, tr = i;
            cout << "YES\n" <<  a[i];
            check();
            return 0;
        }
    }
    cout << "NO";
    return 0;
}