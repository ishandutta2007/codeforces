#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long ll;
typedef double dbl;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <long long, long long> pll;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int n;
multiset <int> v;

vector <int> ans;

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    scanf("%d", &n);

    for (int i = 0; i < n * n; ++i) {
        int num;
        scanf("%d", &num);
        v.insert(num);
    }    

    ans.resize(n);

    for (int i = 0; i < n; ++i) {
        set <int>::iterator it = v.end();
        --it;
        int num = *it;
        ans[i] = num;
        v.erase(v.lower_bound(num));
        for (int j = 0; j < i; ++j) {
            int tmp = gcd(ans[i], ans[j]);
            v.erase(v.lower_bound(tmp));
            v.erase(v.lower_bound(tmp));
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}