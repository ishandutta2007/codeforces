#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
int n;
vector < int > v[20][2];
int arr[N];
int ans[N];
void solve(int level , int x1 , int y1 , int x2 , int y2 , int sz){
    if(x2 < x1){
        return;
    }
    if(y2 < y1){
        return;
    }
    int mid = sz >> 1;
    for(int i = y1 ; i < y1 + mid ; ++i){
        v[level][0].push_back(i);
    }
    for(int i = y1 + mid ; i <= y2 ; ++i){
        v[level][1].push_back(i);
    }
    if(sz > 1){
        solve(level + 1 , x1 , y1 , x1 + mid - 1 , y1 + mid - 1 , mid);
        solve(level + 1 , x1 + mid , y1 + mid , x2 , y2 , sz - mid);
    }
}
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        ans[i] = 1e9 + 9;
    }
    for(int i = 0 ; i < 10 ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            v[i][(j >> i) & 1].push_back(j);
        }
    }
    for(int i = 0 ; i < 20 ; ++i){
        set < int > s1;
        set < int > s2;
        s1.clear();
        s2.clear();
        for(int a : v[i][0]){
            s1.insert(a);
        }
        for(int b : v[i][1]){
            s2.insert(b);
        }
        if(!v[i][0].empty()){
            printf("%d\n" , int(v[i][0].size()));
            for(int j = 0 ; j < v[i][0].size() ; ++j){
                printf("%d%c" , v[i][0][j] , " \n"[(j + 1) == v[i][0].size()]);
            }
            fflush(stdout);
            for(int i = 1 ; i <= n ; ++i){
                scanf("%d" , &arr[i]);
            }
            for(int i = 1 ; i <= n ; ++i){
                if(s1.find(i) == s1.end()){
                    ans[i] = min(ans[i] , arr[i]);
                }
            }
        }
        if(!v[i][1].empty()){
            printf("%d\n" , int(v[i][1].size()));
            for(int j = 0 ; j < v[i][1].size() ; ++j){
                printf("%d%c" , v[i][1][j] , " \n"[(j + 1) == v[i][1].size()]);
            }
            fflush(stdout);
            for(int i = 1 ; i <= n ; ++i){
                scanf("%d" , &arr[i]);
            }
            for(int i = 1 ; i <= n ; ++i){
                if(s2.find(i) == s2.end()){
                    ans[i] = min(ans[i] , arr[i]);
                }
            }
        }
    }
    printf("-1\n");
    for(int i = 1 ; i <= n ; ++i){
        printf("%d%c" , ans[i] , " \n"[i == n]);
    }
    fflush(stdout);
}