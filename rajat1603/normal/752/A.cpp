#include "bits/stdc++.h"
using namespace std;
int n , m , k;
int main(){
    cin >> n >> m >> k;
    for(int i = 1 ; i <= n ; ++i){
        int start = (i - 1) * 2 * m + 1;
        int finish = i * 2 * m;
        if(start <= k && finish >= k){
            for(int j = 1 ; j <= m ; ++j){
                int l = start + (j - 1) * 2;
                int r = start + j * 2 - 1;
                if(l <= k && k <= r){
                    printf("%d %d " , i , j);
                    if(k == l){
                        printf("L\n");
                    }
                    else{
                        printf("R\n");
                    }
                    return 0;
                }
            }
        }
    }
}