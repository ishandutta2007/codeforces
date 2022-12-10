#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

const int maxn = 4e5 + 85 - 69;
LL arr[maxn], Minarr[maxn], n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL *a = arr + 1;
	LL *Min = Minarr + 1;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	a[n] = a[-1] = 1000 * 1000 * 1000 + 1;
	Min[n] = n;
	for(int i = n - 1; i >= -1; i--){
		Min[i] = Min[i + 1];
		if(a[i] <= a[Min[i]])
			Min[i] = i;
	}
	LL backmin = -1;
	LL ret = 0;
	for(int i = 0; i < n; i++){
		LL cycnt = a[Min[-1]];
		LL val;
		if(a[i] == cycnt)
			val = cycnt * n;
		else if(a[Min[i + 1]] - cycnt == 0)
			val = cycnt * n + Min[i + 1] - i;
		else
			val = cycnt * n + (n - i ) + backmin;
		if(a[i] < a[backmin])
			backmin = i;
		smax(ret, val);
	}
	cout << ret << endl;
	return 0;
}