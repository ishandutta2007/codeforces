#include "bits/stdc++.h"
using namespace std;
const int N = 405;
int n , m;
char str[N][N];
int r , c;
char pat[N][N];
bitset < N > arr[N][26];
bitset < N > ans[N];
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 0 ; i < n ; ++i){
        scanf("%s" , str[i]);
    }
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            arr[i][str[i][j] - 'a'].set(j);
            ans[i].set(j);
        }
    }
    scanf("%d %d" , &r , &c);
    for(int i = 0 ; i < r ; ++i){
        scanf("%s" , pat[i]);
    }
    for(int i = 0 ; i < r ; ++i){
        for(int j = 0 ; j < c ; ++j){
            if(pat[i][j] != '?'){
                for(int k = 0 ; k < n ; ++k){
                    ans[(k + n - (i % n)) % n] &= (arr[k][pat[i][j] - 'a'] >> (j % m)) | (arr[k][pat[i][j] - 'a'] << (m - (j % m)));
                }
            }
        }
    }
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j){
            printf("%c" , ans[i][j] + '0');
        }
        printf("\n");
    }
}