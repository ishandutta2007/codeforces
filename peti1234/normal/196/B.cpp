#include <bits/stdc++.h>

using namespace std;

const int c=1502;
bool s[c][c], v[c][c];
pair<int, int> ki[c][c];
int n, m, cnt;
bool jo;

void dfs(int i, int j, pair<int, int> tabla) {
    if (!s[i][j]) {
        return;
    }
    if (v[i][j]) {
        if (ki[i][j]!=tabla) {
            jo=1;
        }
        return;
    }
    v[i][j]=1;
    ki[i][j]=tabla;
    if (i==0) {
        i=n, tabla.first++;
    }
    if (i==n+1) {
        i=1, tabla.first--;
    }
    if (j==0) {
        j=m, tabla.second++;
    }
    if (j==m+1) {
        j=1, tabla.second--;
    }
    dfs(i-1, j, tabla), dfs(i+1, j, tabla), dfs(i, j-1, tabla), dfs(i, j+1, tabla);
}

int main(){
    cin >> n >> m;
    int kezdoi,kezdoj;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++){
            char c;
            cin>>c;
            if(c=='S'){
                s[i][j]=1;
                kezdoi=i;
                kezdoj=j;
            }
            else{
                if(c=='.')
                    s[i][j]=1;
                else
                    s[i][j]=0;
            }
        }
    }
    for (int i=1; i<=n; i++) {
        s[i][0]=s[i][m];
        s[i][m+1]=s[i][1];
    }
    for (int j=1; j<=m; j++) {
        s[0][j]=s[n][j];
        s[n+1][j]=s[1][j];
    }
    dfs (kezdoi, kezdoj, {0, 0});
    cout << (jo? "Yes" : "No") << "\n";
}