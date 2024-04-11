#include "bits/stdc++.h"

using namespace std;

const int N = 501;
const int M = 1001;
int n , m;
int w[N];
int arr[M];
int order[N];
bool mark[N] = {0};
int cur = 0;
int ans = 0;
int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i){
        cin >> w[i];
    }
    for(int i = 1 ; i <= m ; ++i){
        cin >> arr[i];
        if(!mark[arr[i]]){
            order[++cur] = arr[i];
            mark[arr[i]] = 1;
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        for(int j = 1 ; j <= cur ; ++j){
            if(order[j] == arr[i]){
                for(int k = j - 1 ; k >= 1 ; --k){
                    swap(order[k] , order[k + 1]);
                }
                break;
            }
            else{
                ans += w[order[j]];
            }
        }
    }
    cout << ans;
}