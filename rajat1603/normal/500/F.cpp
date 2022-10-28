#include "bits/stdc++.h"
using namespace std;
const int N = 4e3 + 3;
const int T = 2e4 + 4;
int n , p;
int cst[N] , hap[N] , tin[N];
int q;
vector < int > in[T];
int out[T];
int a[T] , b[T];
vector < int > que[T];
int ans[T];
struct stk{
    int arr[N][N];
    int wei[N];
    int cst[N];
    int sz;
    void push(int weight , int cost){
        ++sz;
        for(int i = 0 ; i < weight ; ++i){
            arr[sz][i] = arr[sz - 1][i];
        }
        for(int i = weight ; i < N ; ++i){
            arr[sz][i] = max(arr[sz - 1][i] , arr[sz - 1][i - weight] + cost);
        }
        wei[sz] = weight;
        cst[sz] = cost;
    }
    void pop(){
        --sz;
    }
};
struct queueue{
    stk lft;
    stk rgt;
    void push(int weight , int cost){
        lft.push(weight , cost);
    }
    void relax(){
        if(!rgt.sz){
            while(lft.sz){
                rgt.push(lft.wei[lft.sz] , lft.cst[lft.sz]);
                lft.pop();
            }
        }
    }
    int top(int weight){
        int res = 0;
        for(int i = 0 ; i <= weight ; ++i){
            res = max(res , rgt.arr[rgt.sz][i] + lft.arr[lft.sz][weight - i]);
        }
        return res;
    }
    void pop(){
        relax();
        rgt.pop();
    }
};
queueue dp;
int main(){
    scanf("%d %d" , &n , &p);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d %d" , cst + i , hap + i , tin + i);
        in[tin[i]].emplace_back(i);
        ++out[tin[i] + p];
    }
    scanf("%d" , &q);
    for(int i = 1 ; i <= q ; ++i){
        scanf("%d %d" , a + i , b + i);
        que[a[i]].emplace_back(i);
    }
    for(int i = 1 ; i < T ; ++i){
        for(int idx : in[i]){
            dp.push(cst[idx] , hap[idx]);
        }
        while(out[i]--){
            dp.pop();
        }
        for(int idx : que[i]){
            ans[idx] = dp.top(b[idx]);
        }
    }
    for(int i = 1 ; i <= q ; ++i){
        printf("%d\n" , ans[i]);
    }
}