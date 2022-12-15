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

int n, cnt[26], ans;
string s;

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> s;
    for (char c: s) {
        int val = (c >= 'a' && c <= 'z') ? c - 'a' : c - 'A';
        if (!cnt[val]) {
            cnt[val] ++;
            ans++;
        }
    }
    if (ans == 26) cout << "YES";
    else cout << "NO";
}