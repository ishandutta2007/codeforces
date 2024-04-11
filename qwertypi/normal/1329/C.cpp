#include <bits/stdc++.h>
 
using namespace std;
 
char in[1 << 27];
char const* o ;
 
// SOS!!!!
 
int f, g;
int A[1 << 20];
int ans[1 << 20];
long long cnt = 0, sum = 0;
void op(int x){
	int l = 2 * x + 1, r = 2 * x + 2;
	if(x >= (1 << f - 1) - 1 || A[l] + A[r] == 0){
		A[x] = 0;
	}else{
		if(A[l] > A[r]){
			A[x] = A[l];
			op(l);
		}else{
			A[x] = A[r];
			op(r);
		}
	}
}
bool check(int x, int level){
	if(level > f) return false;
	if(A[x] == 0) return false;
	int l = 2 * x + 1, r = 2 * x + 2;
	if(level == f || A[l] + A[r] == 0){
		return level > g;
	}else{
		if(A[l] > A[r]){
			return check(l, level + 1);
		}else{
			return check(r, level + 1);
		}
	}
}
 
inline void test(int x = 0, int level = 1){
	if(level > f) return;
	while(check(x, level)){
		op(x);
		ans[cnt++] = x;
	}
	test(x * 2 + 1, level + 1);
	test(x * 2 + 2, level + 1);
}
 
void sub(){
	cnt = 0;
	cin >> f >> g;
	for(int i = 0; i < (1 << f) - 1; i++){
		cin >> A[i];
	}
	test();
	long long all = accumulate(A, A + (1 << g) - 1, 0LL);
	cout << all << endl;
	for(int i = 0; i < cnt; i++){
		cout << ans[i] + 1 << ' ';
	}
	cout << endl;
}
 
int main(){
	cin.tie(0), cout.tie(0);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}