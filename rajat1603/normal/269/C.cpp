#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int M = N * 2;
int n , m;
int a[N] , b[N] , c[N];
int d[N];
int hed[N];
int pre[M];
int que[N];
int qs , qe;
int in[N];
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d %d" , a + i , b + i , c + i);
        pre[2 * i] = hed[a[i]];
        hed[a[i]] = 2 * i;
        pre[2 * i + 1] = hed[b[i]];
        hed[b[i]] = 2 * i + 1;
        d[i] = -1;
    }
    in[1] = 0;
    for(int i = 2 ; i <= n ; ++i){
        in[i] = 0;
        for(int j = hed[i] ; j ; j = pre[j]){
            in[i] += c[j >> 1];
        }
        if(i < n){
            in[i] >>= 1;
        }
    }
    que[qe++] = 1;
    while(qs < qe){
        int node = que[qs++];
        for(int i = hed[node] ; i ; i = pre[i]){
            int edge = i >> 1;
            if(d[edge] == -1){
                int next;
                if(a[edge] == node){
                    d[edge] = 0;
                    next = b[edge];
                }
                else{
                    d[edge] = 1;
                    next = a[edge];
                }
                in[next] -= c[edge];
                if(!in[next]){
                    que[qe++] = next;
                }
            }
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        printf("%d\n" , d[i]);
    }
}