//BIT mizanam ghorbatan elallah :D
#include <bits/stdc++.h>

using namespace std;

//man am A _____ & a pair of Izzz wayTn' 230u :)

typedef long long int LL;

const int maxn = 1e5 + 10;
int arr[maxn];
int n, k;

struct ABOO{
	LL a[11];
	
	ABOO(){
		memset(a, 0, sizeof a);
		return;
	}

	LL &operator[](int i){
		return a[i];
	}
	
	ABOO operator<<(int len){
		ABOO ret = *this;
		for(int i = 10; i - len >= 0; i--)
			ret[i] = ret[i - len];
		return ret;
	}
	
	ABOO operator+(ABOO &x){
		ABOO ret = *this;
		for(int i = 0; i < 11; i++)
			ret[i] += x[i];
		return ret;
	}
} fen[maxn];

ABOO get(int idx){
	ABOO ret;
	while(idx > 0){
		ret = ret + fen[idx];
		idx -= idx & -idx;
	}
	return ret;
}

void add(ABOO val, int idx){
	while(idx <= n){
		fen[idx] = fen[idx] + val;
		idx += idx & -idx;
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	for(int i = 0; i < n; i++){
		ABOO x = get(arr[i]);
		x = x << 1;
		x[0] = 1;
		add(x, arr[i]);
	}
	cout << get(n)[k] << endl;
	return 0;
}