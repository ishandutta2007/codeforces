#include <bits/stdc++.h>

using namespace std;

int A[250001];
int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n * n; i++){
		cin >> A[i];
	}
	multiset<int> S;
	for(int i = 0; i < n * n; i++) S.insert(A[i]);
	vector<int> v;
	for(int i = 0; i < n; i++){
		int largest = *S.rbegin();
		for(auto j : v){
			S.erase(S.find(__gcd(j, largest)));
			S.erase(S.find(__gcd(j, largest)));
		}
		v.push_back(largest);
		S.erase(S.find(largest));
	}
	for(auto i : v){
		cout << i << ' ';
	}
	cout << endl;
}