#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;

ll h[N];
ll p[N];

int n,m;
bool ok(ll x){
    int fid = 0;
    ll cur;
    ll fpos;
    for(int i = 0 ; i < n; i ++){
        cur = x;
        if(h[i] > p[fid]){
            if(h[i] - p[fid] > x){
                return false;
            }
            fpos = p[fid];
            while(fid < m && p[fid] < h[i])
                fid ++ ;
            while(fid < m && (p[fid] - fpos) + min(p[fid] - h[i], h[i] - fpos) <= x){
                fid ++ ;
            }
        }
        else{
            while(fid<m && p[fid] <= h[i] + x){
                fid ++ ;
            }
        }
        if(fid==m)
            return true;
    }
    return false;
}

int main(){
    fastIO;
    cin >> n >> m;
    for(int i = 0 ; i < n; i ++ )
        cin >> h[i];
    for(int i = 0 ; i < m; i ++ )
        cin >> p[i];
    ll L = 0, R = (ll)1e12;
    ll M;
    while(L<R){
        M = (L+R)/2;
        if(ok(M))
            R = M;
        else
            L = M + 1;
    }
    cout << R;
    return 0;
}