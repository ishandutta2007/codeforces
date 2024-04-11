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
 
int A[100000], B[100000];
int main(){
	int n, m;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
	} 
	cin >> m;
	for(int i=0;i<m;i++){
		cin >> B[i];
	}
	cout << *max_element(A, A+n) << ' ' << *max_element(B, B+m);
	return 0;
}