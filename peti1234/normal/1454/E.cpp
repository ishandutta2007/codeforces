#include<bits/stdc++.h>

using namespace std;
const int c=200002;
vector<int> sz[c];
long long w, n, sum, cnt, f[c];
bool v[c], v2[c], kor[c];
void dfs(int a) {
    v[a]=true;
    for (int x:sz[a]) {
        if (!v[x]) f[x]=a, dfs(x);
        else if (f[a]!=x && !kor[a]) {
            kor[a]=true;
            int aa=a;
            while(aa!=x) {
                aa=f[aa];
                kor[aa]=true;
            }
        }
    }
}
int dfs2(int a) {
    v2[a]=true;
    int ans=1;
    for (int x:sz[a]) {
        if (!kor[x] && !v2[x]) {
            ans+=dfs2(x);
        }
    }
    return ans;
}
int main() {
    cin >> w;
    while(w--) {
        cin >> n, sum=n*(n-1);
        for (int i=1; i<=n; i++) {
            sz[i].clear();
            kor[i]=0, f[i]=0, v[i]=0, v2[i]=0;
        }
        for (int i=1; i<=n; i++) {
            int a, b; cin >> a >> b;
            sz[a].push_back(b), sz[b].push_back(a);
        }
        dfs(1);
        for (int i=1; i<=n; i++) {
            if (kor[i]) {
                cnt=dfs2(i);
                sum-=cnt*(cnt-1)/2;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}