#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    string str;
    cin >> n >> str;

    int a = 0, b = 0;
    int cnta = 0, cntb = 0;
    int pa = 0, pb = 0;

    while(pa <= (n - 11) / 2 && a < n) {
        if(str[a] == '8') {
            cnta++;
        }
        else {
            pa++;
        }
        a++;
    }

    while(pb < (n - 11) / 2 && b < n) {
        if(str[b] == '8') {
            cntb++;
            pb++;
        }
        b++;
    }

    //cerr << cnta << " " << cntb << "\n";

    cout << (cnta - cntb > 0 ? "YES" : "NO");

    //cin.close();
    //cout.close();
    return 0;
}