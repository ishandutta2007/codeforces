#include "bits/stdc++.h"
using namespace std;
const int N = 500001;
int arr[N];
vector< pair < int , int > > v[N];
int ans[N];
int n , m;
int bit[N];
map < int , int > last;
void update(int idx , int val){
    for(; idx <= n ; idx += idx&-idx){
        bit[idx] = min(bit[idx] , val);
    }
}
int query(int idx){
    int res = n + 1;
    for(; idx ; idx &= idx - 1){
        res = min(res , bit[idx]);
    }
    return res;
}
int main(){
    scanf("%d %d", &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &arr[i]);
        bit[i] = n + 1;
    }
    for(int i = 1 ; i <= m ; ++i){
        int x , y;
        scanf("%d %d" , &x , &y);
        v[y].push_back(make_pair(x , i));
    }
    for(int i = 1 ; i <= n ; ++i){
        if(last.find(arr[i]) != last.end())
            update(n - last[arr[i]] + 1 , i - last[arr[i]]);
        last[arr[i]] = i;
        int x = v[i].size();
        for(int j = 0 ; j < x ; ++j){
            ans[v[i][j].second] = query(n - v[i][j].first + 1);
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        printf("%d\n", (ans[i] == n + 1) ? -1 : ans[i] );
    }
}