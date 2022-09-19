#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, f[c], ln[c], rf[c], szint[c], pos, cel;
vector<int> sz[c];
bool v[c];
void dfs(int a) {
    v[a]=true;
    rf[a]=1;
    for (int x:sz[a]) {
        if (!v[x]) {
            f[x]=a;
            szint[x]=szint[a]+1;
            dfs(x);
            rf[a]+=rf[x];
            if (rf[x]>rf[ln[a]]) {
                ln[a]=x;
            }
        }
    }
}
int ask(char c, int x) {
    cout.flush() << c << " " << x << "\n";
    int res;
    cin >> res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs(1);
    cel=ask('d', 1), pos=1;
    while (szint[pos]<cel) {
        int uj=pos;
        while (ln[uj]) {
            uj=ln[uj];
        }
        int s=ask('d', uj);
        while (szint[uj]+s>cel) {
            uj=f[uj], s--;
        }
        pos=uj;
        if (s) {
            pos=ask('s', pos);
        }
    }
    cout << "! " << pos << "\n";
    return 0;
}