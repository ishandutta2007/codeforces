//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef double LD;
typedef complex<LD> point;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()
#define x real()
#define y imag()

const int nn = 1<<21;
const LD PI = 3.1415926535;
point a[nn];
bool hav[nn];
int n, m;

void fft(bool inv){
	for(int i = 0; i < nn; i++){
		int rev = 0;
		for(int j = 0; j < 21; j++)
			if((i>>j)&1)
				rev |= (1 << (20 - j));
		if(rev > i)
			swap(a[rev], a[i]);
	}
	for(int len = 2; len <= nn; len<<=1){
		LD ang = 2 * PI / len;
		if(inv) ang *= -1;
		point wn(cos(ang), sin(ang));
		for(int i = 0; i < nn; i += len){
			point w(1., 0.);
			for(int j = 0; j < len / 2; j++){
				point t1 = a[i + j] + w * a[i + j + len / 2];
				point t2 = a[i + j] - w * a[i + j + len / 2];
				a[i + j] = t1;
				a[i + j + len / 2] = t2;
				w *= wn;
			}
		}
	}
	if(inv) for(int i = 0; i < nn; i++) a[i] /= nn;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m, m++;
	for(int i = 0, tmp; i < n; i++){
		cin >> tmp;
		a[tmp] = 1;
		hav[tmp] = true;
	}
	fft(false);
	for(int i = 0; i < nn; i++)
		a[i] *= a[i];
	fft(true);
	vector<int> ans;
	for(int i = 0; i < nn; i++)
		if(hav[i] and a[i].x < .5)
			ans.PB(i), a[i] = point(1., 0.);
	for(int i = 0; i < m; i++)
		if(a[i].x > .5 and !hav[i]){
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n"
		<< sz(ans) << '\n';
	for(auto val : ans)
		cout << val << ' ';
	cout << '\n';
	return 0;
}