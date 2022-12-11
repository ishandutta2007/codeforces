#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1010;
char conf[N][N];
int n, m;
int ci, cj;
bool check(int d){
    int slow = -(int)1e9;
    int shigh = (int)1e9;
    int dlow = -(int)1e9;
    int dhigh = (int)1e9;
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < m ; j ++ ){
            if(conf[i][j] == 'B'){
                slow = max(slow, i + j - d);
                shigh = min(shigh, i + j + d);
                dlow = max(dlow, i - j - d);
                dhigh = min(dhigh, i - j + d);
            }
        }
    }
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < m ; j ++ ){
            if((i - j) >= dlow && (i - j) <= dhigh && (i + j) >= slow && (i + j) <= shigh){
                ci = i + 1;
                cj = j + 1;
                return true;
            }
        }
    }
    return false;
}

void solve(){
    cin >> n >> m;
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < m ; j ++ ){
            cin >> conf[i][j];
        }
    }
    int l = 0, r = 2010;
    int mid;
    while(l < r){
        mid = (l + r) / 2;
        if(check(mid)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    check(l);
    cout << ci << " " << cj << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}