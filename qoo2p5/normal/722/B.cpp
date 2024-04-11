#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const ll INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld EPS = 1e-9;

#define TASK ""

const int N = 1000;

int n;
int p[N];

const int C = 6;
char g[C] = {'a', 'e', 'i', 'o', 'u', 'y'};

int run() {
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }
    scanf("\n");
    
    for (int i = 0; i < n; i++) {
        string s;
        char tmp;
        scanf("%c", &tmp);
        while (tmp != '\n') {
            s += tmp;
            scanf("%c", &tmp);
        }
        int cur = 0;
        
        for (int i = 0; i < 6; i++) {
            int c = g[i];
            for (char t : s) {
                cur += t == c;
            }
        }
        
        if (cur != p[i]) {
            cout << "NO\n";
            return 0;
        }
    }
    
    cout << "YES\n";

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return run();
}