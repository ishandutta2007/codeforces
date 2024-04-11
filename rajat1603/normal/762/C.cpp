#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
char a[N];
char b[N];
int n , m;
int lft[N];
int rgt[N];
int l , r;
void setmax(int ql , int qr){
    if(qr - ql + 1 < r - l + 1){
        l = ql;
        r = qr;
    }
}
int main(){
    scanf("%s" , a + 1);
    scanf("%s" , b + 1);
    n = strlen(a + 1);
    m = strlen(b + 1);
    lft[0] = 0;
    int idx = 1;
    for(int i = 1 ; i <= m ; ++i){
        while(idx <= n && a[idx] != b[i]){
            ++idx;
        }
        lft[i] = idx;
        ++idx;
        idx = min(idx , n + 1);
    }
    rgt[m + 1] = n + 1;
    idx = n;
    for(int i = m ; i >= 1 ; --i){
        while(idx >= 1 && a[idx] != b[i]){
            --idx;
        }
        rgt[i] = idx;
        --idx;
        idx = max(idx , 0);
    }
    l = 1;
    r = m;
    for(int i = 1 ; i <= m ; ++i){
        if(lft[i] <= n){
            setmax(i + 1 , m);
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        if(rgt[i] >= 1){
            setmax(1 , i - 1);
        }
    }
    idx = 1;
    for(int i = 1 ; i <= m ; ++i){
        if(lft[i] <= n){
            while(rgt[idx] <= lft[i]){
                ++idx;
            }
            setmax(i + 1 , idx - 1);
        }
    }
    if(r - l + 1 == m){
        printf("-\n");
    }
    else{
        for(int i = 1 ; i <= m ; ++i){
            if(i < l || i > r){
                printf("%c" , b[i]);
            }
        }
        printf("\n");
    }
}