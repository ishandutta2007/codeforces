#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>
 
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
 
#define oo            (int)13e7
#define s(n)          scanf("%d",&n)
#define sl(n)         scanf("%lld",&n)
#define sf(n)         scanf("%lf",&n)
#define fill(a,v)     memset(a, v, sizeof a)
#define ull           unsigned long long
#define ll            long long
#define bitcount      __builtin_popcount
#define all(x)        x.begin(), x.end()
#define pb( z )       push_back( z )
#define gcd           __gcd
using namespace std;
int n, k;

const ll lim = 1000000007LL;
vector<ll> sol;
void gen(ll x) {
    if (x > lim) return;
    if (x) sol.pb(x);
    gen(x*10 + 4);
    gen(x*10 + 7);
}

bool lucky(int v) {
    if (v == 0) return 1;
    int ld = v%10;
    if (ld == 4 || ld == 7)
        return lucky(v/10);
    return 0;
}

const int mxn = 20;
ll f[mxn];
const bool DBG = 0;
int main(int argc, char** argv) {
	
    gen(0); sort(all(sol));
    for (int i=f[0]=1; i < mxn; i++)
        f[i] = f[i-1] * i;
    
    s(n); s(k);
    if (n < mxn && f[n] < k) {
        puts("-1");
        exit(0);
    }
    
    int ans = 0;
    for (int m=1; m < mxn; m++) {
        if (f[m] >= k) {
            vector<int> pos(m);
            vector<int> index(m);
            for (int i=0; i < m; i++) index[i] = i;
            
            int left = k-1;
            for (int p=0; p < m; p++) {
                ll sum = 0;
                for (int j=0; ; j++, sum += f[m-p-1]) {
                    if (sum > left) {
                        sum -= f[m-p-1]; left -= sum; j--;
                        pos[p] = index[j];
                        index.erase( index.begin() + j );
                        break;
                    }
                }
            }
            int offset = n-m+1;
            
            if (DBG) {
                for (int i=1; i < offset; i++)
                    cout << i << " ";
            }
            for (int i=0; i < m; i++) {
                int index = offset + i;
                int value = offset + pos[i];
                if (lucky(index) && lucky(value)) {
                    ans++;
                }
                if (DBG) {
                    cout << value << " ";
                }
            }
            if (DBG) {
                cout << endl;
            }
            for (int i=0; i < sol.size(); i++) {
                if (sol[i] < offset) {
                    ans++;
                }
            }
            
            break;
        }
    }
    
    cout << ans << endl;
    
	return 0;
}