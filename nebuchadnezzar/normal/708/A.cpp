#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1e5 + 5;

char s[MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%s", s);
    int n = strlen(s);

    int c = 0;
    while (c < n && s[c] == 'a') {
        ++c;
    }

    if (c == n) {
        s[n - 1] = 'z';
    } else {
        while (c < n && s[c] != 'a') {
            s[c] -= 1;
            ++c;
        }
    }

    cout << s << "\n";

    #ifdef LOCAL
        cerr << "time: " << clock() << endl;
    #endif
    return 0;
}