#include <iostream>
#include <map>

using namespace std;

int n;
int x[2222];
map<int,int> a;
int c;
int p = 2222;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        if (a[x[i]] == 1) c++;
        a[x[i]]++;
    }
    if (c == 0) {
        cout << "0\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        auto b = a;
        int u = c;
        int k = 0;
        for (int j = i; j <= n; j++) {
            k++;
            b[x[j]]--;
            if (b[x[j]] == 1) u--;
            if (u == 0) break;
        }
        if (u == 0) p = min(p,k);
    }
    cout << p << "\n";
}