#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1005;
const int MOD = (int)1e9 + 7;
int st[N];

int main(){
    fastIO;
    int n, x, pos;
    cin >> n >> x >> pos;
    int l = 0, r = n;
    int mid;
    st[pos]=3;
    while(l < r){
        mid = (l + r) / 2;
        if(mid == pos){
            l = mid + 1;
        }
        else if(mid < pos){
            st[mid] = 1; // less than
            l = mid + 1;
        }
        else{
            st[mid] = 2;
            r = mid;
        }
    }
    int dow = x - 1;
    int up = n - x;
    int sol = 1;
    for(int i = 0; i < n; i ++ ){
        if(st[i] == 1){
            sol = (sol * 1ll * dow) % MOD;
            dow -- ;
        }
        else if(st[i] == 2){
            sol = (sol * 1ll * up) % MOD;
            up -- ;
        }
    }
    up += dow;
    for(int i = 0; i < n; i ++ ){
        if(st[i] == 0){
            sol = (sol * 1ll * up) % MOD;
            up -- ;
        }
    }
    cout << sol << "\n";
    return 0;
}