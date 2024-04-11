#include <iostream>
#include <vector>
#include <utility>
#include <random>
#include <algorithm>
#define mp make_pair
#define pb push_back 
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second

#define p 1000000007

using namespace std;
typedef long long ll;

int A[401];

void Sub(int n){
	vector<int> valid;
	int prev = -1;
	for(int i=0;i<4*n;i++){
		if(A[i] == prev){
			valid.pb(A[i]);
			prev = A[i+1];
			i++;
		}else{
			prev = A[i];
		}
	}
	vector<int> area;
	int L = 0;
	int R = valid.size()-1;
	while(L < R){
		area.pb(valid[L] * valid[R]);
		L++; R--;
	}
	if(area.size() < n){
		cout << "NO" << endl;
		return;
	}
	int standard = area[0];
	for(int i=1;i<area.size();i++){
		if(area[i] != standard){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}

int main(){
	A[400] = -1;
	int q;
	cin >> q;
	for(int C=0;C<q;C++){
		int n;
		cin >> n;
		for(int i=0;i<4*n;i++){
			cin >> A[i];
		}
		sort(A, A+4*n);
		Sub(n);
	}
	return 0;
}