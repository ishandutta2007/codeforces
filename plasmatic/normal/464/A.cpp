// ./a-no-to-palindromes.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 1001;
int N, P;
string s;

char mx;
void inc() {
    s[N-1]++;
    bool carry = false;
    for (auto i = N-1; i >= 0; i--) {
        if (carry) {
            s[i]++;
            carry = false;
        }
        if (s[i] > mx) {
            s[i] -= P;
            carry = true;
        }
    }
    if (carry) {
        cout << "NO\n";
        exit(0);
    }
}

bool check(string &s) {
    for (auto i = 0; i < N-1; i++) 
        if (s[i] == s[i+1])
            return false;
    for (auto i = 0; i < N-2; i++) 
        if (s[i] == s[i+2])
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> P >> s;
    mx = 'a'+P-1;

    for (auto i = N-1; i >= 0; i--) {
        for (auto st = s[i]+1; st <= mx; st++) {
            string t = s;
            t[i] = st;
            char p1 = t[i], p2 = i > 0 ? t[i-1] : 0;
            for (auto j = i+1; j < N; j++) {
                char c = 0;
                for (auto k = 'a'; k <= mx; k++) {
                    if (k != p1 && k != p2) {
                        c = k;
                        break;
                    }
                }
                if (!c) {
                    t = string(N, 'a');
                    break;
                }

                t[j] = c;
                p2 = p1;
                p1 = t[j];
            }

            if (check(t)) {
                cout << t << '\n';
                return 0;
            }
        }
    }
    cout << "NO\n";

    return 0;
}