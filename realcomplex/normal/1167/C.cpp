#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = (int)5e5 + 9;
int sz[N];
int pi[N];

int fin(int x){
    if(pi[x] == x)
        return x;
    return pi[x] = fin(pi[x]);
}

void unite(int a, int b){
    a=fin(a);
    b=fin(b);
    if(a==b)
        return;
    if(sz[a] > sz[b])
        swap(a, b);
    sz[b] += sz[a];
    pi[a] = b;
}

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ )
        sz[i] = 1, pi[i] = i;
    int k;
    int z;
    for(int i = 0 ; i < m ; i ++ ){
        cin >> k;
        vector<int> t;
        for(int i = 0 ; i < k ; i ++ ){
            cin >> z;
            t.push_back(z);
        }
        for(int i = 1; i < t.size(); i  ++ ){
            unite(t[i-1], t[i]);
        }
    }
    for(int i = 1; i <= n; i ++ ){
        cout << sz[fin(i)] << " ";
    }
    return 0;
}