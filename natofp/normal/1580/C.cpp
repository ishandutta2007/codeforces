#include <bits/stdc++.h>
#include <random>
#define ll long long int
#define pb push_back
#define st first
#define nd second
#define pii pair<int,int>
#define mp make_pair
#define pll pair<long long,long long>
#define ld long double
#define ull unsigned long long
 
using namespace std;
 
const int N = 2e5 + 5;
int x[N];
int y[N];
const int block = 700;
int n, m;
 
int ptr[block + 1];
int cnt[block + 1][block + 1];
int big[N];
int firstOcc[N];
 
void solve(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> x[i] >> y[i];
    }
    int bigActive = 0;
    int all = 0;
    for(int i=1;i<=m;i++){
        int op, k; cin >> op >> k;
        if(op == 1){
            all += 1;
            // add
            if(x[k] + y[k] <= block){
                firstOcc[k] = i;
                int sz = x[k] + y[k];
                int cur = i % sz;
                for(int i=cur;i<cur+x[k];i++){
                    int pos = i;
                    if(pos >= sz) pos -= sz;
                    cnt[sz][pos] += 1;
                }
            }
            else{
                // big
                int sz = x[k] + y[k];
                firstOcc[k] = i;
                for(int pos=i;pos<=m;pos+=sz){
                    if(pos != i) big[pos] += 1;
                    if(pos + x[k] <= m) big[pos + x[k]] -= 1;
                }
                bigActive += 1;
            }
        }
        else{
            // rem
            all -= 1;
            if(x[k] + y[k] <= block){
                int sz = x[k] + y[k];
                int cur = firstOcc[k] % sz;
                for(int i=cur;i<cur+x[k];i++){
                    int pos = i;
                    if(pos >= sz) pos -= sz;
                    cnt[sz][pos] -= 1;
                }
            }
            else{
                // big
                int sz = x[k] + y[k];
                for(int pos=firstOcc[k];pos<=m;pos+=sz){
                    big[pos] -= 1;
                    if(pos + x[k] <= m) big[pos + x[k]] += 1;
                }
                int aft = i - firstOcc[k] - 1;
                aft %= sz;
                if(aft < x[k]){
                    bigActive -= 1;
                }
            }
        }
        bigActive += big[i];
        int smallActive = 0;
        for(int j=1;j<=block;j++){
            ptr[j] += 1;
            if(ptr[j] == j) ptr[j] = 0;
            smallActive += cnt[j][i % j];
        }
        cout << all - (bigActive + smallActive) << "\n";
    }
 
 
}
 
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    int tt = 1;
    //cin >> tt;
    while(tt--) solve();
 
    return 0;
}