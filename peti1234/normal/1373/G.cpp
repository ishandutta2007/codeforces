#include <bits/stdc++.h>

using namespace std;
const int c=524288;
int n, m, k, lp[2*c], kezd[2*c], veg[2*c], maxi[2*c], ev[c];
priority_queue<int> q;
set<pair<int, int> > s;
void add(int a, int st, int fi, int ert) {
    int x=kezd[a], y=veg[a], e=2*a, f=e+1;
    if (x>fi || y<st) return;
    if (st<=x && y<=fi) lp[a]+=ert;
    else {
        add(e, st, fi, ert), add(f, st, fi, ert);
        maxi[a]=max(maxi[e]+lp[e], maxi[f]+lp[f]);
    }
}
int ask(int a, int st, int fi) {
    int x=kezd[a], y=veg[a], e=2*a, f=e+1;
    if (x>fi || y<st) return 0;
    if (st<=x && y<=fi) return maxi[a]+lp[a];
    lp[e]+=lp[a], lp[f]+=lp[a];
    return max(ask(e, st, fi), ask(f, st, fi));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> m, q.push(n);
    for (int i=c; i<2*c; i++) kezd[i]=i-c+1, veg[i]=i-c+1, maxi[i]=i-c-n;
    for (int i=c-1; i>=1; i--) kezd[i]=kezd[2*i], veg[i]=veg[2*i+1], maxi[i]=max(maxi[2*i], maxi[2*i+1]);
    for (int i=1; i<=m; i++) {
        int a, b, x, y;
        cin >> a;
        cin >> b;
        x=b+(abs(a-k));
        if (s.find({a, b})!=s.end()) y=-1, s.erase({a, b}), ev[x]++;
        else y=1, s.insert({a, b}), q.push(x);
        while(ev[q.top()]) ev[q.top()]--, q.pop();
        add(1, 1, x, y);
        cout << max(0, ask(1, 1, q.top())) << "\n";
    }
    return 0;
}