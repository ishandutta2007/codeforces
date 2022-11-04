#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll INF = (1LL << 61);
const int MAXN = (int) 1e5;

string f0, f1;

ll dp[MAXN + 1];

int sz1 = 34, sz2 = 32;
int t;

char solve(int n, ll pos) {
    if(n == 0)
       return f0[pos - 1];
    if(pos <= sz1)
       return f1[pos - 1];
    if(pos <= sz1 + dp[n - 1])
       return solve(n - 1, pos - sz1);
    if(pos <= sz1 + dp[n - 1] + sz2)
       return f1[pos - dp[n - 1] - 1];
    if(pos <= sz1 + 2 * dp[n - 1] + sz2)
        return solve(n - 1, pos - sz1 - dp[n - 1] - sz2);
    return f1[pos - 2 * dp[n - 1] - 1];
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i;
    ios::sync_with_stdio(false);
    f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
    f1 = "What are you doing while sending 11? Are you busy? Will you send 11?";
    int sz = f0.size();
    cin >> t;
    dp[0] = sz;
    for(i = 1; i <= MAXN; i++) {
        if((INF - 68) / 2 < dp[i - 1])
            dp[i] = INF;
        else
            dp[i] = 2 * dp[i - 1] + 68;
    }
    while(t > 0) {
        t--;
        int n;
        ll k;
        cin >> n >> k;
        if(dp[n] < k) {
            cout << ".";
        }
        else {
            char ch = solve(n, k);
            if(ch == '1')
                cout << "\"";
            else
                cout << ch;
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}