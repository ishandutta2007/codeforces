#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

int v[100];
bool f[100000];
vector <int> sol;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for(i = n; i >= 1; i--) {
        if(f[v[i]] == 0)
            sol.push_back(v[i]);
        f[v[i]] = 1;
    }
    cout << sol.size() << "\n";
    while(!sol.empty()) {
        cout << sol.back() << " ";
        sol.pop_back();
    }
    //cin.close();
    //cout.close();
    return 0;
}