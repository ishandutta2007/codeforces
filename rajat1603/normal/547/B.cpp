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
const int N = 2e5 + 5;
int l[N];
int arr[N];
int s[N];
int h = 0;
int n;
int mx[N] = {0};
#define push(x) s[++h] = x
#define top() s[h]
#define pop() --h
int main(){
    n = scan();
    for(int i = 1 ; i <= n ; ++i){
        arr[i] = scan();
    }
    arr[0] = 0;
    push(0);
    for(int i = 1 ; i <= n ; ++i){
        while(arr[top()] >= arr[i]){
            pop();
        }
        l[i] = top();
        push(i);
    }
    h = 0;
    arr[n + 1] = 0;
    push(n + 1);
    for(int i = n ; i >= 1 ; --i){
        while(arr[top()] >= arr[i]){
            pop();
        }
        mx[top() - l[i] - 1] = max(mx[top() - l[i] - 1] , arr[i]);
        push(i);
    }
    for(int i = n -1 ; i >= 1 ; --i){
        mx[i] = max(mx[i] , mx[i + 1]);
    }
    for(int i = 1 ; i <= n ; ++i){
        printf("%d ",mx[i]);
    }
}