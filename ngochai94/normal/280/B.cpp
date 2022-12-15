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

int n, lis[100005], ans;
stack<int> s;

int main(){
    ios::sync_with_stdio(0);
    cin >> n;
    REP (i, n) cin >> lis[i];
    s.push(lis[0]);
    FOR (i, 1, n - 1) {
        while (!s.empty() && s.top() < lis[i]) {
            ans = max(ans, lis[i] ^ s.top());
            s.pop();
        }
        if (!s.empty()) ans = max(ans, lis[i] ^ s.top());
        s.push(lis[i]);
    }
    cout << ans;
}