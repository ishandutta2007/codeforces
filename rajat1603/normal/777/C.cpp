#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
vector < int > arr[N];
int mx[N];
int nx[N];
int q;
int l , r;
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        arr[i].resize(m + 1);
        for(int j = 1 ; j <= m ; ++j){
            scanf("%d" , &arr[i][j]);
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        nx[i] = n;
    }
    mx[n] = n;
    for(int i = n - 1 ; i >= 1 ; --i){
        for(int j = 1 ; j <= m ; ++j){
            if(arr[i + 1][j] < arr[i][j]){
                nx[j] = i;
            }
            mx[i] = max(mx[i] , nx[j]);
        }
    }
    scanf("%d" , &q);
    while(q--){
        scanf("%d %d" , &l , &r);
        puts(mx[l] >= r ? "Yes" : "No");
    }
}