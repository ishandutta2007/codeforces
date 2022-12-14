/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

int seg[400001], pos[400001], ar[100001];
void build(int idx, int l, int r){
	if(l == r){
		seg[idx] = ar[l];
		pos[idx] = l;
		return;
	}
	int mid = (l + r) / 2;
	build(idx * 2 + 1, l, mid);
	build(idx * 2 + 2, mid + 1, r);
	if(seg[idx * 2 + 1] > seg[idx * 2 + 2]){
		seg[idx] = seg[idx * 2 + 1];
		pos[idx] = pos[idx * 2 + 1];
	} else {
		seg[idx] = seg[idx * 2 + 2];
		pos[idx] = pos[idx * 2 + 2];	
	}
}

pair < int, int > query(int idx, int s, int e, int st, int ed){
	if(s == st && e == ed) return mp(seg[idx], pos[idx]);
	int mid = (s + e) / 2;
	if(ed <= mid) return query(idx * 2 + 1, s, mid, st, ed);
	else if(st > mid) return query(idx * 2 + 2, mid + 1, e, st, ed);
	else return max(query(idx * 2 + 1, s, mid, st, mid), query(idx * 2 + 2, mid + 1, e, mid + 1, ed));
}

LL sum[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	FOR(i, 1, n) cin >> ar[i];
	ar[n] = n;
	build(0, 1, n);
	LL res = 0;
	for(int i = n-1; i >= 1; i--){
		pair < int, int > p = query(0, 1, n, i+1, ar[i]);
		sum[i] = sum[p.yy] + n - p.yy - (ar[i] - p.yy) + p.yy - i;
		//cout << p.xx << " " << p.yy << " " << sum[i] << endl;
		res += sum[i];
	}
	cout << res << endl;
}