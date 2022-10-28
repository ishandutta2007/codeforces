#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
bool mark[N * 10];
int n , m;
int ans = 1e9;
int main(){
    cin >> n >> m;
    for(int i = 2 ; i <= n * 10 ; i += 2){
        mark[i] = 1;
    }
    for(int i = 3 ; i <= 10 * m ; i += 3){
        mark[i] = 1;
    }
    for(int i = 0 ; i < N * 10 ; ++i){
        if(!mark[i]){
            continue;
        }
        if(!n && !m){
            break;
        }
        if((i % 6) != 0){
            if((i & 1) == 0 && n >= 1){
                --n;
                ans = i;
            }
            else if((i % 3 == 0) && m >= 1){
                --m;
                ans = i;
            }
        }
        else{
            if(n + n <= m + m + m){
                --m;
                ans = i;
            }
            else{
                --n;
                ans = i;
            }
        }
    }
    printf("%d\n" , ans);
}