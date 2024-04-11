#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1010;
const int MOD = (int)1e9 + 7;
int dp[N][N];

void add(int &x, int y){
    x += y;
    if(x >= MOD) x -= MOD;
}
int n;
int P[N];

void reset(){
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < n; j ++ ){
            dp[i][j]=0;
        }
    }
}

bool contains(int l, int r, int id){
    if(l <= r) {
        if(l <= id && id <= r) return true;
        else return false;
    }
    else{
        if(l <= id || id <= r) return true;
        else return false;
    }
}

int match[N];

void solve(){
    cin >> n;
    vector<int> idx;
    for(int i = 0 ; i < n; i ++) {
        cin >> P[i];
        if(i % 2 == 0) idx.push_back(i);
    }
    for(int i = n - 1; i >= 0 ; i -- ){
        if(i % 2 == 1) idx.push_back(i);
    }
    for(int i = 0 ; i < n; i ++ ){
        match[idx[i]] = i;
    }
    reset();
    for(int i = 0 ; i < (n+1)/2 ; i ++ ){
        if(P[idx[i]] == n || P[idx[i]] == -1) {
            dp[i][i] = 1;
        }
    }
    int r;
    int go;
    int answer = 0;
    for(int sz = 1; sz < n; sz ++ ){
        for(int l = 0; l < n; l ++ ){
            r = (l + sz - 1) % n;
            go = (r + 1) % n;
            if(go < (n+1)/2 || ((idx[go] - 1 < 0 || contains(l, r, match[idx[go] - 1])) && (idx[go] + 1 >= n || contains(l, r, match[idx[go] + 1])))){
                if(P[idx[go]] == n - sz || P[idx[go]] == -1){
                    add(dp[l][go], dp[l][r]);
                }
            }
            go = (l - 1 + n) % n;
            if(sz < n - 1){
                if(go < (n+1)/2 || ((idx[go] - 1 < 0 || contains(l, r, match[idx[go] - 1])) && (idx[go] + 1 >= n || contains(l, r, match[idx[go] + 1])))){
                    if(P[idx[go]] == n - sz || P[idx[go]] == -1){
                        add(dp[go][r], dp[l][r]);
                    }
                }
            }
        }
    }
    for(int l = 0 ; l < n; l ++ ){
        add(answer, dp[(l + 1) % n][l]);
    }
    reset();
    for(int i = (n+1)/2; i < n; i ++ ){
        if(P[idx[i]] == n || P[idx[i]] == -1){
            dp[i][i] = 1;
        }
    }
    for(int sz = 1; sz < n; sz ++ ){
        for(int l = 0 ; l < n; l ++ ){
            r = (l + sz - 1) % n;
            go = (r + 1) % n;
            if(go >= (n+1)/2 || ((idx[go] - 1 < 0 || contains(l, r, match[idx[go] - 1])) && (idx[go] + 1 >= n || contains(l, r, match[idx[go] + 1])))){
                if(P[idx[go]] == n - sz || P[idx[go]] == -1){
                    add(dp[l][go], dp[l][r]);
                }
            }
            go = (l - 1 + n) % n;
            if(sz < n - 1){
                if(go >= (n+1)/2 || ((idx[go] - 1 < 0 || contains(l, r, match[idx[go] - 1])) && (idx[go] + 1 >= n || contains(l, r, match[idx[go] + 1])))){
                    if(P[idx[go]] == n - sz || P[idx[go]] == -1){
                        add(dp[go][r], dp[l][r]);
                    }
                }
            }
        }
    }
    for(int l = 0 ; l < n; l ++ ){
        add(answer, dp[(l + 1) % n][l]);
    }
    cout << answer << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}