#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 10;
const int M = 22;
const int T = N * M;
bool mark[N];
int dp[M];
int cc[N];
bitset<T> obt;

int main(){
    fastIO;
    //freopen("in.txt","r",stdin);
    int n, m;
    cin >> n >> m;
    int v;
    for(int i = 2; i <= n; i ++ ){
        if(!mark[i]){
            v = i;
            while(v <= n){
                cc[i] ++ ;
                mark[v] = true;
                if(v * 1ll * i > n) break;
                v *= i;
            }
        }
    }
    for(int i = 1; i < M; i ++ ){
        for(int j = 1; j <= m; j ++ ){
            obt[i * j] = 1;
        }
        dp[i]=obt.count();
    }
    ll res = 1;
    for(int i = 2; i <= n; i ++ ){
        res+=dp[cc[i]];
    }
    cout << res << "\n";
    return 0;
}