#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, k, bal[c], jobb[c], fel[c];
vector<int> sor;
char s[c];
bool jo[c], valt[c];
void dfs(int a) {
    if (!a) return;
    dfs(bal[a]);
    sor.push_back(a);
    dfs(jobb[a]);
}
void solve(int a, int szint) {
    if (!a || szint>k) return;
    solve(bal[a], szint+1);
    if (valt[a]) szint=0;
    if (jo[a]) {
        int x=a;
        for (int i=0; i<szint; i++) {
            valt[x]=1;
            x=fel[x];
            k--;
        }
    }
    if (valt[a]) {
        solve(jobb[a], 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> s[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> bal[i] >> jobb[i];
        fel[bal[i]]=fel[jobb[i]]=i;
    }
    dfs(1);
    for (int i=n-2; i>=0; i--) {
        if (s[sor[i]]<s[sor[i+1]] || s[sor[i]]==s[sor[i+1]] && jo[sor[i+1]]) {
            jo[sor[i]]=1;
        }
    }
    solve(1, 1);
    for (auto x:sor) {
        cout << s[x];
        if (valt[x]) cout << s[x];
    }
    cout << "\n";
    return 0;
}