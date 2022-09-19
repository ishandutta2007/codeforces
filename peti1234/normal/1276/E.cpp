#include <bits/stdc++.h>

using namespace std;
long long g[2], ert;
int cnt;
vector<pair<long long, long long> > ans[4];
void lep(vector<long long> &a, long long x, long long y, int id) {
    if (x==y) {
        return;
    }
    cnt++;
    int pos=-1;
    for (int i=0; i<4; i++) {
        if (a[i]==x) {
            pos=i;
        }
    }
    a[pos]=2*y-x;
    sort(a.begin(), a.end());
    long long x2=(id<=1 ? x : 2*y-x);
    ans[id].push_back({x2, y});
}
bool ch(vector<long long> &a, int x, int y, int id) {
    long long dif=a[3]-a[0], k=abs(a[x]-a[y]);
    if (4*k>=dif && 2*k<=dif) {
        lep(a, a[x], a[y], id);
        return true;
    }
    return false;
}
void solve(vector<long long> &a, int id) {
    sort(a.begin(), a.end());
    long long dif=a[3]-a[0];
    while (dif>ert) {
        while (ch(a, 0, 1, id) || ch(a, 0, 2, id) || ch(a, 3, 1, id) || ch(a, 3, 2, id)) {}
        dif=a[3]-a[0];
        if (dif>ert) {
            int p1=-1, p2=-1;
            for (int i=0; i<4; i++) {
                for (int j=i+1; j<4; j++) {
                    if (4*(a[j]-a[i])<=dif && (p1==-1 || a[j]-a[i]>a[p2]-a[p1])) {
                        p2=j, p1=i;
                    }
                }
            }
            if (p1+p2==3) {
                if (a[0]==a[1]) {
                    p1=1-p1;
                } else if (a[2]==a[3]) {
                    p2=5-p2;
                }
            }
            int pos=(p1==0 ? 3-p2 : 3-p1);
            long long ert1=a[p1], ert2=a[p2], val=a[pos], kov=0;
            if (pos<=1) {
                kov=2*ert1-val;
                lep(a, val, ert1, id);
                lep(a, kov, ert2, id);
            } else {
                kov=2*ert2-val;
                lep(a, val, ert2, id);
                lep(a, kov, ert1, id);
            }
        }
        dif=a[3]-a[0];
    }

    if (id>=2) {
        reverse(ans[id].begin(), ans[id].end());
    }
}
void solve2(vector<long long> &a, long long cel, int id) {
    long long dif=a[3]-a[0], kul=(abs(cel-a[0]));
    if (dif>ert || kul>0) {
        long long a0=a[0], a1=a[1], a2=a[2], a3=a[3];
        if (dif>kul) {
            lep(a, a0, a1, id);
            lep(a, a3, a2, id);
            return solve2(a, cel, id);
        }
        if (4*dif<kul) {
            lep(a, a2, a0, id);
            lep(a, a1, a3, id);
            return solve2(a, cel, id);
        }
        if (a[0]>cel) {
            lep(a, a1, a0, id);
            lep(a, a2, a0, id);
            lep(a, a3, a0, id);
        } else {
            lep(a, a0, a3, id);
            lep(a, a1, a3, id);
            lep(a, a2, a3, id);
        }
        return solve2(a, cel, id);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long sa=0, sb=0;
    vector<long long> a, b;
    for (int i=0; i<4; i++) {
        int x;
        cin >> x;
        sa+=x;
        a.push_back(x);
    }
    for (int i=0; i<4; i++) {
        int x;
        cin >> x;
        sb+=x;
        b.push_back(x);
    }
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    for (int i=1; i<4; i++) {
        g[0]=__gcd(g[0], a[i]-a[0]);
        g[1]=__gcd(g[1], b[i]-b[0]);
    }
    if (g[0]!=g[1] || g[0]==0 && a[0]!=b[0] || g[0]!=0 && abs(sa-sb)%(2*g[0])!=0) {
        cout << -1 << "\n";
        return 0;
    }
    ert=g[0];
    solve(a, 0), solve(b, 2);
    solve2(a, b[0], 1);
    cout << cnt << "\n";
    for (int i=0; i<3; i++) {
        for (auto x:ans[i]) {
            cout << x.first << " " << x.second << "\n";
        }
    }
    return 0;
}