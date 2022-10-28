#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int a[N];
int b[N];
int x , y;
int mxx , myy;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , a + i , b + i);
    }
    a[n + 1] = 1e9 + 9;
    b[n + 1] = 1e9 + 9;
    for(int i = 1 ; i <= n ; ++i){
        if(a[x + 1] < b[y + 1]){
            ++x;
        }
        else{
            ++y;
        }
    }
    mxx = x;
    myy = y;
    for(int k = 1 ; k + k <= n ; ++k){
        if(x < k){
            ++x;
            --y;
        }
        if(y < k){
            ++y;
            --x;
        }
        mxx = max(mxx , x);
        myy = max(myy , y);
    }
    for(int i = 1 ; i <= n ; ++i){
        printf("%c" , char('0' + (i <= mxx)));
    }
    printf("\n");
    for(int i = 1 ; i <= n ; ++i){
        printf("%c" , char('0' + (i <= myy)));
    }
    printf("\n");
}