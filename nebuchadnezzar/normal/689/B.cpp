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

int n;
bool used[MAXN];
int dist[MAXN];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    scanf("%d", &n);

    vector<int> inp;
    for (int i = 0; i < n; ++i) {
        int num;
        scanf("%d", &num);
        --num;
        inp.puba(num);
    }

    queue<int> q;
    q.push(0);
    used[0] = true;

    while (szof(q)) {
        int p = q.front();
        q.pop();
        if (p > 0 && !used[p - 1]) {
            dist[p - 1] = dist[p] + 1;
            q.push(p - 1);
            used[p - 1] = true;
        }
        
        if (p < n - 1 && !used[p + 1]) {
            dist[p + 1] = dist[p] + 1;
            q.push(p + 1);
            used[p + 1] = true;
        }

        if (!used[inp[p]]) {
            dist[inp[p]] = dist[p] + 1;
            q.push(inp[p]);
            used[inp[p]] = true;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << dist[i] << " ";
    }
    cout << "\n";

    return 0;
}