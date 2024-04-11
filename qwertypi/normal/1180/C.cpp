#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <deque>
#define MAX 100000
using namespace std;

int before[100000][2];
int cycle[99999][2];
int init = 0, cyc = 0;
int main(){
	int n, q;
	cin >> n >> q;
	if(q == 0){
		return 0; 
	} 
	deque<int> A(n);
	for(int i=0;i<n;i++){
		cin >> A[i];
	}
	int maximum = *max_element(A.begin(), A.end());
	while(A[0] != maximum){
		int a = A.front();
		A.pop_front();
		int b = A.front();
		A.pop_front();
		if(a > b){
			A.push_front(a);
			A.push_back(b);
		}else{
			A.push_front(b);
			A.push_back(a);
		}
		before[init][0] = a;
		before[init][1] = b;
		init++;
	}
	cyc = n - 1;
	for(int i=0;i<cyc;i++){
		cycle[i][0] = A[0];
		cycle[i][1] = A[i+1]; 
	}
	for(int i=0;i<q;i++){
		long long m;
		cin >> m;
		if(m == 0){
			cout << A[0] << ' ' << A[1] << endl;
		}
		m--;
		if(m >= init){
			int pos = (m - init) % cyc;
			cout << cycle[pos][0] << ' ' << cycle[pos][1] << endl;
		}else{
			cout << before[m][0] << ' ' << before[m][1] << endl;
		}
	}
	return 0;
}