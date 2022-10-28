#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
int a[N] , b[N];
int indeg[N];
queue < int > q;
vector < int > v[N];
bool check(int val){
    for(int i = 1 ; i <= n ; ++i){
        indeg[i] = 0;
        v[i].clear();
    }
    while(!q.empty()){
        q.pop();
    }
    for(int i = 1 ; i <= val ; ++i){
        ++indeg[b[i]];
        v[a[i]].emplace_back(b[i]);
    }
    int tot = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(!indeg[i]){
            q.push(i);
            ++tot;
        }
    }
    //cout << val << " " << tot << endl;
    if(tot != 1){
        return 0;
    }
    tot = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ++tot;
        int sum = 0;
        for(int next : v[node]){
            --indeg[next];
            if(!indeg[next]){
                ++sum;
                q.push(next);
            }
        }
        if(sum > 1){
            return 0;
        }
    }
    return (tot == n);
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , a + i , b + i);
    }
    if(!check(m)){
        printf("-1\n");
        return 0;
    }
    int l = 1;
    int r = m;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    cout << l;
}