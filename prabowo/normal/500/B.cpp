#include<bits/stdc++.h>
using namespace std;

int n;
char a[505][505];
int per[505];
bool flag[505];

vector <int> tmpt[505];

void dfs(int x, int y){
    if (!flag[x]){
        flag[x] = true;
        tmpt[x].push_back(y);
        for (int i=0; i<n; i++){
            if (a[x][i] == '1') dfs(i, y);
        }
    }
}

int main(){
    scanf("%d", &n);
    int cnt[505]={};
    for (int i=0; i<n; i++){
        cin >> per[i];
    }
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    for (int i=0; i<n; i++) {memset(flag,0,sizeof(flag)); dfs(i, per[i]);}
    bool uda[505]={};
    for (int i=0; i<n; i++){
        sort(tmpt[i].begin(), tmpt[i].end());
        for (int j=0; j<tmpt[i].size(); j++){
            if (!uda[tmpt[i][j]]){
                uda[tmpt[i][j]] = true;
                printf("%d", tmpt[i][j]);
                break;
            }
        }
        if (i < n-1) printf(" ");
    }
    printf("\n");
    return 0;
}