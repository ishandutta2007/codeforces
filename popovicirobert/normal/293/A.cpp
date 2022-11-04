#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e6;

char a[2 * MAXN + 1], b[2 * MAXN + 1];
int fr[10];

int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> a + 1 >> b + 1;
    n *= 2;
    for(i = 1; i <= n; i++) {
        int x = a[i] - '0', y = b[i] - '0';
        fr[x * 2 + y]++;
    }
    while(n > 0) {
        int x, y;
        n -= 2;
        if(fr[3]) {
            fr[3]--;
            x = 1;
        }
        else if(fr[2]) {
            fr[2]--;
            x = 1;
        }
        else if(fr[1]) {
            fr[1]--;
            x = 0;
        }
        else if(fr[0]) {
            fr[0]--;
            x = 0;
        }

        if(fr[3]) {
            fr[3]--;
            y = 1;
        }
        else if(fr[1]) {
            fr[1]--;
            y = 1;
        }
        else if(fr[2]) {
            fr[2]--;
            y = 0;
        }
        else if(fr[0]) {
            fr[0]--;
            y = 0;
        }
        //cerr << x << " " << y << "\n";
        if(x == y) {
            continue;
        }
        if(x < y) {
            cout << "Second";
        }
        else {
            cout << "First";
        }
        return 0;
    }
    cout << "Draw";
    //cin.close();
    //cout.close();
    return 0;
}