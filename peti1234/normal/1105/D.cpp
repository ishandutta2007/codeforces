#include <bits/stdc++.h>

using namespace std;
int t[1001][1001];
deque<pair<int, int> > q[1001];
int qq;
int n, m, p;
int s[10];
int w[10];
int main()
{
    cin >> n >> m >> p;
    for (int i=1; i<=p; i++) {
        cin >> s[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char c;
            cin >> c;
            if (c=='#') {
                t[i][j]=-1;
            } else if(c!='.') {
                int x=c-'0';
                t[i][j]=x;
                q[x].push_back({i, j});
                if (q[x].size()==1) {
                    qq++;
                }
            }
        }
    }
    while(qq>0) {
        for (int i=1; i<=p; i++) {
            for (int j=1; j<=s[i]; j++) {
                int k=q[i].size();
                if (k==0) {
                    break;
                }
                for (int l=1; l<=k; l++) {
                    int fi=q[i].front().first;
                    int se=q[i].front().second;
                    q[i].pop_front();
                    if(fi-1>=1 && t[fi-1][se]==0) {
                        t[fi-1][se]=i;
                        q[i].push_back({fi-1, se});
                    }
                    if(fi+1<=n && t[fi+1][se]==0) {
                        t[fi+1][se]=i;
                        q[i].push_back({fi+1, se});
                    }
                    if(se-1>=1 && t[fi][se-1]==0) {
                        t[fi][se-1]=i;
                        q[i].push_back({fi, se-1});
                    }
                    if(se+1<=m && t[fi][se+1]==0) {
                        t[fi][se+1]=i;
                        q[i].push_back({fi, se+1});
                    }
                }
                if (q[i].size()==0) {
                    qq--;
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            int x=t[i][j];
            if (x!=-1) {
                w[x]++;
            }
        }
    }
    for (int i=1; i<=p; i++) {
        cout << w[i] << " ";
    }
    return 0;
}