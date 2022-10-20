#include <bits/stdc++.h>
#define Task "C"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 1000010;

string s;
int n;
bool dd[N];
long long a, b;

int main() {
    ios_base::sync_with_stdio(0);
   // fi, fo;
    cin >> s;
    n = s.size();
    cin >> a >> b;
    long long  cur = 0, mu = 1 % b;
    for(int i = n - 1; i >= 0; i--) {
        cur = (((s[i] - '0') * mu) % b + cur) % b;
        mu = (mu * 10) % b;
        if(cur == 0) dd[i] = 1;
    }
    cur = 0;
    for(int i = 0; i < n - 1; i++) {
        cur = ((cur * 10) + (s[i] - '0')) % a;
        if(cur == 0 && dd[i + 1] && s[i + 1] != '0') {
            cout << "YES\n";
            for(int j = 0; j <= i; j++)
                cout << s[j];
            cout << endl;
            for(int j = i + 1; j < n; j++)
                cout << s[j];
            return 0;
        }
    }
    cout << "NO";

    return 0;
}