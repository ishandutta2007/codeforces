#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int n, x[c], y[c], xx[c], yy[c];
int dx[4]={1, -1, 0, 0}, dy[4]={0, 0, 1, -1};
bool v[c];
set<pair<int, int> > s;
map<pair<int, int>, int> m;
queue<int> q;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        x[i]=a, y[i]=b;
        s.insert({a, b});
        m[{a, b}]=i;
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<4; j++) {
            int a=x[i]+dx[j], b=y[i]+dy[j];
            if (s.find({a, b})==s.end()) {
                xx[i]=a, yy[i]=b;
            }
        }
        if (xx[i] || yy[i]) {
            q.push(i);
        }
    }
    while (q.size()>0) {
        int id=q.front(), a=x[id], b=y[id];
        q.pop();
        if (v[id]) continue;
        v[id]=1;
        for (int i=0; i<4; i++) {
            int aa=a+dx[i], bb=b+dy[i];
            if (s.find({aa, bb})!=s.end()) {
                int id2=m[{aa, bb}];
                if (!xx[id2] && !yy[id2]) {
                    xx[id2]=xx[id], yy[id2]=yy[id];
                    q.push(id2);
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        cout << xx[i] << " " << yy[i] << "\n";
    }
    return 0;
}