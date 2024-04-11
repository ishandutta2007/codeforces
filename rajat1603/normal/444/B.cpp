#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int IDK = 450 + (rand() % 50);
int n , d , x;
int a[N] , b[N] , c;
int pos[N];
int arr[N];
int siz;
int getnextX(){
    return x = (37LL * x + 10007) % 1000000007;
}
int main(){
    scanf("%d %d %d" , &n , &d , &x);
    for(int i = 0 ; i < n ; ++i){
        a[i] = i + 1;
        swap(a[i] , a[getnextX() % (i + 1)]);
    }
    for(int i = 0 ; i < n ; ++i){
        b[i] = i < d;
        pos[a[i]] = i;
        swap(b[i] , b[getnextX() % (i + 1)]);
    }
    siz = 0;
    for(int i = 0 ; i < n ; ++i){
        if(b[i]){
            arr[++siz] = i;
        }
        c = 0;
        if(siz < IDK){
            for(int j = 1 ; j <= siz ; ++j){
                c = max(c , a[i - arr[j]]);
            }
        }
        else{
            for(int k = n ; k >= 1 ; --k){
                int j = pos[k];
                if(j <= i && b[i - j]){
                    c = k;
                    break;
                }
            }
        }
        printf("%d\n" , c);
    }
}