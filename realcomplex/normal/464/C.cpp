#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<ll, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int MOD = (int)1e9 + 7;

void add(int &a, int b){
	a += b;
	if(a >= MOD)
		a -= MOD;
}

void multi(int &a, int b){
	a = (a * 1ll * b) % MOD;
}

int main(){
	fastIO;
	string t;
	cin >> t;
	int n;
	cin >> n;
	string qr[n];
	for(int i = 0 ; i < n;i  ++ )
		cin >> qr[i];
	int f[10];
	int rz[10];
	for(int i = 0; i < 10; i ++ )
		f[i] = i, rz[i]= 10;
	int sum, tp;
	int idx;
	int tdig;
	int vl;
	for(int i = n - 1; i >= 0 ; i -- ){
		sum = 0;
		tp = 1;
		idx = qr[i][0] - '0';
		for(int j = qr[i].size() - 1; j > 2 ; j -- ){
			tdig = qr[i][j] - '0';
			vl = f[tdig];
			multi(vl, tp);
			add(sum, vl);
			multi(tp, rz[tdig]);
		}
		f[idx] = sum;
		rz[idx] = tp;
	}
	sum = 0;
	tp = 1;
	for(int j = t.size() - 1; j >= 0 ; j -- ){
		tdig = t[j] - '0';
		vl = f[tdig];
		multi(vl, tp);
		add(sum, vl);
		multi(tp, rz[tdig]);
	}
	cout << sum;
	return 0;
}