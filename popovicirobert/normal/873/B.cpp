#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = (int) 1e5;

int pos[2 * MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, s;
    char ch;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = -n; i <= n; i++)
        pos[i + MAXN] = n;
    pos[MAXN] = 0;
    s = 0;
    int ans = 0;
    for(i = 1; i <= n; i++) {
        cin >> ch;
        ch -= '0';
        if(ch == 0)
           s++;
        else
           s--;
        ans = max(ans, i - pos[s + MAXN]);
        pos[s + MAXN] = min(pos[s + MAXN], i);
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}