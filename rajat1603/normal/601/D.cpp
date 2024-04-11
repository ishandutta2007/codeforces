#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
const long long mod = 999998727899999LL;
int n;
int arr[N];
char str[N];
vector < int > v[N];
set < long long > s[N];
int val = -1;
int cnt;
int a , b;
void dfs(int node , int parent , long long hashes){
    hashes *= 27ULL;
    hashes += str[node] - 'a' + 1ULL;
    hashes %= mod;
    int idx = 0;
    for(int next : v[node]){
        if(next != parent){
            dfs(next , node , hashes);
            if(idx == -1 || s[next].size() > s[idx].size()){
                idx = next;
            }
        }
    }
    s[node].swap(s[idx]);
    s[node].insert(hashes);
    for(int next : v[node]){
        if(next != parent && next != idx){
            s[node].insert(s[next].begin() , s[next].end());
        }
    }
    int temp = s[node].size() + arr[node];
    if(temp > val){
        val = temp;
        cnt = 0;
    }
    if(temp == val){
        ++cnt;
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    scanf("%s" , str + 1);
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    dfs(1 , -1 , 0LL);
    printf("%d %d\n" , val , cnt);
}