#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 200100

using namespace std;

int a[N * 5], val[N];
int n, m;

void make(int node, int l ,int r) {
    if(l == r) {
        a[node] = val[l];
        return;
    }
    int m = (l + r) >> 1;
    make(node * 2, l, m);
    make(node * 2+ 1, m + 1, r);
    int h = log2(node);
    if(((h % 2) ^ (n % 2)) == 0) a[node] = a[node * 2] ^ a[node * 2 + 1];
    else a[node] = a[node * 2] | a[node * 2 + 1];
}

void Update(int id, int node ,int l, int r) {
    if(l > id || r < id) return;
    if(l == r){
        a[node] = val[id];
        return;
    }
    int m = (l + r) >> 1;
    Update(id, node * 2, l ,m);
    Update(id, node * 2+ 1, m + 1, r);
    int h = log2(node);
    if(((h % 2) ^ (n % 2)) == 0) a[node] = a[node * 2] ^ a[node * 2 + 1];
    else a[node] = a[node * 2] | a[node * 2 + 1];
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> m;
    for(int i = 1; i <= (1 << n); i++) cin >> val[i];
    make(1, 1, 1 << n);
    while(m--) {
        int p, b;
        cin >> p >> b;
        val[p] = b;
        Update(p, 1, 1, 1 << n);
        cout << a[1] << endl;
    }
    return 0;
}