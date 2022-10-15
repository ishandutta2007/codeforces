#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string a;
        cin >> n;
        cin >> a;
        map<int,int> z;
        z[0] = 1;
        int s = 0;
        ll u = 0;
        for (int i = 1; i <= n; i++) {
            s += a[i-1]-'0';
            u += z[s-i];
            z[s-i]++;
        }
        cout << u << "\n";
    }
}