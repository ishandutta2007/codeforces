#include <bits/stdc++.h>

using namespace std;

const int c=495;
int w, sum, cnt, si[c][c], ans[c][c];
vector<int> t;
map<int, vector<int>> m;
map<vector<int>, int> m2;
vector<pair<int, int> > elore[c][c], vissza[c][c];
queue<pair<int, int> > q;
bool v[c][c];
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i=0; i<59049; i++) {
        int s=i;
        sum=0;
        t.clear();
        for (int j=0; j<5; j++) {
            t.push_back(s%9);
            sum+=t[j];
            s/=9;
        }
        if (sum==8) {
            m[cnt]=t;
            m2[t]=cnt;
            cnt++;
        }
    }
    int lep=0;
    for (int i=0; i<c; i++) {
        for (int j=0; j<c; j++) {
            vector<int> a=m[i], b=m[j], kov;
            for (int x=1; x<5; x++) {
                for (int y=1; y<5; y++) {
                    if (a[x] && b[y]) {

                        kov=a;
                        kov[x]--, kov[(x+y)%5]++;
                        int skov=m2[kov];
                        si[i][j]++;
                        elore[i][j].push_back({j, skov});
                        vissza[j][skov].push_back({i, j});
                        lep++;
                    }
                }
            }
            if (!si[i][j]) {
                q.push({i, j});
            }
        }
    }
    while (q.size()>0) {
        int fi=q.front().first, se=q.front().second;
        q.pop();
        if (v[fi][se]) {
            continue;
        }
        v[fi][se]=1;
        if (!fi) {
            ans[fi][se]=1;
        } else {
            ans[fi][se]=-1;
            for (auto kov:elore[fi][se]) {
                if (ans[kov.first][kov.second]==-1) {
                    ans[fi][se]=1;
                }
            }
        }
        for (auto vi:vissza[fi][se]) {
            int x=vi.first, y=vi.second;
            si[x][y]--;
            if (!si[x][y] || ans[fi][se]==-1) {
                q.push({x, y});
            }
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> w;
    while (w--) {
        vector<int> x, y;
        x.resize(5), y.resize(5);
        int fl;
        cin >> fl;
        for (int i=0; i<8; i++) {
            int ert;
            cin >> ert;
            x[ert]++;
        }
        for (int i=0; i<8; i++) {
            int ert;
            cin >> ert;
            y[ert]++;
        }
        int a=m2[x], b=m2[y];
        if (fl==0) {
            fl=1;
        } else {
            swap(a, b);
            fl=-1;
        }
        int ert=ans[a][b]*fl;
        if (ert==1) {
            cout << "Alice\n";
        }
        if (ert==0) {
            cout << "Deal\n";
        }
        if (ert==-1) {
            cout << "Bob\n";
        }
    }
    return 0;
}