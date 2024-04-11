#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

set <int> g[MAXN + 1];
int ord[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, i, x, y;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i < n; i++) {
        cin >> x >> y;
        g[x].insert(y);
        g[y].insert(x);
    }
    for(i = 1; i <= n; i++) {
        cin >> ord[i];
    }
    if(ord[1] != 1) {
        cout << "No";
        return 0;
    }
    queue <int> Q;
    Q.push(1);
    for(auto it : g[1]) {
        g[it].erase(g[it].find(1));
    }
    int pos = 2;
    while(Q.size() && pos <= n) {
        int nod = Q.front();
        Q.pop();
        //printf("%d %d\n" ,nod,pos);
        while(pos <= n && g[nod].find(ord[pos]) != g[nod].end()) {
            Q.push(ord[pos]);
            for(auto it : g[ord[pos]]) {
                if(g[it].find(nod) != g[it].end())
                    g[it].erase(g[it].find(nod));
            }
            pos++;
        }
    }
    if(pos == n + 1) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    //cin.close();
    //cout.close();
    return 0;
}