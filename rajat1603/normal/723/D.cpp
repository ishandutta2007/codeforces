#include "bits/stdc++.h"
using namespace std;
const int N = 55;
const int dx[4] = {0 , 1 , 0 , -1};
const int dy[4] = {1 , 0 , -1 , 0};
int n , m , k;
string str[N];
bool visited[N][N];
vector < pair < int , pair < int , int > > > v;
int ans;
int cnt;
void dfs(int x , int y){
    ++cnt;
    for(int i = 0 ; i < 4 ; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!visited[nx][ny]){
            visited[nx][ny] = 1;
            dfs(nx , ny);
        }
    }
}
void start(int x , int y , int val){
    if(visited[x][y]){
        return;
    }
    cnt = 0;
    visited[x][y] = 1;
    dfs(x , y);
    if(val){
        v.emplace_back(make_pair(cnt , make_pair(x , y)));
    }
}
void fill(int x , int y){
    if(str[x][y] == '*'){
        return;
    }
    str[x][y] = '*';
    for(int i = 0 ; i < 4 ; ++i){
        fill(x + dx[i] , y + dy[i]);
    }
}
int main(){
    cin >> n >> m >> k;
    for(int i = 1 ; i <= n ; ++i){
        cin >> str[i];
        str[i] = "*" + str[i] + "*";
    }
    str[0] = "";
    for(int i = 0 ; i <= m + 1 ; ++i){
        str[0] += "*";
    }
    str[n + 1] = str[0];
    v.clear();
    ans = 0;
    memset(visited , 0 , sizeof(visited));
    for(int i = 0 ; i <= n + 1 ; ++i){
        for(int j = 0 ; j <= m + 1 ; ++j){
            if(str[i][j] == '*'){
                visited[i][j] = 1;
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        start(i , 1 , 0);
        start(i , m , 0);
    }
    for(int i = 1 ; i <= m ; ++i){
        start(1 , i , 0);
        start(n , i , 0);
    }
    for(int i = 2 ; i < n ; ++i){
        for(int j = 2 ; j < m ; ++j){
            start(i , j , 1);
        }
    }
    sort(v.begin() , v.end());
    for(int i = 0 ; i < v.size() - k ; ++i){
        ans += v[i].first;
        fill(v[i].second.first , v[i].second.second);
    }
    printf("%d\n" , ans);
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            printf("%c" , str[i][j]);
        }
        printf("\n");
    }
}