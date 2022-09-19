#include <bits/stdc++.h>

using namespace std;
const int c=4005;
int n, m, t[c][c], sor[c], oszlop[c], sdb[c], odb[c], cnt, mod=998244353;
int ki[c], rng[c], par[c];
int po(int x) {
    int ans=1;
    for (int i=1; i<=x; i++) {
        ans=2*ans%mod;
    }
    return ans;
}
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
bool unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a==b) return false;
    ki[b]=a;
    rng[a]+=rng[b], rng[b]=0;
    par[a]+=par[b], par[b]=0;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char c;
            cin >> c;
            if (c=='0') t[i][j]=2;
            if (c=='1') t[i][j]=1;
            sor[i]+=t[i][j], oszlop[j]+=t[i][j];
            if (t[i][j]) {
                sdb[i]++;
                odb[j]++;
            } else {
                cnt++;
            }
        }
    }
    if (n%2==0 && m%2==0) {
        cout << po(cnt) << "\n";
        return 0;
    }
    if (n%2==0) {
        int a=1, b=1, db=0;
        for (int i=1; i<=n; i++) {
            if (sdb[i]==m) {
                if (sor[i]%2) a=0;
                else b=0;
            } else {
                db++;
            }
        }
        cout << (a+b)*po(cnt-db)%mod << "\n";
        return 0;
    }
    if (m%2==0) {
        int a=1, b=1, db=0;
        for (int j=1; j<=m; j++) {
            if (odb[j]==n) {
                if (oszlop[j]%2) a=0;
                else b=0;
            } else {
                db++;
            }
        }
        cout << (a+b)*po(cnt-db)%mod << "\n";
        return 0;
    }

    for (int i=1; i<=n; i++) {
        par[i]=sor[i];
        rng[i]=1;
    }
    for (int i=n+1; i<=n+m; i++) {
        par[i]=oszlop[i-n];
        rng[i]=1;
    }
    int kor=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (!t[i][j]) {
                if (!unio(i, n+j)) {
                    kor++;
                }
            }
        }
    }
    bool ps=1, pn=1;
    for (int i=1; i<=n; i++) {
        if (sdb[i]==m) {
            if (sor[i]%2) ps=0;
            else pn=0;
        }
    }
    for (int i=1; i<=m; i++) {
        if (odb[i]==n) {
            if (oszlop[i]%2) ps=0;
            else pn=0;
        }
    }

    for (int i=1; i<=n+m; i++) {
        if (ki[i]==0 && rng[i]>1) {
            int a=par[i]%2, b=rng[i]%2;
            if (b%2==0) {
                if (a%2) ps=0, pn=0;
            } else {
                if (par[i]%2) ps=0;
                else pn=0;
            }
        }
    }
    //cout << "alap " << kor << "\n";
    cout << (ps+pn)*po(kor)%mod;
    return 0;
}