#include <bits/stdc++.h>

using namespace std;

int S[200002], B[200002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, m; cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int next = 0;
    for(int i=0;i<m;i++){
        while(next <= n && s[next] != t[i]) next++;
        S[i] = next++;
    }
    next = n;
    for(int i=m-1;i>=0;i--){
        while(next >= 0 && s[next] != t[i]) next--;
        B[i] = next--;
    }

    int ans = 0;
    for(int i=1;i<m;i++){
        ans = max(ans, B[i] - S[i-1]);
    }

    cout << ans;
}