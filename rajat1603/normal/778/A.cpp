#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
char a[N];
char b[N];
int arr[N];
int n;
int m;
int mark[N];
bool check(int mid){
    for(int i = 1 ; i <= n ; ++i){
        mark[i] = 1;
    }
    for(int i = 1 ; i <= mid ; ++i){
        mark[arr[i]] = 0;
    }
    int ptr = 1;
    for(int i = 1 ; i <= n ; ++i){
        if(mark[i]){
            if(a[i] == b[ptr]){
                ++ptr;
            }
        }
    }
    return ptr > m;
}
int main(){
    scanf("%s" , a + 1);
    n = strlen(a + 1);
    scanf("%s" , b + 1);
    m = strlen(b + 1);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    int l = 0;
    int r = n;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(check(mid)){
            l = mid;
        }
        else{
            r = mid - 1;
        }
    }
    printf("%d\n" , l);
}