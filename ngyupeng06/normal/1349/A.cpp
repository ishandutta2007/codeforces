#include <bits/stdc++.h>

using namespace std;
typedef long long int li;
typedef pair<int,int> pii;
typedef pair<li,li> pll;
#define mp make_pair
#define pb push_back

long long n, k, m, t, a, b, c, d, e, f, x, y, arr[100005], p[100005];
bool pr[200005];
deque<long long> bruh[200005];

long long gcd(long long a, long long b){
	if (a>b) swap(a,b);
	if (a==0) return b;
	return gcd(b%a, a);
}

long long lcm(long long a, long long b){
	return a*b/gcd(a,b);
}

int st[1<<21], size = 1<<20;

void update(int p, int v){
	st[p+=size]=v;
	for (p>>=1; p; p>>=1) st[p] = gcd(st[p<<1],st[p<<1|1]);
}

int rquery(int l, int r){
	int ans=0;
	for (l+=size, r+=size; l<r; l>>=1, r>>=1){
		if (l&1) ans = gcd(ans,st[l++]);
		if (r&1) ans = gcd(ans,st[--r]);
	}
	return ans;
}

int query(int l, int r){
	if (r < l) return 0;
	return rquery(l,r+1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> arr[i];
		update(i,arr[i]);
	}
	long long ans = 1;
	for (int i=0; i<n; i++){
		long long thingy = 0;
		thingy = gcd(query(0, i-1), query(i+1,n-1));
		ans = lcm(ans,thingy);
	}
	cout << ans;
}