#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
#define uint unsigned int 
using namespace std;
const int N = 1e4;
int n, ns[N];
int mp[N] = {0, 16, 5, 3, 0, 9, 3};
int lstx, lsty;
pair < int, int > su[N];
pair < int, int > Get (int x) {
	cout << "+ " << x << endl;
	mp[x] += 1;
	int A = 0, B = 0;
//	L(i, 1, n) A += mp[i] * (mp[i] - 1) * (mp[i] - 2) / 6, B += mp[i] * mp[i + 1] * mp[i + 2];
	cin >> A >> B;
	A -= lstx, B -= lsty;
	lstx += A, lsty += B;
	return make_pair(A, B);
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	cin >> n;
//	L(i, 1, n) lstx += mp[i] * (mp[i] - 1) * (mp[i] - 2) / 6, lsty += mp[i] * mp[i + 1] * mp[i + 2];
	cin >> lstx >> lsty;
	R(i, n - 1, 3) 
		su[i] = Get (i);
	auto A = Get (1), B = Get (2), C = Get (1);
	ns[1] = C.first - A.first;
	ns[3] = C.second - A.second - 1;
	ns[2] = A.second / (ns[3] + 1);
	ns[4] = (B.second - (ns[1] + 1) * (ns[3] + 1)) / (ns[3] + 1) - 1;
	L(i, 3, n - 2) 
		ns[i + 2] = (su[i].second - ns[i - 1] * ns[i - 2] - ns[i - 1] * (ns[i + 1] + 1)) / (ns[i + 1] + 1) - 1;
	ns[n] += 1;
	cout << "! ";
	L(i, 1, n) cout << ns[i] << ' ';
	cout << '\n';
	return 0;
}