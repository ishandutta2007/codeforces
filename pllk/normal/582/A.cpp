#include <iostream>
#include <set>
#include <vector>

using namespace std;

int n;
multiset<int> z;
vector<int> p;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n*n; i++) {
        int x;
        cin >> x;
        z.insert(x);
    }
    for (int i = 0; i < n; i++) {
        int u = *z.rbegin();
        for (int i = 0; i < p.size(); i++) {
            z.erase(z.find(gcd(p[i],u)));
            z.erase(z.find(gcd(p[i],u)));
        }
        z.erase(z.find(u));
        p.push_back(u);
        cout << u << " ";
    }
    cout << "\n";
}