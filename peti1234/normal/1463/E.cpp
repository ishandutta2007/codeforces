#include <bits/stdc++.h>

using namespace std;
const int c=300002;
int n, k, kezd, p[c], el[c], kov[c], ki[c], veg[c], cnt;
vector<int> kor[c], sz[c];
vector<int> sol;
bool v[c], baj;
int holvan(int a) {
    if (!ki[a]) {
        return a;
    }
    int x=holvan(ki[a]);
    ki[a]=x;
    return x;
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        ki[b]=a;
    }
}
void kdfs(int a) {
    //cout << "kdfs " << a << endl;
    v[a]=true;
    for (int x:kor[a]) {
        if (!v[x]) {
            kdfs(x);
        }
    }
    cnt++;
    veg[a]=cnt;
}
void dfs(int a) {
    v[a]=true;
    for (int x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
    cnt++;
    veg[a]=cnt;
    sol.push_back(a);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> p[i];
        if (!p[i]) {
            kezd=i;
        } else {
            kor[p[i]].push_back(i);
            //cout << "el " << p[i] << " " << i << endl;
        }
    }
    for (int i=1; i<=k; i++) {
        int a, b; cin >> a >> b;
        if (kov[a] || el[b]) {
            baj=1;
        }
        kov[a]=b, el[b]=a;
        kor[a].push_back(b);
        //cout << "el " << a << " " << b << endl;
        unio(a, b);
    }
    kdfs(kezd);
    for (int i=1; i<=n; i++) {
        for (int j:kor[i]) {
            if (veg[i]<veg[j]) {
                baj=1;
            }
        }
    }
    //cout << "elso resz " << baj << endl;
    cnt=0;
    for (int i=1; i<=n; i++) {
        veg[i]=0, v[i]=0;
        if (p[i]) {
            sz[holvan(p[i])].push_back(holvan(i));
        }
    }
    dfs(kezd);
    for (int i=1; i<=n; i++) {
        for (int j:sz[i]) {
            if (veg[i]<veg[j]) {
                baj=1;
            }
        }
    }
    if (baj) {
        cout << 0 << "\n";
        return 0;
    }
    reverse(sol.begin(), sol.end());
    for (int x:sol) {
        int y=x;
        while(y) {
            cout << y << " ";
            y=kov[y];
        }
    }
    return 0;
}