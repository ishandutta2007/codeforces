#include <bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 100000;
int n,k;
int a[maxn+1];
int r[maxn+1];
int calS(int a,int b) {
	return a - 3*b*b - 3*b -1;
}
int check(int slope,bool verbose = false) {
	int res = 0;
	rep(i,1,n+1) {
		int dau = 0, cuoi = a[i];
		do
		{
			int giua = (dau+cuoi)/2;
			if (calS(a[i],giua)>=slope) dau = giua+1;
			else cuoi = giua-1;
		}
		while (dau<=cuoi);
		res+=cuoi;
		if (verbose) r[i] = cuoi;
	}

	return res;
}
main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cin >> n >> k;
	rep(i,1,n+1) cin >> a[i];
	int dau = -4e18, cuoi = 4e18;
	do
	{
		int giua = (dau+cuoi)/2;

		//cerr << giua << '\n';
		if (check(giua)>k) dau = giua+1;
		else cuoi=giua-1;
	}
	while (dau<=cuoi);
	
	int nk = check(cuoi,true);
	rep(i,1,n+1) {
		if (nk>k and calS(a[i],r[i])==cuoi) {
			nk--;
			r[i]--;
		}
	}
	rep(i,1,n+1) cout << r[i] << ' ';

}