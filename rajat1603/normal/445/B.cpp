#include "bits/stdc++.h"
using namespace std;
const int N = 55;
int parent[N];
int siz[N];
int n , m;
int x , y;
int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
void join(int a , int b){
    int x = find(a);
    int y = find(b);
    if(x != y){
        siz[x] += siz[y];
        siz[y] = siz[x];
        parent[y] = x;
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1 ; i <= n ; ++i){
        parent[i] = i;
        siz[i] = 1;
    }
    while(m--){
        cin >> x >> y;
        join(x , y);
    }
    set < int > s;
    for(int i = 1 ; i <= n ; ++i){
        s.insert(find(i));
    }
    cout << (1LL << n - s.size());
}