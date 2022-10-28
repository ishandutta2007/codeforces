#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const long long inf = 1e17;
int n;
int arr[N];
long long sub[N];
long long mex[N];
int a , b;
vector < int > v[N];
long long ans;
void dfs(int node , int parent){
    sub[node] = arr[node];
    mex[node] = -inf;
    long long val1 = -(inf + inf);
    long long val2 = -(inf + inf);
    for(int next : v[node]){
        if(next != parent){
            dfs(next , node);
            sub[node] += sub[next];
            mex[node] = max(mex[node] , mex[next]);
            if(mex[next] > val1){
                val2 = val1;
                val1 = mex[next];
            }
            else if(mex[next] > val2){
                val2 = mex[next];
            }
        }
    }
    mex[node] = max(mex[node] , sub[node]);
    ans = max(ans , val1 + val2);
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    ans = -inf;
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    dfs(1 , 0);
    if(ans == -inf){
        printf("Impossible\n");
    }
    else{
        printf("%lld\n" , ans);
    }
}