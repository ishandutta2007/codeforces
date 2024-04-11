#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int n, q;
int a[101010];
ll b[101010];
ll t[101010];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n-1; i++) b[i] = abs(a[i+1]-a[i]);
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        y--;
        ll s = 0;
        vector<int> v;
        for (int j = x; j <= y; j++) {
            while (v.size() > 0 && b[v[v.size()-1]] <= b[j]) v.pop_back();
            if (v.size() == 0) {
                t[j] = (j-x+1)*b[j];
            } else {
                int e = v[v.size()-1];
                t[j] = (j-e)*b[j]+t[e];
            }
            s += t[j];
            v.push_back(j);
        }
        cout << s << "\n";
    }
}