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


const int K = 30;
ll pref[K];
multiset<int> T[K];

int sz;

void add(int x){
    sz ++ ;
    for(int i = K - 1; i >= 0 ; i -- ){
        if(x >= (1 << i)){
            pref[i] += x;
            T[i].insert(x);
            break;
        }
    }
}

void rem(int x){
    sz -- ;
    for(int i = K - 1; i >= 0 ; i -- ){
        if(x >= (1 << i)){
            pref[i] -= x;
            T[i].erase(T[i].find(x));
            break;
        }
    }
}

int calc(){
    ll pf = 0;
    int res = 0;
    for(int i = 0 ; i < K ; i ++ ){
        auto it = T[i].begin();
        if(it != T[i].end() && (*it) > 2ll * pf){
            res ++ ;
        }
        pf += pref[i];
    }
    return res;
}

int main(){
    fastIO;
    int q;
    cin >> q;
    char op;
    int x;
    for(int i = 0 ; i < q ; i ++ ){
        cin >> op >> x;
        if(op == '+') add(x);
        else rem(x);
        cout << sz - calc() << "\n";
    }
    return 0;
}