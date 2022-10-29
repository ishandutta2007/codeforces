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
const int N=1e6+50;
int a[N];
void solve() {
    int n;
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    ll s0=a[1]+a[2],s1=a[n];
    int l=3,r=n-1;
    while(l<=r) {
    	s0+=a[l++];
    	s1+=a[r--];
    }
    if(s0<s1) puts("YES");
    else puts("NO");
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) solve();
    
    return 0;
}