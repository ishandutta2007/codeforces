#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>
using namespace std;
vector<pair<int, int>> A(100);
bool B[100];

int cmp(pair<int, int> A, pair<int, int> B){
    return A.second < B.second;
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
	    int val;
		cin >> val;
		A[i] = pair<int, int>{i, val};
		B[i] = 0;
	}
	B[0] = 1;
	int sum = 0;
	for(int i=0;i<n;i++){
	    sum += A[i].second;
	}
	int half = sum / 2 + 1;
	sort(A.begin()+1, A.begin()+n, cmp);
	int cnt = 1;
	int sum_t = A[0].second;
	for(int i=n-1;i>0;i--){
		if(sum_t >= half){
			cout << cnt << endl;
			for(int i=0;i<n;i++){
				if(B[i]){
					cout << i+1 << ' ';
				}
			}
			return 0;
		}
		if(A[i].second * 2 <= A[0].second){
			sum_t += A[i].second;
			B[A[i].first] = 1;
			cnt++;
		}
	}
	if(sum_t >= half){
		cout << cnt << endl;
		for(int i=0;i<n;i++){
			if(B[i]){
				cout << i+1 << ' ';
			}
		}
	}else{
		cout << 0;
	}
	return 0;
}