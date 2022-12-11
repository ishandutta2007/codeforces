#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 5;
const int K = 20;
vector<int> P[N];
int s[K];
int t[K];
int L[1 << K];
int R[1 << K];

int main(){
    fastIO;
    int n, m, k;
    cin >> n >> m >> k;
    char f;
    int c0 = 0, c1 = 0;
    for(int i = 0 ; i < k ; i ++ ){
        cin >> f;
        s[i] = f - '0';
        c0 += s[i];
    }
    for(int i = 0 ; i < k ; i ++ ){
        cin >> f;
        t[i] = f - '0';
        c1 += t[i];
    }
    for(int i = 0 ; i <= n; i ++ ){
        for(int j = 0 ; j < k ; j ++ )
            P[i].push_back(j);
    }
    int l, r;
    for(int i = 1; i <= n; i ++ ){
        cin >> l >> r;
        l -- ;
        r -- ;
        P[i][l]=r;
        P[i][r]=l;
        vector<int> nw;
        for(auto x : P[i]){
            nw.push_back(P[i-1][x]);
        }
        P[i] = nw;
    }
    for(int i = 0 ; i < (1 << k); i ++ ){
        L[i] = (int)1e9;
        R[i] = -1;
    }
    int mask;
    for(int i = 0 ; i <= n - 1; i ++ ){
        mask = 0;
        for(int j = 0 ;j < k ; j ++ ){
            if(s[j]) mask |= (1 << P[i][j]);
        }
        L[mask] = min(L[mask], i);
    }
    for(int i = 1; i <= n; i ++ ){
        mask = 0;
        for(int j = 0 ; j < k ; j ++ ){
            if(t[j]) mask |= (1 << P[i][j]);
        }
        R[mask] = max(R[mask], i);
    }
    int nex;
    for(int i = (1 << k) - 1; i >= 0 ; i -- ){
        for(int j = 0 ; j < k ; j ++ ){
            if((i & (1 << j))) continue;
            nex = (i | (1 << j));
            L[i] = min(L[i], L[nex]);
            R[i] = max(R[i], R[nex]);
        }
    }
    int mx = 0;
    int fl = 0, fr = n;
    for(int i = 0 ; i < (1 << k); i ++ ){
        if(L[i] == (int)1e9 || R[i] == -1) continue;
        if(R[i] - L[i] >= m){
            if(__builtin_popcount(i) > mx){
                mx = __builtin_popcount(i);
                fl = L[i], fr = R[i];
            }
        }
    }
    cout << k + 2 * mx - c0 - c1 << "\n";
    cout << fl + 1 << " " << fr << "\n";
    return 0;
}