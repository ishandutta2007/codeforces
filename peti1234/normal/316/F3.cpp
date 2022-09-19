#include <bits/stdc++.h>

using namespace std;

const int c=1722;
int n, m, id[c][c], kom[c][c], db[c*c], cnt;
int xd[]={0, 0, 1, -1};
int yd[]={1, -1, 0, 0};
bool v[c][c], t[c][c];
bool  spec(int a, int b) {
    return kom[a+3][b+3]-kom[a+3][b-4]-kom[a-4][b+3]+kom[a-4][b-4]<=15;
}
void dfs1(int a, int b) {
    if (id[a][b] || !t[a][b]) return;
    id[a][b]=cnt;
    for (int k=0; k<4; k++) {
        dfs1(a+xd[k], b+yd[k]);
    }
}

void dfs2(int a, int b){
	if (!t[a][b] || v[a][b]) return;
	if (!spec(a, b)){
		return;
	}
	v[a][b]=true;
    for (int k=0; k<4; k++) {
        dfs2(a+xd[k], b+yd[k]);
    }
}
int main() {
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> t[i+5][j+5];
        }
    }
    n+=10, m+=10;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            kom[i][j]=kom[i-1][j]+kom[i][j-1]-kom[i-1][j-1]+t[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (t[i][j] && !id[i][j]) {
                cnt++;
                dfs1(i, j);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (t[i][j] && !v[i][j] && spec(i, j)) {
                db[id[i][j]]++;
                dfs2(i, j);
            }
        }
    }
    sort(db+1, db+cnt+1);
    cout << cnt << "\n";
    for (int i=1; i<=cnt; i++) {
        cout << db[i] << " ";
    }
    cout << "\n";
	return 0;
}