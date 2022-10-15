#include <iostream>
#include <map>

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        map<pair<int,int>,int> m;
        int c1 = 0, c2 = 0;
        ll r = 0;
        for (auto x : s) {
            if (x == 'D') c1++;
            if (x == 'K') c2++;
            int g = gcd(c1,c2);
            int g1 = c1/g;
            int g2 = c2/g;
            m[{g1,g2}] += 1;
            cout << m[{g1,g2}] << " ";
        }
        cout << "\n";
    }
}