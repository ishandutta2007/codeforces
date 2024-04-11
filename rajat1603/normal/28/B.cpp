#include "bits/stdc++.h"
using namespace std;
const int N = 1e2 + 2;
int graph[N][N];
int arr[N];
int n;
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            graph[i][j] = n + 1;
        }
        graph[i][i] = 0;
        cin >> arr[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        int temp;
        cin >> temp;
        if(i + temp <= n){
            graph[i][i + temp] = 0;
            graph[i + temp][i] = 0;
        }
        if(i - temp >= 1){
            graph[i][i - temp] = 0;
            graph[i - temp][i] = 0;
        }
    }
    for(int k = 1 ; k <= n ; ++k){
        for(int i = 1 ; i <= n ; ++i){
            for(int j = 1 ; j <= n ; ++j){
                graph[i][j] = min(graph[i][j] , graph[i][k] + graph[k][j]);
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(graph[i][arr[i]] >= n + 1){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}