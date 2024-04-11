#include "bits/stdc++.h"
using namespace std;
const int N = 4e5 + 5;
int n , m;
int a[N];
int b[N];
int arr[N];
int siz;
int lcp[N];
int ans;
int main(){
    scanf("%d %d" , &n , &m);
    if(m == 1){
        printf("%d\n" , n);
        return 0;
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , a + i);
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d" , b + i);
    }
    for(int i = 2 ; i <= m ; ++i){
        arr[++siz] = b[i] - b[i - 1];
    }
    arr[++siz] = 2e9 + 9;
    for(int i = 2 ; i <= n ; ++i){
        arr[++siz] = a[i] - a[i - 1];
    }
    lcp[0] = 0;
    lcp[1] = 0;
    for(int i = 2 ; i <= siz ; ++i){
        int idx = lcp[i - 1];
        while(idx){
            if(arr[idx + 1] == arr[i]){
                break;
            }
            idx = lcp[idx];
        }
        if(arr[idx + 1] == arr[i]){
            lcp[i] = idx + 1;
        }
        else{
            lcp[i] = 0;
        }
    }
    for(int i = m + 1 ; i <= siz ; ++i){
        if(lcp[i] == m - 1){
            ++ans;
        }
    }
    printf("%d\n" , ans);
}