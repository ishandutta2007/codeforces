#include <bits/stdc++.h>

using namespace std;
int n, k, h;
string s;
vector<int> z;
void z_function(string s) {
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    cin >> s;
    s+=(char)'z'+1;
    n++;
    z.resize(n);
    z_function(s);

    for (int i=0; i<min(n, k); i++) {
        if (s[i+z[i]]>s[z[i]]) {
            break;
        }
        h++;
    }
    for (int i=0; i<k; i++) {
        cout << s[i%h];
    }
    cout << "\n";
    return 0;
}
/*
7 8
dcbdcba
*/