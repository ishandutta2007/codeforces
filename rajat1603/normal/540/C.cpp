#include "bits/stdc++.h"
using namespace std;
const int N = 505;
int n , m;
string arr[N];
bool visited[N][N] = {0};
const int dx[4] = {0 , 1 , 0 , -1};
const int dy[4] = {1 , 0 , -1 , 0};
int sx , sy;
int ex , ey;
bool check(int x , int y){
    return (arr[x][y] == '.');
}
int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
        arr[i] = "X" + arr[i] + "X";
    }
    for(int i = 1 ; i <= m + 2 ; ++i){
        arr[0] += "X";
        arr[n + 1] += "X";
    }
    cin >> sx >> sy;
    cin >> ex >> ey;
    if(make_pair(ex , ey) == make_pair(sx , sy)){
        for(int i = 0 ; i < 4 ; ++i){
            if(arr[sx + dx[i]][sy + dy[i]] == '.'){
                cout << "YES";
                return 0;
            }
        }
        cout << "NO";
    }
    else{
        if(abs(sx - ex) + abs(sy - ey) == 1){
            if(arr[ex][ey] == 'X'){
                cout << "YES";
            }
            else{
                for(int i = 0 ; i < 4 ; ++i){
                    if(arr[ex + dx[i]][ey + dy[i]] == '.'){
                        cout << "YES";
                        return 0;
                    }
                }
                cout << "NO";
            }
        }
        else{
            queue < pair < int , int > > q;
            q.push(make_pair(sx , sy));
            visited[sx][sy] = 1;
            while(!q.empty()){
                auto node = q.front();
                q.pop();
                for(int i = 0 ; i < 4 ; ++i){
                    int x = node.first + dx[i];
                    int y = node.second + dy[i];
                    if(x == ex && y == ey){
                        visited[ex][ey] = 1;
                        break;
                    }
                    if(check(x , y) && !visited[x][y]){
                        visited[x][y] = 1;
                        q.push(make_pair(x , y));
                    }
                }
            }
            if(visited[ex][ey]){
                if(arr[ex][ey] == 'X'){
                    cout << "YES";
                    return 0;
                }
                int cnt = 0;
                for(int i = 0 ; i < 4 ; ++i){
                    if(arr[ex + dx[i]][ey + dy[i]] == '.'){
                        ++cnt;
                    }
                }
                if(cnt >= 2){
                    cout << "YES";
                }
                else{
                    cout << "NO";
                }
            }
            else{
                cout << "NO";
            }
        }
    }
}