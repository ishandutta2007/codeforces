#include <bits/stdc++.h>
using namespace std;
string s;
int A[7];

set<int> used;
vector<pair<int, int>> edges;

int test(){
	used.clear();
	for(auto i : edges){
	    if(A[i.first] < A[i.second])
	        used.insert(A[i.first] * 6 + A[i.second]);
	    if(A[i.first] >= A[i.second])
		    used.insert(A[i.first] + A[i.second] * 6);
	}
	return used.size();
}

int perm(int n){
	if(n == 0){
		return test();
	}
	int ans = 0;
	for(int i = 0; i < 6; i++){
		A[n-1] = i;
		ans = max(ans, perm(n-1));
	}
	return ans;
}


int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int v1, v2;
		cin >> v1 >> v2;
		if(v1 > v2){
			swap(v1, v2);
		}
		v1--; v2--;
		edges.push_back({v1, v2});
	}
	cout << perm(n);
}