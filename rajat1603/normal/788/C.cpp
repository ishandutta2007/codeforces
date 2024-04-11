#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
int n , k;
int mark[N];
int arr[N];
int dist[N + N];
int que[N + N];
int qs , qe;
int main(){
    scanf("%d %d" , &n , &k);
    while(k--){
        int val;
        scanf("%d" , &val);
        mark[val] = 1;
    }
    for(int i = 0 ; i < N ; ++i){
        if(mark[i]){
            arr[++k] = i - n;
        }
    }
    for(int i = 0 ; i < N + N ; ++i){
        dist[i] = N;
    }
    que[qe++] = 0;
    dist[N] = 0;
    int ans = N;
    while(qs < qe){
        int node = que[qs++];
        int cost = dist[node + N] + 1;
        for(int i = 0 ; i <= k ; ++i){
            int val = node + arr[i];
            if(val > -N && val < N){
                if(dist[val + N] > cost){
                    dist[val + N] = cost;
                    que[qe++] = val;
                }
                if(val == 0){
                    ans = min(ans , cost);
                }
            }
        }
    }
    if(ans >= N){
        ans = -1;
    }
    printf("%d\n" , ans);
}