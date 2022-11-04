#include <bits/stdc++.h>
#define lsb(x)
#define ll long long

using namespace std;

const int MAXN = 2000;

int v[MAXN + 1];

inline int gcd(int a, int b) {
    int r;
    while(b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(){
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    ios::sync_with_stdio(false);
    cin >> n;
    int val = 0, cnt = 0;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        if(v[i] == 1)
            cnt++;
        val = gcd(val, v[i]);
    }
    if(val > 1) {
        cout << -1;
        return 0;
    }
    int len = n + 1, pos;
    for(i = 1; i <= n; i++) {
        val = 0;
        for(j = i; j <= n; j++) {
            val = gcd(val, v[j]);
            if(val == 1) {
                if(len > j - i + 1) {
                    len = j - i + 1;
                    pos = i;
                }
            }
        }
    }
    if(cnt > 0)
        cout << n - cnt;
    else
        cout << n + len - 2;
    //cin.close();
    //cout.close();
    return 0;
}