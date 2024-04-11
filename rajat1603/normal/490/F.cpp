#include "bits/stdc++.h"
using namespace std;
const int N = 6e3 + 3;
int n;
pair < int , int > inp[N];
int arr[N];
vector < int > v[N];
int a , b;
int cur = 0;
short ans = 1;
short dp1[N][N];
short dp2[N][N];
short tmp[N];
short max(short a , short b){
    return (a > b) ? a : b;
}
void dfs(int node , int parent){
    for(int i = 0 ; i < arr[node] ; ++i){
        dp1[node][i] = 0;
    }
    for(int i = arr[node] ; i <= cur ; ++i){
        dp1[node][i] = 1;
    }
    for(int i = 0 ; i <= arr[node] ; ++i){
        dp2[node][i] = 1;
    }
    for(int i = arr[node] + 1 ; i <= cur ; ++i){
        dp2[node][i] = 0;
    }
    for(int next : v[node]){
        if(next != parent){
            dfs(next , node);
            for(int i = 0 ; i <= cur ; ++i){
                ans = max(ans , dp1[node][i] + dp2[next][i + 1]);
            }
            for(int i = 0 ; i < arr[node] ; ++i){
                dp1[node][i] = max(dp1[node][i] , dp1[next][i]);
            }
            for(int i = arr[node] ; i <= cur ; ++i){
                dp1[node][i] = max(dp1[node][i] , dp1[next][i]);
                dp1[node][i] = max(dp1[node][i] , dp1[next][arr[node] - 1] + 1);
            }
            for(int i = arr[node] + 1 ; i <= cur ; ++i){
                dp2[node][i] = max(dp2[node][i] , dp2[next][i]);
            }
            for(int i = 0 ; i <= arr[node] ; ++i){
                dp2[node][i] = max(dp2[node][i] , dp2[next][i]);
                dp2[node][i] = max(dp2[node][i] , dp2[next][arr[node] + 1] + 1);   
            }
        }
    }
    ans = max(ans , max(dp1[node][cur] , dp2[node][0]));
    memset(tmp , 0 , sizeof(tmp));
    reverse(v[node].begin() , v[node].end());
    for(int next : v[node]){
        if(next != parent){
            for(int i = 0 ; i <= cur ; ++i){
                ans = max(ans , dp2[next][i + 1] + tmp[i]);
            }
            for(int i = 0 ; i <= cur ; ++i){
                tmp[i] = max(tmp[i] , dp1[next][i]);
            }
            for(int i = arr[node] ; i <= cur ; ++i){
                tmp[i] = max(tmp[i] , dp1[next][arr[node] - 1] + 1);
            }
        }
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &inp[i].first);
        inp[i].second = i;
    }
    sort(inp + 1 , inp + 1 + n);
    for(int i = 1 ; i <= n ; ++i){
        cur += (inp[i].first != inp[i - 1].first);
        arr[inp[i].second] = cur;
    }
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    dfs(1 , 0);
    printf("%hd\n" , ans);
}