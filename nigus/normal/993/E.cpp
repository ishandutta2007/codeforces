#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

const ll big = 1000000007;
const ll mod = 998244353;
ll x;
double pi;

#pragma once

typedef complex<double> C;
typedef vector<double> vd;

void fft(vector<C> &a, vector<C> &rt, vi& rev, int n) {
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
	}
}

vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n), rt(n, 1); vi rev(n);
	rep(i,0,n) rev[i] = (rev[i/2] | (i&1) << L) / 2;
	for (int k = 2; k < n; k *= 2) {
		C z[] = {1, polar(1.0, pi / k)};
		rep(i,k,2*k) rt[i] = rt[i/2] * z[i&1];
	}
	copy(all(a), begin(in));
	rep(i,0,sz(b)) in[i].imag(b[i]);
	fft(in, rt, rev, n);
	trav(x, in) x *= x;
	rep(i,0,n) out[i] = in[(n - i) & (n - 1)] - conj(in[i]);
	fft(out, rt, rev, n);
	rep(i,0,sz(res)) res[i] = imag(out[i]) / (4*n);
	return res;
}


ll n,m,k,q,p;

ll ANS[200002] = {0};

//vd A1,A2,res;
vl A;
void treat(ll l, ll r){
    if(l == r){
        ANS[A[l]]++;
        return;
    }
    ll mid = (l+r)/2;
    treat(l,mid);
    treat(mid+1,r);

    vd A1;
    vd A2;
    vd res;
    //A1.clear();
    //A2.clear();
    //res.clear();
    ll x1 = 0;
    A1.push_back(0);
    for(int c1 = mid; c1 >= l; c1--){
        if(A[c1] == 1){x1++;A1.push_back(0);}
        A1[x1]++;
    }

    ll x2 = 0;
    A2.push_back(0);
    for(int c1 = mid+1; c1 <= r; c1++){
        if(A[c1] == 1){x2++;A2.push_back(0);}
        A2[x2]++;
    }

    res = conv(A1,A2);

    for(int c1 = 0; c1 < sz(res); c1++){
        ANS[c1] += round(res[c1]);
    }
    return;
}

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("autput.txt","w",stdout);
    ll a,b,c,d;
    pi = acos(-1);
    //cout << pi;
    cin >> n >> x;
   // n = 100000;
    //x = 10;
    for(int c1 = 0; c1 < n; c1++){
        cin >> a;
        //a = rand()%20;
        if(a < x){
            a = 1;
        }else{a = 0;}
        A.push_back(a);
    }
    treat(0,n-1);

    for(int c1 = 0; c1 <= n; c1++){
        cout << ANS[c1] << " ";
    }

    return 0;
}