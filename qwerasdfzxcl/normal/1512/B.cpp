#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
char matrix[404][404];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n;i++) scanf("%s", matrix[i]);
    vector<pair<int, int>> v;
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (matrix[i][j]=='*') v.push_back(make_pair(i, j));
        }
    }
    if (v[0].first == v[1].first){
        int x = -1;
        if (!v[0].first) x = 1;
        matrix[v[0].first+x][v[0].second]='*';
        matrix[v[1].first+x][v[1].second]='*';
    }
    else if (v[0].second==v[1].second){
        int x = -1;
        if (!v[0].second) x = 1;
        matrix[v[0].first][v[0].second+x]='*';
        matrix[v[1].first][v[1].second+x]='*';
    }
    else{
        matrix[v[1].first][v[0].second]='*';
        matrix[v[0].first][v[1].second]='*';
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++) printf("%c", matrix[i][j]);
        printf("\n");
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}