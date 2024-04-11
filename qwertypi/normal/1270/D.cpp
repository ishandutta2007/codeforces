#include <bits/stdc++.h>
#define int long long
using namespace std;

set<int> query;
vector<int> det;
vector<int> nd;
int A[501];

pair<int, int> ask(){
	cout << "? "; 
	for(auto i : query){
		cout << i << ' ';
	}
	cout << endl;
	int v1, v2;
	cin >> v1 >> v2;
	return {v1, v2};
}

int32_t main(){
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= k; i++){
		query.insert(i);
	}
	for(int i = 0; i < n - k + 1; i++){ // n - k + 1 >= 2;
		pair<int, int> op = ask();
		det.push_back(op.first);
		A[op.first] = op.second;
		query.erase(op.first);
		query.insert(k + i + 1);
	}
	query.erase(n + 1);
	int c1 = det[0];
	int c2 = det[1];
	for(auto i : query){
		nd.push_back(i);
	}
	query.insert(c1);
	query.insert(c2);
	int m = 1;
	for(auto i : nd){
		query.erase(i);
		pair<int, int> op = ask();
		if(op.second == max(A[c1], A[c2])){
			m++;
		}
		query.insert(i);
	}
	cout << "! " << m << endl;
}