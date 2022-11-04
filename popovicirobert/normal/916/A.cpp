#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 92

using namespace std;



int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int x, h, m;
    ios::sync_with_stdio(false);
    cin >> x;
    cin >> h >> m;
    int cnt = 0;
    while(1) {
        if(h % 10 == 7 || m % 10 == 7) {
            cout << cnt;
            return 0;
        }
         m -= x;
        if(m < 0) {
            m += 60;
            h--;
        }
        if(h < 0)
            h += 24;
        cnt++;
    }
    //cin.close();
    //cout.close();
    return 0;
}