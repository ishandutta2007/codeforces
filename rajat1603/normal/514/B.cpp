#include "bits/stdc++.h"

using namespace std;

const int N = 1001;
int n;
int x[N];
int y[N];
bool visited[N];
int ans = 0;
int main(){
    cin >> n;
    for(int i = 0 ; i <= n ; ++i){
        cin >> x[i] >> y[i];
        visited[i] = false;
    }
    for(int i = 1 ; i <= n ; ++i){
        if(!visited[i]){
            ++ans;
            visited[i] = true;
            for(int j = 1 ; j <= n ; ++j){
                if((x[i] - x[0])*(y[j] - y[0]) == (x[j] - x[0])*(y[i] - y[0])){
                    visited[j] = true;
                }
            }
        }
    }
    cout << ans;
}