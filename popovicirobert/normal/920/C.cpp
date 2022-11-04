#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 113

using namespace std;

const int MAXN = (int) 2e5;

int v[MAXN + 1];

string str;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
    }
    cin >> str;
    str = " " + str;
    int last = 1;
    for(i = 1; i < n; i++) {
        if(str[i] == '0') {
            sort(v + last, v + i + 1);
            for(j = last; j <= i; j++) {
                if(v[j] != j) {
                    cout << "NO";
                    return 0;
                }
            }
            last = i + 1;
        }
    }
    cout << "YES";
    //cin.close();
    //cout.close();
    return 0;
}