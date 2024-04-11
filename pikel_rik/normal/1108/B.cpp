#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;

vi divisors(int m) {
    vi ans;
    for (int i = 1; i <= m; i++) {
        if (m % i == 0)
            ans.push_back(i);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vi div(n);
    multiset<int> s;

    for (int i = 0; i < n; i++) {
        cin >> div[i];
        s.insert(div[i]);
    }

    int m = *max_element(div.begin(), div.end());

    vi div_m = divisors(m);
    for (int i : div_m) {
        s.erase(s.find(i));
    }

    cout << m << " " << *(s.rbegin());
    return 0;
}