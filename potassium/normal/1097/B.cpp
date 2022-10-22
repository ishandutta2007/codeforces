#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define SP << " "
#define EL << "\n"
#define sqr(x) ((x)*(x))
//mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 x(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;

template <class T1,class T2>
ostream& operator << (ostream& out, pair<T1,T2> p) {
	cout << "(" << p.first << "," << p.second << ")";
	return out;
}

static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();

/******************************************/

int deg[15];
int perm[15];
bool isFound = 0;
int n;

void permute(int k) {
	if (k == n) {
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += perm[i]*deg[i];
			
		if (sum % 360 == 0) {
			isFound = 1;
		}
	} else {
		perm[k] = -1;
		permute(k+1);
		perm[k] = 1;
		permute(k+1);
	}
}

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++)
		cin >> deg[i];
	
	permute(0);
	
	if (isFound)
		cout << "YES";
	else
		cout << "NO";
	
	return 0;
}