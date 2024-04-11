
 #include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define mp make_pair
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second
 
#define p 1000000007
 
using namespace std;
 
typedef long long ll;
 
int A[200000];
int main(){
	int n;
	cin >> n;
	if(n % 2 == 0){
		cout << "NO";
		return 0;
	}
	cout << "YES" << endl;
	int seq[4] = {n, 1, -n, 1};
	A[0] = 1;
	A[2*n-1] = 2*n;
	int cur = 0;
	for(int i=0;i<2*n/4;i++){
		for(int j=0;j<4;j++){
			cur += seq[j];
			A[cur] = i * 4 + j + 2;
		}
	}
	for(int i=0;i<2*n;i++){
		cout << A[i] << ' ';
	}
	return 0;
}