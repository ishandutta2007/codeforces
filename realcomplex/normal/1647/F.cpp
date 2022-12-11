#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 100;
const int inf = (int)1e9 + 100;

int A[N];
int n;

int dp_end[N];
int dp_start[N];

int mix[N][2];


int solve(){
    for(int i = n; i >= 1; i -- ){
        dp_end[i] = inf;
        dp_start[i] = inf;
    }
    dp_end[n + 1] = 0;
    A[n + 1] = 0;
    int id = 1;
    for(int i = 1; i <= n; i ++ ){
        if(A[i] > A[id]){
            id = i ;
        }
    }
    for(int i = n; i >= 1; i -- ){
        if(A[i] > A[i + 1]){
            dp_end[i] = min(dp_end[i], dp_end[i + 1]);
        }
        if(A[i] > dp_end[i + 1]){
            dp_end[i] = min(dp_end[i], A[i + 1]);
        }
    }
    int L = dp_end[id];
    if(L == inf) return 0;
    dp_start[0] = 0;
    A[0] = 0;
    for(int i = 1; i <= n; i ++ ){
        if(A[i] > A[i - 1]){
            dp_start[i] = min(dp_start[i], dp_start[i - 1]);
        }
        if(A[i] > dp_start[i - 1]){
            dp_start[i] = min(dp_start[i], A[i - 1]);
        }
    }
    mix[id][0] = 0;
    mix[id][1] = L;
    for(int i = id - 1; i >= 1; i -- ){
        mix[i][0] = 0;
        mix[i][1] = inf;
        if(A[i] > A[i + 1]){
            mix[i][0] = max(mix[i][0], mix[i + 1][0]);
        }
        if(A[i] < A[i + 1]){
            mix[i][1] = min(mix[i][1], mix[i + 1][1]);
        }
        if(A[i] > mix[i + 1][1]){
            mix[i][0] = max(mix[i][0], A[i + 1]);
        }
        if(A[i] < mix[i + 1][0]){
            mix[i][1] = min(mix[i][1], A[i + 1]);
        }
    }
    int res = 0 ;
    for(int i = id - 1; i >= 1; i -- ){
        if(mix[i][0] > dp_start[i]){
            res ++ ;
        }
    }
    return res;
}



int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    int res = solve();
    reverse(A + 1, A + n + 1);
    res += solve();
    cout << res << "\n";
    return 0;
}