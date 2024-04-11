#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
const LL MOD = 1000000007;
LL powMod(LL x, LL y, LL mod) {
    if (y<1) return 1;
    if (y%2) return x*powMod(x, y-1, mod)%mod;
    return powMod(x*x%mod, y/2, mod);
}
LL extgcd(LL a, LL b, LL &x, LL &y) { // a x + b y = gcd(a, b)
    LL g=a; x=1, y=0;
    if (b) { g=extgcd(b, a%b, y, x); y-=a/b*x; }
    return g;
}

LL invMod(LL a, LL mod) {
    LL x, y;
    if (extgcd(a, mod, x, y) == 1) return (x + mod) % mod;
    return 0; // unsolvable
}


int n, m, a[1010];
vector<pair<int,int> >v;
LL fact[1010];
int main() {
    fact[0]=1;
    for (int i=1; i<1010; i++) fact[i] = fact[i-1]*i%MOD;
    
    scanf("%d%d", &n, &m);
    for (int i=0; i<m; i++) {
	int x; scanf("%d", &x); x--;
	a[x]=1;
    }
    int p=-1;
    LL ans=fact[n-m], d=1;
    for (int i=0; i<n; i++) {
	if (a[i]==1) {
	    if (p==-1) { if (i) v.push_back(make_pair(1, i)); }
	    else { if (i-p-1) v.push_back(make_pair(2, i-p-1)); }
	    p=i;
	}
    }
    if (n-p-1) v.push_back(make_pair(1, n-p-1));
    //cout<<v.size()<<endl;
    for (int i=0; i<int(v.size()); i++) {
	//printf("%d %d\n", v[i].first, v[i].second);
	d = d * fact[v[i].second] % MOD;
	if (v[i].first==2) ans = ans * powMod(2, v[i].second-1, MOD) % MOD;
    }
    printf("%d\n", int(ans*invMod(d, MOD)%MOD));
    return 0;
}