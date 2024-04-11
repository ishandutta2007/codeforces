#include <bits/stdc++.h>

using namespace std;
const int c=(1<<21);
int n, p, k;
int kezd[c], veg[c], fix[c], lp[c], mini[c], ki[c], kov[c];
bool v[c];
vector<int> s;
map<int, int> m;
vector<pair<int, int> > sz[c];
void init(int x) {
    int po=1;
    while (po<=x) {
        po*=2;
    }
    for (int i=po; i<2*po; i++) {
        kezd[i]=i-po+1, veg[i]=i-po+1;
    }
    for (int i=po-1; i>=1; i--) {
        kezd[i]=kezd[2*i], veg[i]=veg[2*i+1];
    }
}
int calc(int a, int l, int r) {
    if (kezd[a]>r || veg[a]<l) {
        return 0;
    }
    if (l<=kezd[a] && veg[a]<=r) {
        return 2;
    }
    return 1;
}
void calc2(int a) {
    int x=2*a, y=2*a+1;
    mini[a]=min(mini[x], mini[y]);
    ki[a]=(mini[a]==mini[x] ? ki[x] : ki[y]);
}
void push(int a) {
    int x=2*a, y=2*a+1;
    if (fix[a]) {
        fix[x]=fix[a], fix[y]=fix[a];
        mini[x]=fix[a], mini[y]=fix[a];
        ki[x]=ki[a], ki[y]=ki[a];
        lp[x]=0, lp[y]=0;
    } else if (lp[a]) {
        if (fix[x]) {
            fix[x]+=lp[a];
        } else {
            lp[x]+=lp[a];
        }
        if (fix[y]) {
            fix[y]+=lp[a];
        } else {
            lp[y]+=lp[a];
        }
        mini[x]+=lp[a], mini[y]+=lp[a];
    }
    fix[a]=0, lp[a]=0, ki[a]=0, mini[a]=0;
}
void add(int a, int l, int r) {
    int s=calc(a, l, r);
    if (s==0) {
        return;
    }
    if (s==2) {
        if (fix[a]) {
            fix[a]++;
        } else {
            lp[a]++;
        }
        mini[a]++;
        return;
    }
    push(a);
    int x=2*a, y=2*a+1;
    add(x, l, r), add(y, l, r);
    calc2(a);
}
void valt(int a, int l, int r, int val, int id) {
    int s=calc(a, l, r);
    if (s==0) {
        return;
    }
    if (s==2) {
        fix[a]=val, mini[a]=val, ki[a]=id;
        lp[a]=0;
        return;
    }
    push(a);
    int x=2*a, y=2*a+1;
    valt(x, l, r, val, id), valt(y, l, r, val, id);
    calc2(a);
}
pair<int, int> ask(int a, int l, int r) {

    int s=calc(a, l, r);
    if (s==0) {
        return {n+1, 0};
    }
    if (s==2) {
        return {mini[a], ki[a]};
    }
    push(a);
    int x=2*a, y=2*a+1;
    auto v1=ask(x, l, r), v2=ask(y, l, r);
    calc2(a);
    return min(v1, v2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> p;
    for (int i=1; i<=p; i++) {
        int a, x, y;
        cin >> a >> x >> y;
        y++;
        s.push_back(x), s.push_back(y);
        sz[a].push_back({x, 1}), sz[a].push_back({y, -1});
    }
    sort(s.begin(), s.end());
    s.erase(unique(s.begin(), s.end()), s.end());
    for (auto x:s) {
        k++;
        m[x]=k;
    }
    init(k);
    add(1, 1, k);
    for (int i=1; i<=n; i++) {
        sort(sz[i].begin(), sz[i].end());
        int cnt=0, ut=1;
        pair<int, int> res={n+1, 0};
        for (auto x:sz[i]) {
            int fi=m[x.first];
            if (x.second==1) {
                cnt++;
                if (cnt==1) {
                    ut=fi;
                }
            } else {
                cnt--;
                if (cnt==0) {
                    res=min(res, ask(1, ut, fi-1));
                }
            }
        }
        ut=1;
        for (auto x:sz[i]) {
            int fi=m[x.first];
            if (x.second==1) {
                cnt++;
                if (cnt==1) {
                    add(1, ut, fi-1);
                    ut=fi;
                }
            } else {
                cnt--;
                if (cnt==0) {
                    valt(1, ut, fi-1, res.first, i);
                    ut=fi;
                }
            }
        }
        add(1, ut, k);
        kov[i]=res.second;
    }
    pair<int, int> ans=ask(1, 1, k);
    int pos=ans.second;
    cout << ans.first-1 << "\n";
    while (pos) {
        v[pos]=1;
        pos=kov[pos];
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) {
            cout << i << " ";
        }
    }
    cout << "\n";
    return 0;
}