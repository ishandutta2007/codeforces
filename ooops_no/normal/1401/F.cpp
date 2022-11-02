#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>
#include<random>
#include<unordered_set>
 
using namespace std;
 
/*
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace __gnu_pbds;
 
tree<pair<long long, long long>, null_type, less<pair<long long, long long>>, rb_tree_tag, tree_order_statistics_node_update> st;
 
*/
/*
 
st.find_by_order();
st.order_of_key();
 
*/
 
#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
 
#define pb push_back
#define ld long double
#define int long long
 
mt19937 rnd(51);
 
//  ,    
 
const int N = 262144 + 10;
long long t[4 * N];
int32_t go[4 * N][2], a[N], add[4 * N][20], need[4 * N][30];
 
void push(int v, int cnt){
    for (int i = 0; i < 20; i++){
        if (go[v][0] < 4 * N){
            need[go[v][0]][i] ^= need[v][i];
            need[go[v][1]][i] ^= need[v][i];
        }
        need[v][i] = 0;
        if (cnt == i){
            if (go[v][0] < 4 * N){
                add[go[v][0]][i + 1] ^= add[v][i];
                add[go[v][1]][i + 1] ^= add[v][i];
            }
        }
        else if (cnt < i){
            if (go[v][0] < 4 * N){
                add[go[v][0]][i] ^= add[v][i];
                add[go[v][1]][i] ^= add[v][i];
            }
        }
        add[v][i] = 0;
    }
}
 
void build(int v, int l, int r){
    if (l == r){
        t[v] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m), build(2 * v + 1, m + 1, r);
    t[v] = t[v * 2] + t[v * 2 + 1];
    go[v][0] = v * 2;
    go[v][1] = v * 2 + 1;
}
 
void update(int v, int l, int r, int pos, int val, int cnt){
    if (need[v][cnt]){
        swap(go[v][0], go[v][1]);
    }
    if (add[v][cnt]){
        swap(go[v][0], go[v][1]);
    }
    push(v, cnt);
    if (l == r){
        t[v] = val;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m){
        update(go[v][0], l, m, pos, val, cnt + 1);
    }
    else{
        update(go[v][1], m + 1, r, pos, val, cnt + 1);
    }
    t[v] = t[v * 2] + t[v * 2 + 1];
}
 
int sum(int v, int tl, int tr, int l, int r, int cnt){
    if (need[v][cnt]){
        swap(go[v][0], go[v][1]);
        //cout << "UUUPS" << v << endl;
    }
    if (add[v][cnt]){
        swap(go[v][0], go[v][1]);
    }
    push(v, cnt);
    if (l > r) return 0;
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    return (sum(go[v][0], tl, tm, l, min(r, tm), cnt + 1) + sum(go[v][1], tm + 1, tr, max(l, tm + 1), r, cnt + 1));
}
 
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, m;
    cin >> m >> q;
    n = (1 << m);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    build(1, 0, n - 1);
    while(q--){
        int p;
        cin >> p;
        if (p == 1){
            int x, k;
            cin >> x >> k;
            x--;
            update(1, 0, n - 1, x, k, 0);
        }
        else if (p == 3){
            int k;
            cin >> k;
            k++;
            k = m - k;
            need[1][k] ^= 1;
            //cout << "LLL2 " << 1 << " " << k << endl;
        }
        else if (p == 2){
            int k;
            cin >> k;
            k = m - k;
            add[1][k] ^= 1;
            //cout << "LLL3 " << 1 << " " << k << endl;
        }
        else{
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << sum(1, 0, n - 1, l, r, 0) << endl;
        }
    }
    return 0;
}