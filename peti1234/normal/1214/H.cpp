#include <bits/stdc++.h>

using namespace std;
const int c=200002;
vector<int> sz[c];
int sol[c], n, k, maxi, p1, p2, tav[c], tid[c], sp[c], mini, add, ert;
bool v1[c], v2[c], v3[c], baj;
void dfs1(int a) {
    v1[a]=true;
    int cs1=a, cs2=0, t1=0, t2=0;
    for (int x:sz[a]) {
        if (!v1[x]) {
            dfs1(x);
            if (tav[x]>t2) t2=tav[x], cs2=tid[x];
        }
        if (t2>t1) swap(t1, t2), swap(cs1, cs2);
    }
    if (t1+t2>maxi) {
        maxi=t1+t2, p1=cs1, p2=cs2;
    }
    tav[a]=t1+1, tid[a]=cs1;
}
bool dfs2(int a) {
    if (a==p2) {
        v3[a]=true;
        sol[a]=sp[a]%k;
        return true;
    }
    v2[a]=true;
    for (int x:sz[a]) {
        if (!v2[x]) {
            sp[x]=sp[a]+1;
            if (dfs2(x)) {
                sol[a]=sp[a]%k;
                v3[a]=true;
                return true;
            }
        }
    }
    sp[a]=0;
    return false;
}
void dfs3(int a, int ert) {
    if (ert<0) ert+=k;
    ert%=k;
    if (!v3[a]) {
        sol[a]=ert;
        if (tav[a]+mini>=k) baj=1;
    }
    v3[a]=true;
    for (int x:sz[a]) {
        if (!v3[x]) {
            tav[x]=tav[a]+1;
            dfs3(x, ert+add);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    dfs1(1);
    sp[p1]=1;
    dfs2(p1);
    for (int i=1; i<=n; i++) {
        if (sp[i]) {
            tav[i]=0;
            mini=min(sp[i], maxi-sp[i]+2);
            if (sp[i]-1>maxi-sp[i]+1) add=1;
            else add=-1;
            dfs3(i, sp[i]);
        }
    }
    if (baj && k!=2) cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i=1; i<=n; i++) {
            cout << sol[i]+1 << " ";
        }
        cout << "\n";
    }
    return 0;
}