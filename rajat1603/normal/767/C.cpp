#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n;
int par;
vector < int > v[N];
int arr[N];
int sum[N];
int who[N];
long long tot;
void dfs(int node){
    sum[node] = arr[node];
    int last1 , last2;
    last1 = -1;
    last2 = -1;
    for(int next : v[node]){
        dfs(next);
        sum[node] += sum[next];
        if(who[next] != -1){
            last2 = last1;
            last1 = who[next];
        }
    }
    if(last2 != -1){
        printf("%d %d\n" , last1 , last2);
        exit(0);
    }
    if(node != v[0][0] && sum[node] == 2 * tot && last1 != -1){
        printf("%d %d\n" , node , last1);
        exit(0);
    }
    if(sum[node] == tot){
        who[node] = node;
    }
    else{
        who[node] = last1;
    }
}
int main(){
    scanf("%d" , &n);
    tot = 0;
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , &par , &arr[i]);
        v[par].emplace_back(i);
        tot += arr[i];
        who[i] = -1;
    }
    if(tot % 3){
        printf("-1\n");
        return 0;
    }
    tot /= 3;
    dfs(v[0][0]);
    printf("-1\n");
}