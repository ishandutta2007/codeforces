#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME aplusb

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int MAXN = 1e4 + 5;

char s[MAXN];
int n;

int main() {        
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%s", s);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        --l; --r;
        /*
        cerr << l << " " << l + k % (r - l + 1) << " " << r + 1 << endl;
        for (int i = l; i <= r; ++i) {
            cerr << s[i];
        }
        cerr << endl;
        */
        rotate(s + l, s + r + 1 - k % (r - l + 1), s + r + 1);
        /*
        for (int i = l; i <= r; ++i) {
            cerr << s[i];
        }
        cerr << endl;
        */
    }

    int l = strlen(s);
    for (int i = 0; i < l; ++i) {
        printf("%c", s[i]);
    }
    printf("\n");

    return 0;
}