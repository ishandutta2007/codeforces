#include <bits/stdc++.h>

using namespace std;
const int c=200002, h=10*c;
int h1, h2, pos[c];
long long st[h];
int w, n, m, k, si[c], db, jo;
vector<int> sz[c], sol;
priority_queue<pair<int, int> > q;
bool v[c];
int vel() {
    long long a=rand(), b=rand(), c=rand();
    return (a*b+c)%h;
}
void ujel(long long a, long long b, int id) {
    long long ert=(a*h1+b*h2)%h;
    while(st[ert]) {
        ert++;
        if (ert==h) ert=0;
    }
    st[ert]=n*a+b;
    pos[id]=ert;
}
bool el(long long a, long long b) {
    long long ert=(a*h1+b*h2)%h, ert2=n*a+b;
    while(st[ert]) {
        if (st[ert]==ert2) return true;
        ert++;
        if (ert==h) ert=0;
    }
    return false;
}
bool klikk() {
    int si=sol.size();
    if (si<k-1) {
        sol.clear();
        return false;
    }
    sort(sol.begin(), sol.end());
    for (int i=0; i<si; i++) {
        for (int j=i+1; j<si; j++) {
            if (!el(sol[i], sol[j])) {
                sol.clear();
                return false;
            }
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    srand(time(0));
    h1=vel(), h2=vel();
    cin >> w;
    while(w--) {
        cin >> n >> m >> k;
        for (int i=1; i<=n; i++) {
            si[i]=0, sz[i].clear(), v[i]=0;
        }
        sol.clear(), jo=0, db=0;
        for (int i=1; i<=m; i++) {
            int a, b; cin >> a >> b;
            if (a>b) swap(a, b);
            sz[a].push_back(b), sz[b].push_back(a);
            ujel(a, b, i);
        }
        for (int i=1; i<=n; i++) {
            si[i]=sz[i].size();
            if (si[i]<k) {
                q.push({-si[i], i});
            }
        }
        db=n;
        while(q.size()>0) {
            int ert=-q.top().first, id=q.top().second;
            q.pop();
            if (!jo && !v[id]) {
                v[id]=true, db--;
                for (int x:sz[id]) {
                    if (!v[x]) {
                        sol.push_back(x);
                        si[x]--;
                        if (si[x]<k) q.push({-si[x], x});
                    }
                }
                if (klikk()) {
                    db=k, jo=1;
                    for (int i=1; i<=n; i++) v[i]=1;
                    v[id]=0;
                    for (int x:sol) v[x]=0;
                }
            }
        }
        if (db) jo=1;
        if (!jo) cout << -1 << "\n";
        else {
            if (db==k) cout << 2 << "\n";
            else cout << 1 << " " << db << "\n";
            for (int i=1; i<=n; i++) {
                if (!v[i]) cout << i << " ";
            }
            cout << "\n";
        }
        for (int i=1; i<=m; i++) {
            st[pos[i]]=0;
            pos[i]=0;
        }
    }
    return 0;
}