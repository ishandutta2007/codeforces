#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int Q = 5e3 + 3;
const int LN = 17;
int n , q;
int arr[N];
int l[Q] , r[Q];
double p[Q];
int st[LN][N];
int lg[N];
vector < int > tmp[N];
vector < int > v[Q];
int mx[Q];
double dp[Q][Q];
void build(){
    for(int i = 1 ; i <= n ; ++i){
        st[0][i] = arr[i];
    }
    for(int i = 1 ; i < LN ; ++i){
        for(int j = 1 ; j + (1 << i) - 1 <= n ; ++j){
            st[i][j] = max(st[i - 1][j] , st[i - 1][j + (1 << (i - 1))]);
        }
    }
    lg[1] = 0;
    for(int i = 2 ; i <= n ; ++i){
        lg[i] = lg[i >> 1] + 1;
    }
}
int query(int l , int r){
    int k = lg[r - l + 1];
    return max(st[k][l] , st[k][r - (1 << k) + 1]);
}
void dfs(int node){
    for(int next : v[node]){
        dfs(next);
    }
    dp[node][0] = 1;
    for(int j = 1 ; j <= q ; ++j){
        int val = mx[node] + j;
        double prod1 = 1 - p[node];
        double prod2 = p[node];
        for(int next : v[node]){
            int col = val - mx[next];
            if(col <= q + 1){
                prod1 *= 1 - dp[next][col];
                prod2 *= 1 - dp[next][col - 1];
            }
        }
        if(j == 1){
            prod2 *= 0;
        }
        dp[node][j] = 1 - prod1 - prod2;
    }
}
int main(){
    scanf("%d %d" , &n , &q);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    build();
    int idx = -1;
    for(int i = 1 ; i <= q ; ++i){
        scanf("%d %d %lf" , l + i , r + i , p + i);
    }
    ++q;
    l[q] = 1;
    r[q] = n;
    p[q] = 0;
    for(int i = 1 ; i <= q ; ++i){
        tmp[l[i]].emplace_back(i);
        mx[i] = query(l[i] , r[i]);
    }
    for(int i = 1 ; i <= n ; ++i){
        sort(tmp[i].begin() , tmp[i].end() , [](int a , int b){
            return r[a] > r[b];
        });
    }
    idx = tmp[1][0];
    stack < int > s;
    for(int i = 1 ; i <= n ; ++i){
        while(!s.empty() && r[s.top()] < i){
            s.pop();
        }
        for(int j : tmp[i]){
            if(!s.empty()){
                v[s.top()].emplace_back(j);
            }
            s.push(j);
        }
    }
    dfs(idx);
    double ans = 0;
    for(int i = 0 ; i <= q ; ++i){
        ans += (mx[idx] + i) * (dp[idx][i] - dp[idx][i + 1]);
    }
    printf("%.9lf\n" , ans);
}