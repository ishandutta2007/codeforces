#include<bits/stdc++.h>
using namespace std;

const int c=500002;

int ki[c], eldb, r[c];
long long n, si[c], ans;
vector<pair<int, int> > el[c];
int holvan(int a) {
    if (ki[a]) return holvan(ki[a]);
    return a;
}
int unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        eldb++;
        if (si[a]<si[b]) {
            ki[a]=b, si[b]+=si[a];
            r[eldb]=a;
        } else {
            ki[b]=a, si[a]+=si[b];
            r[eldb]=b;
        }
    }
}
int torol(int ert) {
    while(eldb>ert) {
        int v=r[eldb];
        si[ki[v]]-=si[v], ki[v]=0;
        eldb--;
    }
}

void solve(int bal, int jobb) {
    if (bal>jobb) {
        return;
    }
    if (bal==jobb) {
        for (auto x:el[bal]) {
            long long a=si[holvan(x.first)], b=si[holvan(x.second)];
            ans+=a*b;
        }
        return;
    }
    int elkezd=eldb;
    int koz=(bal+jobb)/2;
    for (int i=bal; i<=koz; i++) {
        for (auto x:el[i]) {
            unio(x.first, x.second);
        }
    }
    solve(koz+1, jobb);
    torol(elkezd);
    for (int i=koz+1; i<=jobb; i++) {
        for (auto x:el[i]) {
            unio(x.first, x.second);
        }
    }
    solve(bal, koz);
    torol(elkezd);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        si[i]=1;
    }
    for (int i=1; i<n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        el[c].push_back({a, b});
    }
    solve(1, n);
    cout << ans << "\n";
	return 0;
}