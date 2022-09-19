#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> >sz={{0, 1}, {0, -1}, {1, 1}, {1, 0}, {1, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
vector<vector<int> > v, t;
int n, m, cnt, lo=-1, hi=1e3, mid, db;
string s;
queue<pair<pair<int, int>, int> > q;
bool jo(int a, int b) {
    return (a>=0 && a<n && b>=0 && b<m);
}
int ert(int a, int b) {
    if (!jo(a, b)) return 0;
    return t[a][b];
}
bool f(int a, int b, int c) {
    return (jo(a+c, b+c) && ert(a+c, b+c)-ert(a-c-1, b+c)-ert(a+c, b-c-1)+ert(a-c-1, b-c-1)==(2*c+1)*(2*c+1));
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m, v.resize(n), t.resize(n);
    for (int i=0; i<n; i++) {
        v[i].resize(m), t[i].resize(m);
        cin >> s;
        for (int j=0; j<m; j++) {
            int p=(s[j]=='X'); db+=p;
            t[i][j]=ert(i-1, j)+ert(i, j-1)-ert(i-1, j-1)+p;
        }
    }
    while(hi-lo>1) {
        mid=((hi+lo)/2);
        cnt=0;
        for (int i=0; i<n;i++) for (int j=0; j<m; j++) {
            v[i][j]=0;
            if (f(i, j, mid)) q.push({{i, j}, 0});
        }
        while(q.size()>0) {
            int a=q.front().first.first, b=q.front().first.second, t=q.front().second;
            q.pop();
            if (!v[a][b]) {
                v[a][b]=1, cnt++;
                for (int i=0; i<8; i++) {
                    int x=a+sz[i].first, y=b+sz[i].second;
                    if (t<mid) q.push({{x, y}, t+1});
                }
            }
        }
        if (cnt==db) lo=mid;
        else hi=mid;
    }
    cout << lo << "\n";
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (f(i, j, lo)) cout << 'X';
            else cout << '.';
        }
        cout << "\n";
    }
    return 0;
}