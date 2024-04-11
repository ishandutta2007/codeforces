#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <deque>

using namespace std;

int main(){
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int L = 1;
	int R = n;
	for(int j=0;j<n/2;j++){
		int U = 1;
		int D = m;
		for(int i=0;i<m;i++){
			cout << L << ' ' << U++ << '\n';
			cout << R << ' ' << D-- << '\n';
		}
		L++; R--;
	}
	if(n % 2){
		int U = 1;
		int D = m;
		for(int i=0;i<m/2;i++){
			cout << L << ' ' << U++ << '\n';
			cout << R << ' ' << D-- << '\n';
		}
		if(m % 2){
			cout << L << ' ' << U << '\n';
		}
	}
	return 0;
}