#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
    sort(a.begin(), a.end());
    int cn = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == a[0]) cn++; 
    }
    if (cn <= (n / 2))
        cout << "Alice\n";
    else
        cout << "Bob\n";
}