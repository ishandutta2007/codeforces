#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 5007;
int n;
ll x[N], t[N], f[N][N]; // f :  i  x_j  
bool ok[N][N], isok[N], sok[N]; // ok :  x_i x_j 
int main () {
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    memset(f, 0x3f, sizeof(f));
	cin >> n;
	L(i, 1, n) cin >> t[i] >> x[i];
	isok[0] = sok[0] = true;
	L(i, 0, n) {
		L(j, 1, n) isok[i] |= ok[i][j];
		if(!isok[i]) 
			return cout << "NO\n", 0;
		if(sok[i]) {
			L(j, i + 1, n) f[i][j] = min(f[i][j], t[i] + abs (x[i] - x[j])); 
		}
			
		if(t[i] + abs(x[i] - x[i + 1]) <= t[i + 1]) 
			isok[i + 1] = true;
		
		if(i > 0) {
			if(abs (x[i] - x[i + 1]) + t[i] <= t[i + 1]) {
				L(j, i + 2, n) if(ok[i][j]) {
					ok[i + 1][j] = true;
				}
				isok[i + 1] = true;
				sok[i + 1] = true;
			}
			if(ok[i][i + 1]) {
				isok[i + 1] = true;
				L(j, i + 2, n) {
					f[i + 1][j] = min(f[i + 1][j], max(t[i + 1], t[i] + abs (x[i] - x[j])));
				}
				if(t[i] + abs (x[i] - x[i + 2]) <= t[i + 2]) 
					isok[i + 2] = true, sok[i + 2] = true;
			}
		}
		
		L(j, i + 2, n) 
			if(abs (x[i + 1] - x[j]) + f[i][j] <= t[i + 1])	{
				ok[i + 1][j] = true;
			}
		
		if(f[i][i + 1] <= t[i + 1]) {
			if(f[i][i + 1] + abs (x[i + 1] - x[i + 2]) <= t[i + 2]) 
				isok[i + 2] = true, sok[i + 2] = true;
			isok[i + 1] = true;
		}
		
		L(j, i + 2, n) {
			f[i + 1][j] = min(f[i + 1][j], max(t[i + 1], f[i][i + 1] + abs (x[i + 1] - x[j])));
		}
	} 
	cout << "YES\n";
	return 0;
}
/*
3
16 16
17 1
18 2
*/