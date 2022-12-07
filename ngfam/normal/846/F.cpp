#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

struct SegmentTree{

	int Value[N * 8];
	int Lazy[N * 8];

	#define mid ((l + r) >> 1)
	#define ii (i << 1)

	void Down(int i){
		if(Lazy[i] != 0){
			Lazy[ii] += Lazy[i];
			Lazy[ii + 1] += Lazy[i];
			Value[i] += Lazy[i];
		}
		Lazy[i] = 0;
	}
	
	void upd(int i, int l, int r, int x, int y, int val){
		Down(i);
		if(l > y || r < x){
			return;
		}
		if(l >= x && r <= y){
			Lazy[i] += val;
			Down(i);
			return;
		}

	}

};

int last[N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int n;
	scanf("%d", &n);

	long double tot = -n;
	long double sumqr = 1LL * n * n;

	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		tot += 2LL * (i - last[x]) * (n - i + 1);
		last[x] = i;
	}

	cout << fixed << setprecision(7) << tot / sumqr;

	return 0;
}