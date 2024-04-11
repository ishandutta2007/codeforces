#include <bits/stdc++.h>

using namespace std;
const int c=5000005;
int n, ans, si[c], ki[c], cnt;
bool baj;
priority_queue<int> q[c][2];
map<int, int> m;
int add(int a) {
    if (m.find(a)==m.end()) {
        m[a]=++cnt;
        ki[cnt]=a;
    }
    return m[a];
}
void solve(int x) {
    if (baj) return;
    //cout << "solve " << x << "\n";
    if (x==0) {
        baj=1;
        return;
    }
    int s=add(x);
    si[s]--;
    ans-=q[s][0].top();
    q[s][0].pop();
    int ert=x/2, cnt=0;
    while (ert && ert%2==0) {
        ert/=2, cnt++;
    }
    //cout << "vege " << ert << " " << cnt << "\n";
    int kov=add(ert);
    ans++;
    si[kov]++;
    q[kov][0].push(-cnt);
    if (si[kov]>0) {
        solve(ert);
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        cin >> n;
        for (int id=1; id>=0; id--) {
            for (int i=1; i<=n; i++) {
                int x, cnt=0;
                cin >> x;
                while (x && x%2==0) {
                    cnt++, x/=2;
                }
                //cout << "vege " << x << " " << "\n";
                int s=add(x);
                if (id==0) si[s]++;
                else si[s]--;
                q[s][id].push(-cnt);
            }
        }
        //return 0;
        for (int i=1; i<=cnt; i++) {
            while (si[i]>0) {
                if (baj) break;
                solve(ki[i]);
            }
        }
        //return 0;
        //cout << "alap " << ans << "\n";
        cout << (baj ? "NO" : "YES") << "\n";


        for (int i=0; i<=cnt; i++) {
            si[i]=0, ki[i]=0;
            for (int j=0; j<2; j++) {
                while (q[i][j].size()>0) q[i][j].pop();
            }
        }
        ans=0, cnt=0, m.clear();
        baj=0;

    }
    return 0;
}
/*
1
4
2 4 5 24
1 4 6 11
*/