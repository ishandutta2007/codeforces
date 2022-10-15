#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
const int maxn = 107;
typedef vector<ll> row;
typedef vector< row > matrix;
 
matrix matexpo(matrix A, ll ex) {
	matrix B, C, D;
	int n = A.size(); 
	C = *new matrix(n); B = *new matrix(n); D = *new matrix(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C[i].push_back(i == j);
			B[i].push_back(A[i][j]);
			D[i].push_back(0);
		}
	}
	while (ex > 0) {
		//cout<<ex<<endl;
		if (ex & 1ll) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					D[i][j] = 0;
					for (int k = 0; k < n; k++) {
						D[i][j] = (D[i][j] + C[i][k] * B[k][j])%md;
					}
				}
			}
			for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) C[i][j] = D[i][j];
		}
		ex >>= 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				D[i][j] = 0;
				for (int k = 0; k < n; k++) {
					D[i][j] = (D[i][j] + B[i][k] * B[k][j])%md;
				}
			}
		}
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) B[i][j] = D[i][j];
	}
	return C;
}
 
ll a[maxn];
 
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; ll k; cin>>n>>k;
	matrix M, A;
	M.resize(n);
	for (int i = 0; i < n; i++) {
		cin>>a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			M[i].push_back( __builtin_popcountll(a[i] ^ a[j])%3 == 0 );
			//cout<<M[i][j]<<" ";
		}
		//cout<<endl;
	}
	A = matexpo(M, k - 1);
	ll res = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) res = (res + A[i][j])%md;
	cout<<res<<endl;
}