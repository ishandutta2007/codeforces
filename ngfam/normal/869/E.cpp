#include <bits/stdc++.h>
#define mid ((l + r) >> 1)

using namespace std;

const int N = 2510;

int sz = 0;

int n, m;


typedef pair < pair < int, int >, pair < int, int > > rec;

map < rec, long long > idx;

rec a[N * N];

long long f[N][N];


void upd(int x, int y, int val){
	for(; x < N; x += x & -x){
		for(int i = y; i < N; i += i & -i){
			f[x][i] ^= val;
		}
	}
}

long long qr(int x, int y){
	long long ans = 0;
	for(; x > 0; x &= x - 1){
		for(int i = y; i > 0; i &= i - 1){
			ans ^= f[x][i];
		}
	}
	return ans;
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int q;
	scanf("%d%d%d", &n, &m, &q);

	int sz = 0, r = 1;

	while(q--){
		int t, u, v, x, y;
		scanf("%d%d%d%d%d", &t, &u, &v, &x, &y);

		if(t == 1){
			a[++sz] = rec(make_pair(u, v), make_pair(x, y));

			long long rate = 1LL * rand() * rand();


			upd(u, v, rate);
			upd(u, y + 1, rate);
			upd(x + 1, v, rate);
			upd(x + 1, y + 1, rate);
			idx[a[sz]] = rate;

		}
		if(t == 2){
			long long rate = idx[rec(make_pair(u, v), make_pair(x, y))];
			upd(u, v, rate);
			upd(u, y + 1, rate);
			upd(x + 1, v, rate);
			upd(x + 1, y + 1, rate);
		}


		if(t == 3){
			if(qr(x, y) == qr(u, v)){
				puts("Yes");
			}
			else{
				puts("No");
			}
		}
	}

	return 0;
}