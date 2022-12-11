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

const int N = (int)5e5 + 9;
const int BL = 700;
const int K = 1000;
int p[N];
int len[N];
int nx[N];

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int l, r;
    for(int i = 0 ; i < n; i ++ ){
        cin >> l >> r;
        p[l] = max(p[l], r);
    }
    for(int i = 1 ; i < N ; i ++ )
        p[i] = max(p[i],p[i-1]);
    int jl;
    for(int i = N-1; i >= 0 ; i -- ){
        if(p[i] <= i){
            len[i] = -1;
            nx[i] = -1;
            continue;
        }
        jl = p[i];
        if(jl / BL > i / BL){
            len[i] = 1;
            nx[i] = jl;
        }
        else{
            len[i] = len[jl] + 1;
            nx[i] = nx[jl];
        }
    }
    int xi, yi;
    int res=0;
    for(int i = 0 ; i < m ; i ++ ){
        cin >> xi >> yi;
        res = 0;
        while(nx[xi] != -1 && nx[xi] < yi){
            res += len[xi];
            xi = nx[xi];
        }
        while(xi < yi){
            if(p[xi] <= xi){
                res = -1;
                break;
            }
            res ++ ;
            xi = p[xi];
        }
        cout << res << "\n";
    }
    return 0;
}