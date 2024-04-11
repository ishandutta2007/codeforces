#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using omset=tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

void fsc(int &x){
    register int c;
    x = 0; c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1)+(x<<3)+c-48;
}
void read(){}
template <typename T, typename... Types> 
void read(T& var1, Types&... var2) { 
    fsc(var1);
    read(var2...) ; 
}

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e2+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 30, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int n, cnt[2], a[MAXN], pre[MAXN][2], cur[MAXN][2], ss[MAXN];
void solve(){
    cin >> n;
    int cnt[2] = {(n+1)/2, n/2}; //even left, odd left
    vector<int> a(n); 
    for (auto& it : a) {
        cin >> it, --it;
        if (it != -1) cnt[it&1]--, it = it&1;
    }
    // cerr << cnt[0] << ' ' << cnt[1] << '\n';
    memset(ss, 0, sizeof(ss));
    for (int i = n-1; i >= 0; i--) ss[i] = (a[i]==-1)+ss[i+1];
    memset(pre, 0, sizeof(pre)); memset(cur, 1e9, sizeof(cur));
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= cnt[0]; j++){ //how many evens left
            int k = cnt[1]-(ss[i+1]-(cnt[0]-j)); //how many odds left
            if (k < 0) continue;
            for (int l = 0; l < 2; l++){ //whether my current element is gonna be even or odd
                if (a[i] == -1){
                    if (!l && !j) cur[j][l] = 1e9;
                    else if (l && !k) cur[j][l] = 1e9;
                    else {
                        cur[j][l] = min(pre[j-(l==0)][0]+(l!=0), pre[j-(l==0)][1]+(l!=1));
                    }
                } else {
                    if ((a[i]&1) != l) cur[j][l] = 1e9;
                    else cur[j][l] = min(pre[j][0]+(a[i]!=0), pre[j][1]+(a[i]!=1));
                }
                // cerr << i << ' ' << j << ' ' << k << ' ' << l << ' ' << cur[j][l] << '\n';
            }
        }
        for (int j = 0; j <= cnt[0]; j++) for (int l = 0; l < 2; l++) pre[j][l] = cur[j][l], cur[j][l] = 1e9;
    }
    cout << min(pre[cnt[0]][0], pre[cnt[0]][1]);
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; //cin >> t; 
    while (t--) solve();
}