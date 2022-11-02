#include <bits/stdc++.h>
#define ll long long
using namespace std;

int A[200000], B[200000];

set<int> visited;

int main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	vector<int> B;
	int curCnt = 0;
	for(int i = 0; i < n; i++){
		if(A[i] < 0){
			if(visited.find(-A[i]) != visited.end()){
				visited.erase(-A[i]);
			}else{
				cout << -1;
				return 0;
			}
		}else{
			if(visited.find(A[i]) != visited.end()){
				cout << -1;
				return 0;
			}else{
				visited.insert(A[i]);
			}
		}
		curCnt++;
		if(visited.size() == 0){
			B.push_back(curCnt);
			curCnt = 0;
		}
	}
	if(visited.size() != 0){
		cout << -1;
		return 0;
	}
	curCnt = 0;
	for(auto i : B){
		set<int> used;
		for(int j = curCnt; j < curCnt + i; j++){
			if(used.find(A[j]) != used.end()){
				cout << -1;
				return 0;
			}
			used.insert(A[j]);
		}
		curCnt += i;
	}
	cout << B.size() << endl;
	for(auto i : B){
		cout << i << ' ';
	}
}