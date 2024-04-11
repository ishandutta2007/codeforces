#include <bits/stdc++.h>

#define int long long
using namespace std;

int n, k;
int A[1000];
int par[1000];

vector<int> seq;

void print(vector<int>& seq){
	int l = seq.size();
	for(int i = 0; i < l - 1; i++){
		cout << seq[i] << '.';
	}
	cout << seq[l - 1] << endl;
}
void sub(){
	seq.clear();
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		if(A[i] == 1){
			seq.push_back(1);
		}else{
			while(seq.back() != A[i] - 1){
				seq.pop_back();
			}
			seq[(int) seq.size() - 1] = A[i];
		}
		print(seq);
	}
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		sub();
	}
}