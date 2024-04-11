#include "bits/stdc++.h"
using namespace std;
const int N = 1 << 10;
int n;
int pos0 , pos1;
void solve(int l , int r , int val , int valcnt){
	if(l == r){
		if(val){
			pos1 = l;
		}
		else{
			pos0 = r;
		}
		return;
	}
	int mid = l + r >> 1;
	cout << "? ";
	for(int i = 1 ; i <= n ; ++i){
		if(i < l || i > mid){
			cout << val;
		}
		else{
			cout << 1 - val;
		}
	}
	cout << endl;
	fflush(stdout);
	int res;
	cin >> res;
	if(res == valcnt - (mid - l + 1)){
		solve(mid + 1 , r , val , valcnt);
	}
	else{
		solve(l , mid , val , valcnt);
	}
}
int main(){
	cin >> n;
	cout << "? ";
	for(int i = 0 ; i < n ; ++i){
		cout << "0";
	}
	cout << endl;
	fflush(stdout);
	int res;
	cin >> res;
	cout << "? ";
	cout << "1";
	for(int i = 1 ; i < n ; ++i){
		cout << "0";
	}
	cout << endl;
	fflush(stdout);
	int res2;
	cin >> res2;
	int x;
	if(res2 < res){
		pos1 = 1;
		x = 0;
	}
	else{
		pos0 = 1;
		x = 1;
	}
	solve(1 , n , x , x ? n - res : res);
	cout << "! " << pos0 << " " << pos1 << endl;
	fflush(stdout);
}