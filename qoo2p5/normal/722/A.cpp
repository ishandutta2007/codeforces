#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const ll INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld EPS = 1e-9;

#define TASK ""

int diff(string a, string b) {
    if (a.size() > b.size()) {
        swap(a, b);
    }
    
    while (a.size() < b.size()) {
        a = "0" + a;
    }
    
    int r = 0;
    
    for (int i = 0; i < (int) a.size(); i++) {
        r += a[i] != b[i];
    }
    
    return r;
}

int run() {
    int type;
    int hh, mm;
    scanf("%d\n%d:%d", &type, &hh, &mm);
    
    string h = to_string(hh);
    
    string m = to_string(mm);
    
    int ans = INF;
    string best_h, best_m;
    
    if (type == 12) {
        for (int a = 1; a <= 12; a++) {
            for (int b = 0; b <= 59; b++) {
                int cur = diff(to_string(a), h) + diff(to_string(b), m);
                if (cur < ans) {
                    ans = cur;
                    best_h = to_string(a);
                    best_m = to_string(b);
                }
            }
        }
    } else if (type == 24) {
        for (int a = 0; a <= 23; a++) {
            for (int b = 0; b <= 59; b++) {
                int cur = diff(to_string(a), h) + diff(to_string(b), m);
                if (cur < ans) {
                    ans = cur;
                    best_h = to_string(a);
                    best_m = to_string(b);
                }
            }
        }
    }
    
    while ((int) best_h.size() < 2) {
        best_h = "0" + best_h;
    }
    
    while ((int) best_m.size() < 2) {
        best_m = "0" + best_m;
    }
    
    cout << best_h << ":" << best_m << "\n";

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    return run();
}