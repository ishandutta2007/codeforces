#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXN = 105;

int n;
int contacts[MAXN][MAXN];
vector <int> prediction;

int already[MAXN];
int come[MAXN];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < n; ++j) {
            contacts[i][j] = s[j] - '0';
        }
    }
        
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        prediction.puba(num);        
    }
    
    while (true) {
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (already[i] == prediction[i]) {
                for (int j = 0; j < n; ++j) {
                    already[j] += contacts[i][j];
                }
                come[i] = 1;
                flag = false;
                break;
            }
        }
        if (flag) {
            break;
        }
    }

    int ans = 0;

    for (int i = 0; i < n; ++i) {
        ans += come[i];
    }

    cout << ans << endl;
    for (int i = 0; i < n; ++i) {
        if (come[i]) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}