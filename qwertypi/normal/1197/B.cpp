#include <iostream>
#include <algorithm>
using namespace std;

int A[200000];
int order[200000];

int cmp(int a, int b){
	return A[a] > A[b];
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
		order[i] = i;
	}
	sort(order, order + n, cmp);
	int L = order[0];
	int R = order[0];
	for(int i=1;i<n;i++){
		if(abs(L - order[i]) != 1 && abs(R - order[i]) != 1){
			cout << "NO";
			return 0;
		}
		if(order[i] < L){
			L = order[i];
		}else{
			R = order[i];
		}
	}
	cout << "YES";
	return 0;
}