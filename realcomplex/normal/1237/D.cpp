#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)3e5 + 10;
const int LOG = 19;

int tab[LOG][N];
int a[N];
int ln[N];
int sol[N];

int get(int lf, int rf){
    int nl = ln[rf - lf + 1];
    return min(tab[nl][lf], tab[nl][rf - (1 << nl) + 1]);
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    vector<pii> qq;
    for(int i = 0 ; i < 3 * n; i ++ ){
        if(i < n){
            cin >> a[i];
            qq.push_back(mp(a[i], i));
        }
        else{
            a[i] = a[i - n];
        }
        tab[0][i] = a[i];
    }
    int nn = 3 * n;
    for(int lg = 1; lg < LOG; lg ++ ){
        for(int i = 0 ; i + (1 << lg) - 1 < nn; i ++ ){
            tab[lg][i] = min(tab[lg-1][i], tab[lg - 1][i + (1 << (lg - 1))]);
        }
    }
    for(int i = 1; i <= nn; i ++ ){
        while((1 << (ln[i] + 1)) <= i){
            ln[i] ++ ;
        }
    }
    sort(qq.begin(), qq.end());
    set<int> pos;
    int id;
    int go;
    int nex;
    int ch;
    for(int i = 0 ; i < n; i ++ ){
        id = qq[n - i - 1].se;
        auto it = pos.lower_bound(id);
        if(it == pos.end()){
            ch = nn;
        }
        else{
            ch = *it;
        }
        go = id;
        for(int lg = LOG - 1; lg >= 0; lg -- ){
            nex = (go + (1 << lg));
            if(nex < nn && get(id, nex) >= (a[id] + 1)/2 && nex < ch){
                go = nex;
            }
        }
        if(go == nn - 1){
            sol[id] = -1;
        }
        else{
            if(a[go + 1] < (a[id] + 1) / 2){
                sol[id] = go + 1 - id;
            }
            else{
                if(sol[go + 1] == -1) sol[id] = -1;
                else sol[id] = sol[go + 1] + go + 1 - id;
            }
        }
        sol[id + n] = sol[id];
        sol[id + 2 * n] = sol[id];
        pos.insert(id);
        pos.insert(id + n);
        pos.insert(id + 2 * n);
    }
    for(int i = 0 ; i < n; i ++ ){
        cout << sol[i] << "\n";
    }
    return 0;
}