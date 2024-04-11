#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, kezd, kezd2, l1, l2;
int szint[c], kozos[c], kulon[c], cs1[c], cs2[c], kozosv, kulonv, cs[4];
vector<int> sz[c];
bool v[c], jo[c];
bool valt(int a, int b, int c, int d) {
    return (a>c || (a==c && b>d));
}
void dfs(int a) {
    v[a]=true;
    if (sz[a].size()>=3) {
        jo[a]=1;
    }
    int pos1=a, pos2=a, spec1=a, spec2=a;
    cs1[a]=a;
    for (int x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            dfs(x);
            if (jo[x]) {
                jo[a]=true;
                if (valt(kozos[x], kulon[x], kozos[pos2], kulon[pos2])) {
                    pos2=x;
                }
                if (valt(kozos[pos2], kulon[pos2], kozos[pos1], kulon[pos1])) {
                    swap(pos1, pos2);
                }
            } else {
                if (kulon[x]>kulon[spec2]) {
                    spec2=x;
                }
                if (kulon[spec2]>kulon[spec1]) {
                    swap(spec1, spec2);
                }
            }
        }
    }
    if (jo[a]) {
        int s1=kozos[pos1]+kozos[pos2], s2=kulon[pos1]+kulon[pos2];
        if (pos2!=a) {
            if (valt(s1, s2, kozosv, kulonv)) {
            //if (s1>kozosv || (s1==kozosv && s2>kulonv)) {
                kozosv=s1, kulonv=s2;
                cs[0]=cs1[pos1], cs[1]=cs1[pos2], cs[2]=cs2[pos1], cs[3]=cs2[pos2];
            }
        } else {
            s1=kozos[pos1], s2=kulon[pos1]+kulon[spec1]+kulon[spec2];
            if (valt(s1, s2, kozosv, kulonv)) {
                kozosv=s1, kulonv=s2;
                cs[0]=cs1[pos1], cs[1]=cs1[spec1], cs[2]=cs2[pos1], cs[3]=cs1[spec2];
            }
        }
        if (s1) {
            kozos[a]=kozos[pos1]+1, kulon[a]=kulon[pos1]+2;
            cs1[a]=cs1[pos1], cs2[a]=cs2[pos1];
        } else {
            kozos[a]=1, kulon[a]=kulon[spec1]+kulon[spec2]+2;
            cs1[a]=cs1[spec1], cs2[a]=cs1[spec2];
        }
    } else {
        kulon[a]=kulon[spec1]+1, cs1[a]=cs1[spec1];
    }
}
int main()
{
    cin >> n;
    for (int i=1; i<n; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    for (int i=1; i<=n; i++) {
        int si=sz[i].size();
        if (si==1) {
            if (!l1) {
                l1=i;
            } else {
                l2=i;
            }
        }
        if (si>=3) {
            if (!kezd) {
                kezd=i;
            } else {
                kezd2=i;
            }
        }
    }
    if (!kezd) {
        int x=sz[l1][0], a=sz[x][0], b=sz[x][1];
        if (a==l1) {
            a=b;
        }
        cout << l1 << " " << x << "\n" << a << " " << l2 << "\n";
        return 0;
    }
    dfs(kezd);
    if (!kezd2) {
        vector<pair<int, int> > s;
        for (int i=1; i<=n; i++) {
            s.push_back({szint[i], i});
        }
        sort(s.rbegin(), s.rend());
        cout << s[0].second << " " << s[1].second << "\n" << s[2].second << " " << s[3].second << "\n";
        return 0;
    }
    cout << cs[0] << " " << cs[1] << "\n" << cs[2] << " " << cs[3] << "\n";
    return 0;
}