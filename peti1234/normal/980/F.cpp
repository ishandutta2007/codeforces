#include <bits/stdc++.h>

using namespace std;
const int c=500005;
int n, m, k, fel[c], h[c], szint[c];
int hid[c], hid2[c], szabad[c], spec[c], ans[c];
vector<int> sz[c], kor[c];
bool v[c];
queue<int> q;
void dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            szint[x]=szint[a]+1;
            fel[x]=a;
            dfs(x);
        } else if (szint[a]>szint[x]+1) {
            k++;
            int pos=a;
            while (szint[pos]>=szint[x]) {
                kor[k].push_back(pos);
                h[pos]=k;
                pos=fel[pos];
            }
        }
    }
}
bool jo(int a, int b) {
    return (!h[a] || h[a]!=h[b]);
}
void dfs2(int a) {
    for (auto x:sz[a]) {
        if (fel[x]==a) {
            dfs2(x);
            if (jo(a, x)) {
                hid2[a]=max(hid2[a], szabad[x]+1);
                if (hid2[a]>hid[a]) {
                    swap(hid[a], hid2[a]);
                }
            }
            szabad[a]=max(szabad[a], szabad[x]+1);
        }
    }
}
int tav(int a, int b, int len, int dir) {
    if (dir) {
        swap(a, b);
    }
    return (b+len-a)%len;
}
void dfs3(int a) {
    if (h[a] && h[a]!=h[fel[a]]) {
        int id=h[a], len=kor[id].size();
        deque<int> q;
        for (int dir=0; dir<2; dir++) {
            for (int s=0; s<2; s++) {
                for (int ii=0; ii<len; ii++) {
                    int i=(dir==0 ? ii : len-1-ii);
                    int val=kor[id][i];
                    while (q.size()>0 && 2*tav(q.front(), i, len, dir)>len) {
                        q.pop_front();
                    }
                    if (q.size()>0) {
                        spec[val]=max(spec[val], hid[kor[id][q.front()]]+tav(q.front(), i, len, dir));
                    }
                    while (q.size()>0 && hid[val]>hid[kor[id][q.back()]]+tav(q.back(), i, len, dir)) {
                        q.pop_back();
                    }
                    q.push_back(i);
                }
            }
            q.clear();
        }
    }
    ans[a]=max(hid[a], spec[a]);
    for (auto x:sz[a]) {
        if (fel[x]==a) {
            if (jo(a, x)) {
                int ert=0;
                if (hid[a]!=szabad[x]+1) {
                    ert=ans[a];
                } else {
                    ert=max(hid2[a], spec[a]);
                }
                hid2[x]=max(hid2[x], ert+1);
                if (hid2[x]>hid[x]) {
                    swap(hid[x], hid2[x]);
                }
            }
            dfs3(x);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        sz[a].push_back(b), sz[b].push_back(a);
    }
    szint[1]=1;
    dfs(1);
    for (int i=2; i<=n; i++) {
        fel[i]=0;
    }
    q.push(1);
    while (q.size()>0) {
        int a=q.front();
        q.pop();
        for (auto x:sz[a]) {
            if (x!=1 && !fel[x]) {
                fel[x]=a;
                q.push(x);
            }
        }
    }

    dfs2(1);
    dfs3(1);

    for (int i=1; i<=n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}