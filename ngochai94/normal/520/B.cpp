#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define pb push_back

int n, m, vst[100005];
queue<int> q;

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> m;
    q.push(n);
    reset(vst, -1);
    vst[n] = 0;
    q.push(n);
    while (!q.empty()) {
        n = q.front();
        q.pop();
        if (n * 2 < 100000 && !~vst[n * 2]) {
            vst[n * 2] = vst[n] + 1;
            q.push(n * 2);
        }
        if (n - 1 > 0 && !~vst[n - 1]) {
            vst[n - 1] = vst[n] + 1;
            q.push(n - 1);
        }
    }
    cout << vst[m];
}