#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int n;
int arr[N];
int tin[N];
int low[N];
int timer;
stack < int > s;
bool instack[N];
int ans;
int pw2[N];
int add(int a , int b){
    int res = a + b;
    if(res >= mod){
        return res - mod;
    }
    return res;
}
int mult(int a , int b){
    long long res = a;
    res *= b;
    if(res >= mod){
        return res % mod;
    }
    return res;
}
bool dfs(int node , int last){
    tin[node] = low[node] = ++timer;
    s.push(node);
    instack[node] = 1;
    int next = arr[node];
    if(tin[next] == 0){
        dfs(next , node);
        low[node] = min(low[node] , low[next]);
    }
    else if(instack[next]){
        low[node] = min(low[node] , tin[next]);
    }
    if(low[node] == tin[node]){
        int sz = 0;
        while(1){
            int x = s.top();
            s.pop();
            instack[x] = 0;
            ++sz;
            if(x == node){
                break;
            }
        }
        if(sz == 1){
            ans = add(ans , ans);
        }
        else{
            ans = mult(ans , add(pw2[sz] , mod - 2));
        }
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        tin[i] = 0;
        low[i] = 0;
        instack[i] = 0;
    }
    while(!s.empty()){
        s.pop();
    }
    timer = 0;
    ans = 1;
    pw2[0] = 1;
    for(int i = 1 ; i <= n ; ++i){
        pw2[i] = add(pw2[i - 1] , pw2[i - 1]);
    }
    for(int i = 1 ; i <= n ; ++i){
        if(!tin[i]){
            dfs(i , 0);
        }
    }
    printf("%d\n" , ans);
}