#pragma GCC optimize("Ofast", "-funroll-loops", "-fdelete-null-pointer-checks")
#pragma GCC target("ssse3", "sse3", "sse2", "sse", "avx2", "avx")
#pragma GCC optimize(3, "Ofast", "inline")
#define _CRT_SECURE_NO_WARNINGS
#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>
#include <queue>
#include <bitset>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll mod = 1e9+7;
void imult(ll& lhs, const ll& rhs) {
	lhs = ((lhs % mod) * (rhs % mod)) % mod;
}

void iadd(ll& lhs, const ll& rhs) {
	lhs = ((lhs%mod) + (rhs%mod)) % mod;
}

void isubt(ll& lhs, const ll& rhs) {
	ll ret = (lhs - rhs) % mod;
	lhs = ret + (ret < 0 ? mod : 0);
}

ll bpw(const ll& lhs, const ll& rhs) {
	if (rhs == 0)return 1;
	ll ret = bpw(lhs, rhs >> 1);
	imult(ret, ret);
	if (rhs & 1) imult(ret, lhs);
	return ret;
}

ll inv(const ll& x) {
	return bpw(x, mod - 2);
}

ll mult(const ll& lhs, const ll& rhs) {
	return ((lhs % mod) * (rhs % mod)) % mod;
}

ll add(const ll& lhs, const ll& rhs) {
	return ((lhs%mod) + (rhs%mod)) % mod;
}

ll subt(const ll& lhs, const ll& rhs) {
	ll ret = (lhs - rhs) % mod;
	return ret + (ret < 0 ? mod : 0);
}

ll divv(const ll& lhs, const ll& rhs) {
	return mult(lhs, inv(rhs));
}


const int sz=1e6+2,psz=21;
int n, m;
ll dp[psz][sz], vals[psz];


ll calcdp()  {
    ll tot = 0, crsm=0;
    for (int p = 0; p < m; p++) {
        crsm += vals[p];
        dp[p][0]=(p==0);
        for (int i = 1; i < crsm; i++)
            dp[p][i]=add(mult(dp[p-1][i-1],vals[p]), mult(dp[p][i-1], crsm-i));
        if(p==m-1)break;
        for (int i = crsm;i<crsm+vals[p+1];i++)
            dp[p][i]=0;
    }
    return dp[m-1][n-1];
}


int main() {
	fast;
	cin>>n;
	ll tot=0;
	bool onlytwo=0;
	int crpw=0,cr=1;
	while(true){
	    if(cr*2<=n&&cr*3>n){
	        crpw++;
	        cr*=2;
	        onlytwo=1;
	        break;
	    }
	    else if (cr*2>n){
	        break;
	    }
	    else{
	        cr*=2;
	    }
	    crpw++;
	}
	m=crpw+1;
	int crr = cr,pval=0;
	for (int j=0;j<crpw+1;j++){
	    vals[j]=n/crr-pval;
	    crr/=2;
	    pval+=vals[j];
	}
	iadd(tot,calcdp());
	if(!onlytwo){
	    cr/=2;
	    cr*=3;
	    for (int i = 0; i < crpw;i++){
	        pval=0;
	        crr=cr;
	        for (int j = 0; j < crpw+1;j ++) {
	            vals[j]=n/crr-pval;
	            if(j==i)
	               crr/=3; 
	            else
	                crr/=2;
	             pval+=vals[j];
	        }
	        iadd(tot,calcdp());
	    }
	}
	cout<<tot<<'\n';
	return 0;
}