#include <bits/stdc++.h>
#define int long long
using namespace std;
const int p = 998244353;
int A[500005];
int power(int a, int b, int c) {
    a %= c;
    if(b==0) return 1;
    if(b==1) return a;
    if(a==0) return 0;
    if(a==1) return 1;
    if(b%2==0) {
        int k = power(a, b/2, c);
        return k * k % c;
    }
    if(b % 2 == 1) {
        int k = power(a, b-1, c);
        return k * a % c;
    }
}
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
//vector<vector<int> > adj;

signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    int i, j, k;
    while(t--) {
        int N, M;
        cin >> N >> M;
        /*
        adj.clear();
        adj.resize(N*M);
        */
        vector<string> s;
        s.resize(N);
        for(i=0;i<N;i++) cin >> s[i];
        int px, py;
        for(i=0;i<N;i++) {
            for(j=0;j<M;j++) {
                if(s[i][j]=='L') {
                    px = i;
                    py = j;
                }
                if(s[i][j]=='#') continue;
                /*
                int cnt = 0;
                for(k=0;k<4;k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if(x>=0&&x<N&&y>=0&&y<M&&s[x][y]!='#') {
                        cnt++;
                    }
                }
                if(cnt <= 2) {
                    for(k=0;k<4;k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(x>=0&&x<N&&y>=0&&y<M&&s[x][y]!='#') {
                            adj[M*x+y].push_back(M*i+j);
                        }
                    }
                }
                */
            }
        }
        vector<bool> vis;
        vis.resize(N*M);
        queue<int> Q;
        Q.push(M*px+py);
        while(!Q.empty()) {
            int c = Q.front();
            //cout << "bfsing : " << c/M << ' ' << c % M << '\n';
            Q.pop();
            if(vis[c]) continue;
            vis[c] = true;
            for(int k2=0;k2<4;k2++) {
                int x3 = c / M + dx[k2], y3 = c % M + dy[k2];
                if(x3>=0&&x3<N&&y3>=0&&y3<M&&s[x3][y3]=='.'&&!vis[M*x3+y3]) {
                    int n = M*x3 + y3;
                    int x = n / M, y = n % M;
                    int cnt = 0;
                    for(k=0;k<4;k++) {
                        int x2 = x + dx[k];
                        int y2 = y + dy[k];
                        if(x2>=0&&x2<N&&y2>=0&&y2<M&&s[x2][y2]=='.'&&!vis[M*x2+y2]) {
                            cnt++;
                        }
                    }
                    if(cnt <= 1) Q.push(n);
                }
            }
        }
        for(i=0;i<N;i++) {
            for(j=0;j<M;j++) {
                if(s[i][j]=='.'&&vis[M*i+j]) cout << '+';
                else cout << s[i][j];
            }
            cout << '\n';
        }
    }
}