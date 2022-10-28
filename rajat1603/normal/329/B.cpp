#include "bits/stdc++.h"
using namespace std;
const int N = 1005;
const int dx[4] = {0 , 1 , 0 , -1};
const int dy[4] = {1 , 0 , -1 , 0};
string arr[N];
int n , m;
int dist[N][N];
int main(){
    cin >> n >> m;
    memset(dist , -1 , sizeof(dist));
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
        arr[i] = " " + arr[i];
    }
    queue < pair < int , int > > q;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            if(arr[i][j] == 'E'){
                q.push(make_pair(i , j));
                dist[i][j] = 0;
                break;
            }
        }
    }
    while(!q.empty()){
        pair < int , int > node = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; ++i){
            pair < int , int > temp = make_pair(node.first + dx[i] , node.second + dy[i]);
            if(temp.first >= 1 && temp.first <= n && temp.second >= 1 && temp.second <= m && arr[temp.first][temp.second] != 'T' && dist[temp.first][temp.second] == -1){
                dist[temp.first][temp.second] = dist[node.first][node.second] + 1;
                q.push(temp);
            }
        }
    }
    int mx = -1;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            if(arr[i][j] == 'S'){
                mx = dist[i][j];
                break;
            }
        }
    }
    int ans = 0;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            if(arr[i][j] > '0' && arr[i][j] <= '9' && dist[i][j] != -1 && dist[i][j] <= mx){
                ans += arr[i][j] - '0';
            }
        }
    }
    cout << ans;
}