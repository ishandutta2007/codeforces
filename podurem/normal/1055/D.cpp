#include <bits/stdc++.h>
#define err(...) //fprintf(stderr, __VA_ARGS__), fflush(stderr)
typedef long long ll;
 
using namespace std;

#define TASK ""

int solve();
int main() {
    #ifndef PoDuReM 
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        if (TASK == "input") {
            freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
        } else if (TASK != "") {
            freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
        }
    #endif
    return solve();
}

const int dd = (int)1e5 + 7;

struct Pref {
    int T[dd];
    char C[dd];
    int sz = 0;

    int add(char c) {
        if (sz == 0) {
            T[sz] = 0;
            C[sz++] = c;
            return 0;
        }
        C[sz] = c;
        int j = T[sz - 1];
        int i = sz;
        while (j > 0 && C[i] != C[j]) {
            j = T[j - 1];
        }
        j += (C[i] == C[j]);
        return T[sz++] = j;
    }
} P;

int L[dd], R[dd];

int solve() {
    int n;
    cin >> n;
    vector<string> A(n), B(n);
    for (auto &i : A) {
        cin >> i;
    }
    for (auto &i : B) {
        cin >> i;
    }
    vector<int> kok(n, 0);
    int PP = -1;
    for (int i = 0; i < n; ++i) {
        if (A[i] == B[i]) {
            continue;
        }
        PP = i;
        kok[i] = 1;
        int j = 0;
        while (A[i][j] == B[i][j]) ++j;
        int jEnd = (int)A[i].size() - 1;
        while (A[i][jEnd] == B[i][jEnd]) --jEnd;

        L[i] = j, R[i] = jEnd;
    }

    set<int> H;
    for (int i = 0; i < n; ++i) if (kok[i]) {
        H.insert(R[i] - L[i]);
    }
    if (H.size() > 1) {
        cout << "NO\n";
        return 0;
    }

    while (1) {
        bool ok = true;
        bool ok2 = true;
        for (int i = 0; i < n; ++i) if (kok[i]) {
            if (L[i] == 0) {
                ok2 = false;
                break;
            }
            if (A[i][L[i] - 1] != A[PP][L[PP] - 1] || B[i][L[i] - 1] != B[PP][L[PP] - 1]) {
                ok2 = false;
                break;
            }
        }

        if (ok2) {
            ok = false;
            for (int i = 0; i < n; ++i) if (kok[i]) {
                --L[i];
            }
            continue;
        }

        ok2 = true;
        for (int i = 0; i < n; ++i) if (kok[i]) {
            if (R[i] == (int)A[i].size() - 1) {
                ok2 = false;
                break;
            }
            if (A[i][R[i] + 1] != A[PP][R[PP] + 1] || B[i][R[i] + 1] != B[PP][R[PP] + 1]) {
                ok2 = false;
                break;
            }
        }

        if (ok2) {
            ok = false;
            for (int i = 0; i < n; ++i) if (kok[i]) {
                ++R[i];
            }
            continue;
        }

        if (ok) {
            break;
        }
    }

    string s = string(A[PP].begin() + L[PP], A[PP].begin() + R[PP] + 1);
    string t = string(B[PP].begin() + L[PP], B[PP].begin() + R[PP] + 1);

    for (char c : s) {
        P.add(c);
    }
    P.add('#');

    for (int i = 0; i < n; ++i) {
        int k = -1;
        for (int j = 0; j < (int)A[i].size(); ++j) {
            if (P.add(A[i][j]) == (int)s.size()) {
                k = j;
                break;
            }
        }
        if (k != -1) for (int l = 0; l < (int)s.size(); ++l) {
            A[i][k - l] = t[(int)s.size() - l - 1];
        }
        err("%d : %s  ->  %s\n", i, A[i].c_str(), B[i].c_str());
        if (A[i] != B[i]) {
            cout << "NO\n";
            return 0;
        }
        P.sz = (int)s.size() + 1;
    }
    cout << "YES\n" << s << "\n" << t << "\n";
    return 0;
}