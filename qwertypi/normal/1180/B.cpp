#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#define MAX 100000
using namespace std;
vector<pair<int, int>> V;

int cmp(pair<int, int> A, pair<int, int> B){
	return A.first < B.first;
}

int cmp2(pair<int, int> A, pair<int, int> B){
	return A.second < B.second;
}

int A[100000];
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		V.push_back(pair<int, int>{i, t});
	}
	sort(V.begin(), V.end(), cmp2);
	for(int i=0;i<n;i++){
		A[i] = V[i].second;
	}
	int cnt_0 = upper_bound(A, A+n, 0) - lower_bound(A, A+n, 0);
	int neg = lower_bound(A, A+n, 0) - A;
	int pos = A + n - upper_bound(A, A+n, 0);
	for(int i = neg; i < cnt_0 + neg; i++){
		V[i].second = -1;
	}
	neg += cnt_0;
	for(int i = neg; i < n; i++){
		V[i].second = - A[i] - 1;
	}
	sort(V.begin(), V.end(), cmp2);
	if(n % 2){
		V[0].second = - V[0].second - 1;
	}
	sort(V.begin(), V.end(), cmp);
	for(int i=0;i<n;i++){
		cout << V[i].second << ' ';
	}
	return 0;
}