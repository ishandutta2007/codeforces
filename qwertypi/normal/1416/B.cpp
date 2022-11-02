#include <bits/stdc++.h>
#define int long long

using namespace std;

int A[300010];

struct data{
	int i, j, x;
};

vector<data> vd;
void op(int i, int j, int x){
	A[i] = A[i] - x * (i + 1), A[j] = A[j] + x * (i + 1);
	vd.push_back({i + 1, j + 1, x});
}

void sub(){
	vd.clear();
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	long long sum = accumulate(A, A + n, 0LL);
	if(sum % n != 0){
		cout << -1 << endl;
		return;
	}
	
	long long r = sum / n;
	
	for(int i = 1; i < n; i++){
		op(0, i, ((i + 1) - A[i] % (i + 1)) % (i + 1));
		int j = 0, x = A[i] / (i + 1);
		op(i, j, x);
	}

//	for(int i = 0; i < n; i++){
//		cout << A[i] << ' ';
//	}
//	cout << endl;
	
	for(int j = 1; j < n; j++){
		int i = 0, x = r;
		op(i, j, x);
	}
	
	cout << vd.size() << endl;
	for(auto k : vd){
		cout << k.i << ' ' << k.j << ' ' << k.x << endl;
	}
	
//	for(int i = 0; i < n; i++){
//		cout << A[i] << ' ';
//	}
//	cout << endl;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}