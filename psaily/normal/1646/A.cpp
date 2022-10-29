#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int Mod=1e9+7;
const int N=1e5+50;
void solve() {
    ll n,s;
    scanf("%lld%lld",&n,&s);
    // cerr << " --- " << endl;
    printf("%lld\n",s/n/n);
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) solve();
    
    return 0;
}