#include <bits/stdc++.h>

using namespace std;
int n, kerd=1;
vector<int> sz[1001];
int db[1001];
bool v[1001];
queue<int> q;
void out(int a, int b)
{
    cout.flush() << "?" << " " << a << " " << b << "\n";
}
void val(int a) {
    cout.flush() << "!" << " " << a << "\n";
}
int main()
{
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        db[i]=sz[i].size();
        if (db[i]==1) q.push(i);
    }
    while(2*kerd<=n) {
        int fi=q.front();
        v[fi]=1;
        for (int i=0; i<sz[fi].size(); i++) {
            int x=sz[fi][i];
            db[x]--;
            if (db[x]==1) q.push(x);
        }
        q.pop();
        int se=q.front();
        v[se]=1;
        for (int i=0; i<sz[se].size(); i++) {
            int x=sz[se][i];
            db[x]--;
            if (db[x]==1) q.push(x);
        }
        q.pop();
        out(fi, se);
        int x;
        cin >> x;
        if (x==fi) {
            val(fi);
            return 0;
        } else if (x==se) {
            val(se);
            return 0;
        }
        kerd++;
    }
    for (int i=1; i<=n; i++) if (!v[i]) {
        val(i);
        return 0;
    }
    return 0;
}