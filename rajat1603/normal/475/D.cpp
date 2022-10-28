#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 17;
int n;
int arr[N];
int st[LN][N];
int logtable[N];
map < int , long long > m;
int q;
int x;
void build(){
    logtable[0] = -1;
    for(int i = 1 ; i <= n ; ++i){
        st[0][i] = arr[i];
        logtable[i] = logtable[i >> 1] + 1;
    }
    for(int i = 1 ; i < LN ; ++i){
        for(int j = 1 ; j + (1 << i) - 1 <= n ; ++j){
            st[i][j] = __gcd(st[i - 1][j] , st[i - 1][j + (1 << (i - 1))]);
        }
    }
}
int query(int l , int r){
    int k = logtable[r - l + 1];
    int ql = st[k][l];
    int qr = st[k][r - (1 << k) + 1];
    return __gcd(ql , qr);
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    build();
    for(int i = 1 ; i <= n ; ++i){
        for(int j = i ; j <= n ;){
            int val = query(i , j);
            if(query(i , n) == val){
                m[val] += n - j + 1;
                j = n + 1;
            }
            else{
                int l = j;
                int r = n;
                while(l < r){
                    int mid = l + r >> 1;
                    if(query(i , mid) == val){
                        l = mid + 1;
                    }
                    else{
                        r = mid;
                    }
                }
                m[val] += r - j;
                j = r;
            }
        }
    }
    scanf("%d" , &q);
    while(q--){
        scanf("%d" , &x);
        printf("%lld\n" , m[x]);
    }
}