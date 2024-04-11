#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
char A[400000];
int r[50000];
int c[50000];
vector<int> good_r(50000);
vector<int> good_c(50000);
int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int n, m;
		cin >> n >> m;
		good_r.clear();
		good_c.clear();
		fill(r, r+n, 0);
		fill(c, c+m, 0);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				char val;
				cin >> val;
				r[i] += val == '*';
				c[j] += val == '*';
				A[i * m + j] = val;
			}
		}
		int max_r = *max_element(r, r+n);
		int max_c = *max_element(c, c+m);
		for(int i=0;i<n;i++){
			if(r[i] == max_r){
				good_r.push_back(i); 
			}
		}
		for(int j=0;j<m;j++){
			if(c[j] == max_c){
				good_c.push_back(j); 
			}
		}
		int sum = 0;
		for(auto i:good_r){
			for(auto j:good_c){
				sum += A[i*m+j] == '.';
			}
		}
		cout << n + m - max_r - max_c - (sum != 0) << endl;
	}
	return 0;
}