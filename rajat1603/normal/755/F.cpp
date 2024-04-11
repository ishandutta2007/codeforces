#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int mn;
int mx;
int n , k;
int nxt[N];
bool visited[N];
bitset < N > dp;
int cnt[N];
int arr[N];
int sz;
int arr2[N];
int sz2;
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , nxt + i);
    }
    sz = 0;
    mn = 0;
    mx = 0;
    for(int i = 1 ; i <= n ; ++i){
        visited[i] = 0;
        cnt[i] = 0;
    }
    for(int i = 1 ; i <= n ; ++i){
        if(!visited[i]){
            int node = i;
            int cnt = 0;
            do{
                visited[node] = 1;
                node = nxt[node];
                ++cnt;
            }while(node != i);
            ++::cnt[cnt];
            arr[++sz] = cnt;
        }
    }
    sz2 = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(cnt[i]){
            int val = cnt[i];
            for(int j = 0 ; (1 << j) <= val ; ++j){
                arr2[++sz2] = (1 << j) * i;
                val -= 1 << j;
            }
            if(val){
                arr2[++sz2] = val * i;
            }
        }
    }
    dp.set(0);
    for(int i = 1 ; i <= sz2 ; ++i){
        dp |= dp << arr2[i];
    }
    if(dp.test(k)){
        mn = k;
    }
    else{
        mn = k + 1;
    }
    for(int i = 1 ; i <= sz && k ; ++i){
        if(k * 2 >= arr[i]){
            k -= arr[i] >> 1;
            mx += arr[i] - (arr[i] & 1);
            arr[i] &= 1;
        }
        else{
            mx += k * 2;
            arr[i] -= k * 2;
            k = 0;
        }
    }
    for(int i = 1 ; i <= sz && k ; ++i){
        if(arr[i]){
            --k;
            --arr[i];
            ++mx;
        }
    }
    printf("%d %d\n" , mn , mx);
}