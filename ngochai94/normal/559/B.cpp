#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define sqr(x) (x) * (x)
#define pb push_back

string s1, s2;

bool f(int st1, int st2, int len) {
    int flag = false;
    REP (i, len) if (s1[st1 + i] != s2[st2 + i]) {
        flag = true;
        break;
    }
    if (!flag) return true;
    if (len & 1) return false;
    if (f(st1, st2, len / 2) && f(st1 + len / 2, st2 + len / 2, len / 2)) return true;
    if (f(st1, st2 + len / 2, len / 2) && f(st1 + len / 2, st2, len / 2)) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> s1 >> s2;
    int n = s1.size();
    if (f(0, 0, n)) cout << "YES";
    else cout << "NO";
}