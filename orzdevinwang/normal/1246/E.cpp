#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 16, K = 2005;
int n, k, a[N], D[N];
bitset < K > bs[1 << N];
void get (int msk, int w, int dep) {
	if(msk == 0 && w == 0) 
		return ;
	if(w * k < K && bs[msk][w * k]) 
		return get(msk, w * k, dep + 1), void ();
	L(t, 0, n - 1) if((msk >> t & 1) && w >= a[t] && bs[msk ^ (1 << t)][w - a[t]]) 
		return D[t] = dep, get (msk ^ (1 << t), w - a[t], dep), void ();
	assert (0);
}
set < pair < int, int > > st;
int main () {
//    ios :: sync_with_stdio(false);
//    cin.tie(0); cout.tie(0);
	cin >> n >> k;
	L(i, 0, n - 1) cin >> a[i];
	bs[0].set (0);
	L(i, 0, (1 << n) - 1) {
		R(j, 2000 / k, 0) if(bs[i][k * j]) bs[i].set(j);
		L(t, 0, n - 1) if(!(i >> t & 1))
			bs[i | (1 << t)] |= bs[i] << a[t];
	}
	if(!bs[(1 << n) - 1][1]) 
		return cout << "NO\n", 0;
	cout << "YES\n";
	get((1 << n) - 1, 1, 0);
	vi S;
	R(i, 100000, 0) {	
		int now = -1;
		vi Gm = S;
		S.clear ();
		L(i, 0, sz(Gm) - 1) {
			if(Gm[i] % k == 0) {
				S.push_back(Gm[i] / k);
				continue;
			}
			if(now == -1) now = Gm[i];
			else {
				cout << now << ' ' << Gm[i] << '\n', now += Gm[i];
				if(now % k == 0) {
					S.push_back(now / k);
					now = -1;
					continue;
				}
			}
		}
		L(j, 0, n - 1) {
			if(D[j] == i) {
				if(now == -1) now = a[j];
				else {
					cout << now << ' ' << a[j] << '\n', now += a[j];
					if(now % k == 0) {
						S.push_back(now / k);
						now = -1;
						continue;
					}
				}
			}
		}
	}
	return 0;
}