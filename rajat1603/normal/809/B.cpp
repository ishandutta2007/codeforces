#include "bits/stdc++.h"
using namespace std;
int n , k;
bool check(int idx , int fixed){
	if(idx >= 1 && idx <= n && idx != fixed){
		cout << "1 " << idx << " " << fixed << endl;
		fflush(stdout);
		string str;
		cin >> str;
		if(str == "TAK"){
			return 1;
		}
		return 0;
	}
	return 0;
}
int main(){
	cin >> n >> k;
	int l = 1;
	int r = n;
	while(l < r){
		int mid = l + r >> 1;
		cout << "1 " << mid << " " << mid + 1 << endl;
		fflush(stdout);
		string str;
		cin >> str;
		if(str == "TAK"){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	int idx = l;
	l = 1;
	r = idx - 1;
	while(l < r){
		int mid = l + r >> 1;
		cout << "1 " << mid << " " << mid + 1 << endl;
		fflush(stdout);
		string str;
		cin >> str;
		if(str == "TAK"){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	if(check(l , idx)){
		cout << "2 " << l << " " << idx << endl;
		fflush(stdout);
		return 0;
	}
	l = idx + 1;
	r = n;
	while(l < r){
		int mid = l + r >> 1;
		cout << "1 " << mid << " " << mid + 1 << endl;
		fflush(stdout);
		string str;
		cin >> str;
		if(str == "TAK"){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	cout << "2 " << l << " " << idx << endl;
	fflush(stdout);
}