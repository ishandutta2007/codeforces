#pragma GCC optimize("O3")   //
#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double ld;
typedef unsigned long long ull;
 
unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 eng(seed);
ll random2(){
    return (1ll << 31ll)*eng()+eng();
}
 
const ll big = 1000000007;
const ll big2 = 1000000009;
const ll mod =  998244353;
const int MAXN = 200001;

int n,m;
const int BLOCK = 400;
vi A;
vi jumps, land, last;

void recalc(int b){
    for(int c1 = min(n, (b+1)*BLOCK)-1; c1 >= b*BLOCK; c1--){
        int x = A[c1] + c1;
        if(x >= n){
            last[c1] = c1;
        }
        else{
            last[c1] = last[x];
        }
        if(x >= n || x/BLOCK > b){
            jumps[c1] = 1;
            land[c1] = x;
        }
        else{
            jumps[c1] = 1 + jumps[x];
            land[c1] = land[x];
        }
    }
}

void solve(int i){
    int jump = 0;
    int L = 0;
    while(i < n){
        jump += jumps[i];
        L = last[i];
        i = land[i];
    }
    cout << L+1 << " " << jump << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >>  n >> m;
    rep(c1,0,n){
        int a;
        cin >> a;
        A.push_back(a);
        jumps.push_back(0);
        land.push_back(0);
        last.push_back(0);
    }
    for(int b = (n+BLOCK-1)/BLOCK; b >= 0; b--){
        recalc(b);
    }
    rep(c1,0,m){
        int type;
        cin >> type;
        if(type == 0){
            int a,b;
            cin >> a >> b;
            a--;
            A[a] = b;
            recalc(a/BLOCK);
        }
        else{
            int a;
            cin >> a;
            a--;
            solve(a);
        }
    }
 
    return 0;
}