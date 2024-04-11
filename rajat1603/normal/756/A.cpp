#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int arr[N];
bool visited[N];
int cnt;
int arr2[N];
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        visited[i] = 0;
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr2 + i);
    }
    cnt = 0;
    int onez = 0;
    int v = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(!visited[i]){
            int node = i;
            int lol = 0;
            do{
                ++lol;
                visited[node] = 1;
                node = arr[node];
            }while(node != i);
            if(lol > 1){
                ++v;
            }
            else{
                onez += 1;
            }
        }
    }
    if(n == 1){
        cnt = 0;
    }
    else if(onez == n){
        cnt = n;
    }
    else{
        if(v == 1){
            cnt = 1 + onez;
        }
        else{
            cnt = v + onez;
        }
    }
    if(v == 1 && onez == 0){
        cnt = 0;
    }
    int ones = 0;
    for(int i = 1 ; i <= n ; ++i){
        ones += arr2[i];
    }
    if(!(ones & 1)){
        ++cnt;
    }
    cout << cnt << endl;
}