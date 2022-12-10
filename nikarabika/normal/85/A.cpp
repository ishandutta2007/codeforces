//sobskdrbhvk
//remember the flying, the bird dies ):(
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
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 100 + 10;
char a[4][maxn];
int n, lst;

void put(int i, int j, int ii, int jj){
	a[i][j] = lst + 'a';
	a[ii][jj] = lst + 'a';
	lst++;
	if(lst == 26) lst = 0;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	if(n&1){
		put(0, 0, 1, 0);
		for(int j = 0; j < n; j++)
			for(int i = 0; i < 4; i++)
				if(!a[i][j])
					put(i, j, i, j + 1);
		put(2, n - 1, 3, n - 1);
		a[2][n] = a[3][n] = 0;
	}
	else{
		put(1, 0, 2, 0);
		for(int j = 0; j < n; j++)
			for(int i = 0; i < 4; i++)
				if(!a[i][j])
					put(i, j, i, j + 1);
		put(1, n - 1, 2, n - 1);
		a[1][n] = a[2][n] = 0;
	}
	for(int i = 0; i < 4; i++)
		cout << a[i] << '\n';
	return 0;
}