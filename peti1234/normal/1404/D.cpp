#include <bits/stdc++.h>

using namespace std;
const int c=500002;
int n, ki[2*c];
long long sum;
vector<int> sz[c], e, m;
bool v[2*c];
void dfs(int a) {
    v[a]=true;
    e.push_back(a), sum+=a;
    int h=ki[a], x=sz[h][0], y=sz[h][1];
    if (x==a) swap(x, y);
    m.push_back(x);
    v[x]=true;
    if (x>n) x-=n;
    else x+=n;
    if (!v[x]) dfs(x);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n%2==0) {
        cout << "First\n";
        for (int i=0; i<2*n; i++) cout << i%n+1 << " ";
        cout << "\n";
    } else {
        cout.flush() << "Second\n";
        for (int i=1; i<=2*n; i++) {
            int x; cin >> x;
            ki[i]=x;
            sz[x].push_back(i);
        }
        for (int i=1; i<=n; i++) {
            if (!v[i]) dfs(i);
        }
        sort(e.begin(), e.end()), sort(m.begin(), m.end());
        if (sum%(2*n)) {
            for (int i=0; i<n; i++) cout << m[i] << " ";
            cout << "\n";
        } else {
            for (int i=0; i<n; i++) cout << e[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}