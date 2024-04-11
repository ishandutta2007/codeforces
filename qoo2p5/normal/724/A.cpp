#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const ll INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld EPS = 1e-9;

map<string, int> d;
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int run() {
    d["monday"] = 0;
    d["tuesday"] = 1;
    d["wednesday"] = 2;
    d["thursday"] = 3;
    d["friday"] = 4;
    d["saturday"] = 5;
    d["sunday"] = 6;
    
    string a, b;
    cin >> a >> b;
    int aa = d[a];
    int bb = d[b];
    
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 11; j++) {
            int day1 = 0;
            for (int k = 0; k < j; k++) {
                day1 += days[k];
            }
            
            int x = (aa + i) % 7;
            int y = (bb + i) % 7;
            
            int day2 = day1 + days[j];
            
            if (day1 % 7 == x && day2 % 7 == y) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    
    cout << "NO\n";
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    return run();
}