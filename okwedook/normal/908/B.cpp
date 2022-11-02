#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<string> arr(100);
string inst;
ll sx, sy;
ll n, m;
int cnt = 0;


void rec(ll a, ll b, ll c, ll d) {
    ll x = sx, y = sy;
    for (int i = 0; i < inst.size(); ++i) {
        if (a == inst[i]) --x;
        if (b == inst[i]) --y;
        if (c == inst[i]) ++x;
        if (d == inst[i]) ++y;
        if (x < 0 || y < 0 || x >= m || y >= n || arr[y][x] == '#')
            return;
        if (arr[y][x] == 'E') {
            cnt++;
            return;
        }
        //cout << (arr[y][x] == 'E');
    }
}

int main() { 
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    for (int i = 0; i < n;++i)
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == 'S') {
                sx = j;
                sy = i;
                arr[i][j] == '.';
            }
        }
    cin >> inst;
    rec(48, 49, 50, 51);
    rec(48, 49, 51, 50);
    rec(48, 50, 49, 51);
    rec(48, 50, 51, 49);
    rec(48, 51, 49, 50);
    rec(48, 51, 50, 49);
    rec(49, 48, 50, 51);
    rec(49, 48, 51, 50);
    rec(49, 50, 48, 51);
    rec(49, 50, 51, 48);
    rec(49, 51, 48, 50);
    rec(49, 51, 50, 48);
    rec(50, 48, 49, 51);
    rec(50, 48, 51, 49);
    rec(50, 49, 48, 51);
    rec(50, 49, 51, 48);
    rec(50, 51, 48, 49);
    rec(50, 51, 49, 48);
    rec(51, 48, 49, 50);
    rec(51, 48, 50, 49);
    rec(51, 49, 48, 50);
    rec(51, 49, 50, 48);
    rec(51, 50, 48, 49);
    rec(51, 50, 49, 48);
    cout << cnt;
    //system("pause");
    return 0; 
}