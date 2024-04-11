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

char s[20];
bool have[10];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    int n;
    scanf("%d", &n);

    scanf("%s", s);
    
    for (int i = 0; i < n; ++i) {
        have[s[i] - '0'] = true;
    }

    if ((have[1] || have[2] || have[3]) && (have[7] || have[9] || have[0]) && (have[1] || have[4] || have[7] || have[0]) && (have[3] || have[6] || have[9] || have[0])) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}