#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int x[N];
int y[N];
set < pair < int , int > > v[N + N];
int arr[N];
int ans[N];
priority_queue < int > pq[N];
map < int , int > m;
int cur;
void update(int x , int y){
    x = m[x];
    y = m[y];
    while(x <= cur){
        pq[x].push(-y);
        x += x & -x;
    }
}
bool query(int x , int y){
    x = m[x];
    y = m[y];
    while(x){
        if(!pq[x].empty()){
            int temp = -pq[x].top();
            if(temp <= y){
                return 1;
            }
        }
        x -= x & -x;
    }
    return 0;
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , x + i , y + i);
        v[y[i] - x[i] + N].insert(make_pair(x[i] , i));
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &arr[i]);
    }
    for(int i = 1 ; i <= n ; ++i){
        if(v[arr[i] + N].empty()){
            puts("NO");
            return 0;
        }
        ans[i] = v[arr[i] + N].begin() -> second;
        v[arr[i] + N].erase(v[arr[i] + N].begin());
    }
    for(int i = 1 ; i <= n ; ++i){
        m[x[i]];
        m[y[i]];
    }
    cur = 0;
    for(auto it : m){
        m[it.first] = ++cur;
    }
    for(int i = n ; i >= 1 ; --i){
        if(query(x[ans[i]] , y[ans[i]])){
            puts("NO");
            return 0;
        }
        update(x[ans[i]] , y[ans[i]]);
    }
    puts("YES");
    for(int i = 1 ; i <= n ; ++i){
        printf("%d %d\n" , x[ans[i]] , y[ans[i]]);
    }
}