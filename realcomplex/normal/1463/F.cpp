#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 22;
short dp[1<<N][N];
int bits[N];

int main(){
    int n, x, y;
    cin >> n >> x >> y;
    if(x>y) swap(x,y);
    int p = x + y;
    int q = n % p;
    int af = max(q-x,0);
    int cnt;
    bool valid;
    for(int i = 0 ; i < (1 << y); i ++ ){
        for(int j = 0 ; j < y ; j ++ ){
            dp[i][j]=-1;
        }
        cnt = 0;
        valid = true;
        for(int j = 0 ; j < y; j ++ ){
            if((i & (1 << j))){
                bits[j]=1;
            }
            else{
                bits[j]=0;
            }
            if(j >= x){
                if(bits[j] && bits[j-x]){
                    valid = false;
                }
            }
        }
        if(!valid) continue;
        for(int j = 0 ; j < af; j ++ ){
            cnt += bits[j];
        }
        dp[i][cnt]=__builtin_popcount(i);
    }
    int nx;
    for(int i = 0 ; i < (1 << y); i ++ ){
        for(int cnt = 0; cnt < y; cnt ++ ){
            if(dp[i][cnt]==-1) continue;
            for(int t = 0 ;t < y; t ++ ){
                if((i&(1<<t))) continue;
                nx = (i | (1 << t));
                dp[nx][cnt]=max(dp[nx][cnt],dp[i][cnt]);
            }
        }
    }
    int cur_mask;
    int soln = 0;
    int cur;
    int ex;
    int p1 = min(x, q);
    int mx = 0;
    for(int bu = 0 ; bu < (1 << x) ; bu ++ ){
        cur_mask = (1 << y) - 1;
        for(int c = 0 ;c < x ; c ++ ){
            if((bu & (1 << c))){
                if((cur_mask & (1 << c)))
                    cur_mask ^= (1 << c);
                nx = (y-x)+c;
                if((cur_mask & (1 << nx))){
                    cur_mask ^= (1 << nx);
                }
            }
        }
        ex = 0;
        for(int t = 0 ;t < p1; t ++ ){
            if((bu & (1<<t)))
                ex ++ ;
        }
        for(int pf = 0 ; pf <= af; pf ++ ){
            if(dp[cur_mask][pf] == -1) continue;
            cur = __builtin_popcount(bu) + dp[cur_mask][pf];
            mx = max(mx, cur);
            soln = max(soln,(n/p)*cur+ex+pf);
        }
    }
    cout << soln << "\n";
    return 0;
}