#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int n;
int t[1010];
unordered_map<int,int> z;
set<pair<int,int>> q;
int r;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        z[x]++;
        t[i] = x;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            int a = t[i];
            int b = t[j];
            if (q.count({a,b})) continue;
            q.insert({a,b});
            unordered_map<int,int> u;
            u[a]++;
            u[b]++;
            if (u[a] > z[a]) continue;
            if (u[b] > z[b]) continue;
            int k = 2;
            while (true) {
                int c = a+b;
                a = b;
                b = c;
                if (u[c] < z[c]) {
                    u[c]++;
                    k++;
                } else {
                    break;
                }
            }
            r = max(r,k);
        }
    }
    cout << r << "\n";
}