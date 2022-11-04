#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

map < pair <int, int>, int > mp;

inline int gcd(int a, int b) {
    int r;
    while(b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

string str;
vector <int> v[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, j;
    ios::sync_with_stdio(false);
    cin >> m;
    for(i = 1; i <= m; i++) {
        cin >> str;
        int pos = 0;
        for(j = 0; j < 3; j++) {
            int nr = 0;
            while(!isdigit(str[pos])) {
                pos++;
            }
            while(pos < str.size() && isdigit(str[pos])) {
                nr = nr * 10 + str[pos] - '0';
                pos++;
            }
            v[i].push_back(nr);
        }
        int a = v[i][0] + v[i][1], b = v[i][2];
        int c = gcd(a, b);
        mp[{a / c, b / c}]++;
    }
    for(i = 1; i <= m; i++) {
        int a = v[i][0] + v[i][1], b = v[i][2];
        int c = gcd(a, b);
        cout << mp[{a / c, b / c}] << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}