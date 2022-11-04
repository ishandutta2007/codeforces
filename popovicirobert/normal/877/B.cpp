#include <bits/stdc++.h>
#define ll long long
#define lsb(x) (x & (-x))


using namespace std;

const int MAXN = 5000;

string str;

int spa[MAXN + 1];

int spb[MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    cin >> str;
    int n = str.size();
    str = " " + str;
    for(i = 1; i <= n; i++) {
        spa[i] = spa[i - 1] + (str[i] == 'a');
        spb[i] = spb[i - 1] + (str[i] == 'b');
    }
    int ans = 3 * n;
    for(i = 0; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            ans = min(ans, spb[i] + spa[j] - spa[i] + spb[n] - spb[j]);
        }
    }
    cout << n - ans;
    //cin.close();
    //cout.close();
    return 0;
}