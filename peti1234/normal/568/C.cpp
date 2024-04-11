#include <bits/stdc++.h>

using namespace std;
const int c=405, k=30;
int n, m, l, kov0[k], kov1[k], ea, eb;
vector<int> sz[c];
bool p[k], aa[k], v[c];
string s, kezd;
int valt(int a) {
    return (a>n ? a-n : a+n);
}
vector<int> vis;
void dfs(int a) {
    v[a]=true;
    vis.push_back(a);
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
}
vector<int> proba(int pos) {
    vis.clear();
    dfs(pos);
    return vis;
}
void cl(vector<int> fr) {
    for (auto x:fr) {
        v[x]=0;
    }
}
bool solve(int pos, bool s) {
    //cout << "solve " << pos << " " << s << "\n";
    //cout << "kell " << v[pos] << " " << v[pos+n] << "\n";
    if (pos>n) {
        return true;
    }
    int ert=(kezd[pos-1]-'a'+1);

    if (v[pos]) {
        if (s) {
            if (ea<=l && solve(pos+1, 1)) {
                kezd[pos-1]='a'+ea-1;
                return true;
            }
            return false;
        } else {
            if (aa[ert] && solve(pos+1, 0)) {
                return true;
            }
            int uj=kov0[ert+1];
            if (uj<=l && solve(pos+1, 1)) {
                kezd[pos-1]='a'+uj-1;
                return true;
            }
            return false;
        }
    }

    if (v[pos+n]) {
        if (s) {
            if (eb<=l && solve(pos+1, 1)) {
                kezd[pos-1]='a'+eb-1;
                return true;
            }
            return false;
        } else {
            if (!aa[ert] && solve(pos+1, 0)) {
                return true;
            }
            int uj=kov1[ert+1];
            if (uj<=l && solve(pos+1, 1)) {
                kezd[pos-1]='a'+uj-1;
                return true;
            }
            return false;
        }
    }
    if (!s) {
        int r=(aa[ert] ? pos : pos+n);
        vector<int> fr=proba(r);
        if (!v[valt(r)] && solve(pos+1, 0)) {
            return true;
        }
        cl(fr);
    }

    int a1=(s ? ea : kov0[ert+1]), b1=(s ? eb : kov1[ert+1]);
    if (a1<b1) {
        if (a1>l) {
            cout << "nagyonnagybaj\n";
        }
        vector<int> fr=proba(pos);
        if (!v[pos+n] && solve(pos+1, 1)) {
            kezd[pos-1]='a'+a1-1;
            return true;
        }
        cl(fr);
    }
    if (b1<=l) {
        vector<int> fr=proba(pos+n);
        if (!v[pos] && solve(pos+1, 1)) {
            kezd[pos-1]='a'+b1-1;
            return true;
        }
        cl(fr);
    }
    if (a1<=l) {
        vector<int> fr=proba(pos);
        if (!v[pos+n] && solve(pos+1, 1)) {
            kezd[pos-1]='a'+a1-1;
            return 1;
        }
        cl(fr);
    }
    return false;


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> s;
    l=s.size();
    for (int i=0; i<l; i++) {
        if (s[i]=='V') {
            aa[i+1]=1;
        }
    }
    kov0[l+1]=l+1, kov1[l+1]=l+1;
    for (int i=l; i>=1; i--) {
        kov0[i]=(aa[i] ? i : kov0[i+1]);
        kov1[i]=(!aa[i] ? i : kov1[i+1]);
    }
    ea=kov0[1], eb=kov1[1];
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int p1, p2;
        char c1, c2;
        cin >> p1 >> c1 >> p2 >> c2;
        if (c1!='V') p1+=n;
        if (c2!='V') p2+=n;
        sz[p1].push_back(p2);
        sz[valt(p2)].push_back(valt(p1));
    }
    for (int i=1; i<=n; i++) {
        bool baj=1;
        vector<int> fr=proba(i);
        if (!v[i+n]) {
            baj=0;
        }
        cl(fr);
        fr=proba(i+n);
        if (!v[i]) {
            baj=0;
        }
        cl(fr);

        if (baj) {
            cout << -1 << "\n";
            return 0;
        }

    }
    cin >> kezd;
    if (solve(1, 0)) {
        cout << kezd << "\n";
    } else {
        cout << -1 << "\n";
    }
    return 0;
}
/*
VCV
10 10
1 V 7 V
7 V 1 V
10 V 8 C
9 V 1 V
6 C 2 C
1 V 9 V
2 C 5 C
2 V 9 C
2 C 10 C
1 V 4 C
bbbbcaabab




*/