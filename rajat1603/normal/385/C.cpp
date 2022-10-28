#include "bits/stdc++.h"
using namespace std;
inline int scan(){
    char c = getchar();
    int x = 0;
    while(c < '0' || c > '9'){
        c = getchar();
    }
    while(c >= '0' && c <= '9'){
        x = (x<<1) + (x<<3) + c - '0';
        c = getchar();
    }
    return x;
}
const int N = 10000001; // 3162
int prime[N] = {0};
int cnt[N];
int n , q;
int main(){
    for(int i = 2 ; i <= 3162 ; ++i){
        if(!prime[i]){
            for(int j = i * i ; j < N ; j += i){
                if(!prime[j])
                    prime[j] = i;
            }
        }
    }
    n = scan();
    while(n--){
        int temp = scan();
        int prev = -1;
        while(temp > 1){
            if(!prime[temp]){
                if(temp != prev)
                    ++cnt[temp];
                break;
            }
            ++cnt[prime[temp]];
            prev = prime[temp];
            while(prime[temp] == prev)
                temp /= prime[temp];
        }
    }
    for(int i = 3 ; i < N ; ++i){
        cnt[i] += cnt[i-1];
    }
    q = scan();
    while(q--){
        int l = scan() , r = scan();
        printf("%d\n",cnt[min(N-1,r)] - cnt[min(N-1 , l-1)]);
    }
}