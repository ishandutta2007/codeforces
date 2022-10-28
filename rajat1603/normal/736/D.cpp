#include "bits/stdc++.h"
using namespace std;
const int N = 2e3 + 3;
const int M = 5e5 + 5;
int n , m;
int a[M] , b[M];
bitset < N > inv[N];
bitset < N > ide[N];
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , a + i , b + i);
        ide[a[i]].set(b[i]);
    }
    for(int i = 1 ; i <= n ; ++i){
        inv[i].set(i);
    }
    for(int i = 1 ; i <= n ; ++i){
        if(!ide[i].test (i)){
            for(int j = i + 1 ; j <= n ; ++j){
                if(ide[j].test(i)){
                    swap(ide[i] , ide[j]);
                    swap(inv[i] , inv[j]);
                    break;
                }
            }
        }
        for(int j = i + 1 ; j <= n ; ++j){
            if(ide[j].test(i)){
                ide[j] ^= ide[i];
                inv[j] ^= inv[i];
            }
        }
    }
    for(int i = n ; i >= 1 ; --i){
        for(int j = i - 1 ; j >= 1 ; --j){
            if(ide[j].test(i)){
                ide[j] ^= ide[i];
                inv[j] ^= inv[i];
            }
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        puts(inv[b[i]].test(a[i]) ? "NO" : "YES");
    }
}