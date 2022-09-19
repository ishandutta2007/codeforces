#include <bits/stdc++.h>

using namespace std;
const int c=202;
typedef long long ll;
int n, p[c], o[c];
ll t[c];
bool v[c][c], qq[c];
int kor(int a)
{
    for (int i=1; i<=n; i++) {
        qq[i]=p[i]=o[i]=0;;
    }
    queue<pair<int, int> > q;
    q.push({a, 1});
    int mini=INT_MAX;
    while(q.size()>0) {
        int fi=q.front().first, se=q.front().second;
        q.pop();
        if (!qq[fi]) {
            qq[fi]=true;
            for (int i=1; i<=n; i++) {
                if (v[fi][i]) {
                    if (p[i]) {
                        if (o[fi]!=i) {
                            mini=min(mini, p[fi]+p[i]-1);
                        }
                    } else {
                        q.push({i, se+1});
                        o[i]=fi;
                        p[i]=se+1;
                    }
                }
            }
        }
    }
    return mini;
}
int main()
{
    cin >> n;
    int si=1;
    for (int i=1; i<=n; i++) {
        ll x;
        cin >> x;
        if (x) {
            t[si]=x;
            si++;
        }
        if (si>=200) {
            cout << 3 << "\n";
            return 0;
        }
    }
    si--;
    n=si;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i!=j && t[i]&t[j]) {
                v[i][j]=true;
            }
        }
    }
    int mini=100;
    for (int i=1; i<=n; i++) {
        mini=min(mini, kor(i));
    }
    if (mini==100) {
        cout << -1 << "\n";
    } else {
        cout << mini << "\n";
    }
    return 0;
}