#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & (-x))


using namespace std;

vector <int> sol;

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 2; i <= n; i += 2)
        sol.push_back(i);
    for(i = 1; i <= n; i += 2)
        sol.push_back(i);
    for(i = 2; i <= n; i += 2)
        sol.push_back(i);
    cout << sol.size() << "\n";
    for(auto it : sol)
        cout << it << " ";
    //cin.close();
    //cout.close();
    return 0;
}