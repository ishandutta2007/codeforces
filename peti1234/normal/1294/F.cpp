#include <bits/stdc++.h>

using namespace std;
int n, x, y, m=-1;
queue<pair<int, pair<int, int> > > q;
vector<int> sz[200001];
int db[200001];
bool v[200001];
void pb(int a, int b, int c) {
    q.push({a, {b, c}});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {db[i]=sz[i].size(), v[i]=true; if (sz[i].size()==1) pb(i, i, 0);}
    if (q.size()==2) {
        cout << n-1 << "\n";
        cout << q.front().first << " " << sz[q.front().first][0] << " ";
        q.pop();
        cout << q.front().first << "\n";
        return 0;
    }
    while(q.size()>2) {
        int id=q.front().first;
        int l=q.front().second.first;
        int h=q.front().second.second;
        v[id]=false, q.pop();
        for (int i=0; i<sz[id].size(); i++) {
            int p=sz[id][i];
            if (v[p]) {
                db[p]--;
                if (db[p]==1) pb(p, l, h+1);
            }
        }
    }
    m+=q.front().second.second, x=q.front().second.first;
    q.pop();
    m+=q.front().second.second, y=q.front().second.first;
    q.pop();
    for (int i=1; i<=n; i++){
        if (v[i]) m++;
        v[i]=true, db[i]=sz[i].size(); if (sz[i].size()==1 && i!=x && i!=y) pb(i, i, 0);
    }
    while(q.size()>=1) {
        int id=q.front().first;
        int l=q.front().second.first;
        int h=q.front().second.second;
        v[id]=false, q.pop();
        for (int i=0; i<sz[id].size(); i++) {
            int p=sz[id][i];
            if (v[p]) {
                db[p]--;
                if (db[p]==1) pb(p, l, h+1);
            }
        }
        if (q.size()==0) {
            cout << m+h+1 << "\n" << x << " " << y << " " << l << "\n";
        }
    }
    return 0;
}
/*
10
1 2 2 3 3 4 4 5 5 6 6 7 7 8 6 9 9 10
*/