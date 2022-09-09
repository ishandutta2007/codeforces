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
const int MAXN = 2e5 + 5;

int inp[MAXN], mem[MAXN];
int n;
int used[MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);

    int pos = -1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", inp + i);
        --inp[i];
        mem[i] = inp[i];
        if (inp[i] == i) {
            pos = i;
        }
    }

    fill(used, used + n, -1);

    if (pos == -1) {
        int now = 0;
        while (used[now] == -1) {
            used[now] = MAXN;
            now = inp[now];
        }
        inp[now] = now;
        pos = now;
    }

    for (int i = 0; i < n; ++i) {
        int now = i;
        while (used[now] == -1) {
            used[now] = i;
            now = inp[now];
        }
        if (used[now] == i) {
            inp[now] = pos;
        }
    }

    int diff = 0;

    for (int i = 0; i < n; ++i) {
        diff += (inp[i] != mem[i]);
    }

    cout << diff << "\n";
    for (int i = 0; i < n; ++i) {
        cout << inp[i] + 1 << " ";
    }
    cout << "\n";

    return 0;
}