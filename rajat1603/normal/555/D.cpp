#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , m;
pair < int , int > inp[N];
int arr[N];
int idx[N];
int x , len;
int solveright(int idx , int len , int rekt);
int solveleft(int idx , int len , int rekt){
    if(len == 0){
        return idx;
    }
    int go;
    if(arr[1] >= arr[idx] - len){
        go = 1;
    }
    else{
        go = lower_bound(arr + 1 , arr + idx + 1 , arr[idx] - len) - arr;
    }
    if(go == idx){
        if(rekt == 2){
            return idx;
        }
        return solveright(idx , len , 2);
    }
    if(rekt == 1 && len >= 2 * (arr[idx] - arr[go])){
        len %= 2 * (arr[idx] - arr[go]);
        return solveleft(idx , len , rekt);
    }
    else{
        len -= arr[idx] - arr[go];
        if(len >= 0){
            return solveright(go , len , 1);
        }
        return idx;
    }
}
int solveright(int idx , int len , int rekt){
    if(len == 0){
        return idx;
    }
    int go;
    if(arr[n] <= arr[idx] + len){
        go = n;
    }
    else{
        go = lower_bound(arr + idx , arr + 1 + n , arr[idx] + len + 1) - arr - 1;
    }
    if(go == idx){
        if(rekt == 2){
            return idx;
        }
        return solveleft(idx , len , 2);
    }
    if(rekt == 1 && len >= 2 * (arr[go] - arr[idx])){
        len %= 2 * (arr[go] - arr[idx]);
        return solveright(idx , len , 1);
    }
    else{
        len -= arr[go] - arr[idx];
        if(len >= 0){
            return solveleft(go , len , 1);
        }
        else{
            return idx;
        }
    }
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &inp[i].first);
        inp[i].second = i;
    }
    sort(inp + 1 , inp + 1 + n);
    for(int i = 1 ; i <= n ; ++i){
        arr[i] = inp[i].first;
        idx[inp[i].second] = i;
    }
    while(m--){
        scanf("%d %d" , &x , &len);
        x = idx[x];
        printf("%d\n" , inp[solveright(x , len , 0)].second);
    }
}