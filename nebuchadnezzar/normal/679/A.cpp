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

int sieve[200];
char s[5];

int main() {
    //freopen(TASK_NAME ".in", "r", stdin);
    //freopen(TASK_NAME ".out", "w", stdout);

    for (int i = 2; i < 200; ++i) {
        if (sieve[i]) {
            continue;
        }
        for (int j = 2 * i; j < 200; j += i) {
            sieve[j] = 1;
        }
    }

    int sum = 0;
    for (int i = 2; i < 50; ++i) {
        if (!sieve[i]) {
            cout << i << endl;
            scanf("%s", s);
            if (strcmp(s, "yes") == 0) {
                ++sum;
            }
        }
        if (!sieve[i] && i * i < 100) {
            cout << i * i << endl;
            scanf("%s", s);
            if (strcmp(s, "yes") == 0) {
                cout << "composite" << endl;
                return 0;
            }
        }
    }

    if (sum < 2) {
        cout << "prime" << endl;
    } else {
        cout << "composite" << endl;
    }

    return 0;
}