#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 1;

struct edge{
    int from;
    int to;
    int val;
    edge(int f , int t , int v){
        from = f;
        to = t;
        val = v;
    }
    bool operator < (const edge &b)const{
        return val > b.val;
    }
};

int n , m;
int arr[N];
int size[N];
int parent[N];
vector < edge > v;

int find(int node){
    return parent[node] = (node == parent[node]) ? node : find(parent[node]);
}

long long join(int a , int b){
    int x = find(a);
    int y = find(b);
    if(x == y){
        return 0;
    }
    long long ret = 1LL * size[x] * size[y];
    if(size[x] >= size[y]){
        size[x] += size[y];
        parent[y] = x;
    }
    else{
        size[y] += size[x];
        parent[x] = y;
    }
    return ret;
}

int main(){

    cin >> n >> m;

    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
        size[i] = 1;
        parent[i] = i;
    }

    for(int i = 1 ; i <= m ; ++i){
        int a , b;
        cin >> a >> b;
        v.emplace_back(edge(a , b , min(arr[a] , arr[b])));
    }

    sort(v.begin() , v.end());
    long long sum = 0;

    for(edge it : v){
        sum += join(it.from , it.to) * it.val;
    }

    double ans = sum;
    ans /= n;
    ans /= n - 1;
    ans += ans;
    
    printf("%lf\n" , ans);
}