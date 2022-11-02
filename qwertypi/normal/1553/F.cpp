#include <bits/stdc++.h>
 
#define int long long
#define MAXN 300000LL
using namespace std;
 
int powmod(int a, int b, int p){
	int res = 1;
	while(b){
		if(b % 2){
			res = (res * a) % p;
		}
		b /= 2;
		a = (a * a) % p;
	}
	return res;
}
 
// cp-algorithms
struct FenwickTree {
    vector<int> bit;
    int n;
 
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }
 
    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }
 
    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
 
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
 
    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
} ;
 
FenwickTree fta(300013), ftb(300013);
 
int A[300001], p[300001];
int B[300001];
void sub(){
	for(int i = 1; i <= MAXN; i++){
		B[i] = floor(sqrt(i));
	}
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	
	int ans = 0;
	int s = 0;
	for(int i = 0; i < n; i++){
		ans += s + A[i] * i;
		s += A[i];
		ans -= fta.sum(A[i]);
		for(int j = A[i]; j <= MAXN; j += A[i]){
			ans -= j * (ftb.sum(min(MAXN, j + A[i] - 1)) - ftb.sum(j - 1));
		}
		p[i] = ans;
		for(int j = A[i]; j <= MAXN; j += A[i]){
			fta.add(j, A[i]);
		}
		ftb.add(A[i], 1);
		
	}
	for(int i = 0; i < n; i++){
		cout << p[i] << ' ';
	}
	cout << endl;
}
 
 
int32_t main(){
	int J;
	J = 1;
	while(J--){
		sub();
	}
}