#include <iostream>
#include <string>
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
 
int A[100000];
int main(){
	ll res = 0;
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> A[i];
		res += A[i];
	}
	sort(A, A+n);
	if(res - A[n-1] < A[n-1]){
		cout << "NO";
		return 0;
	}
	if(res % 2){
		cout << "NO";
	}else{
		cout << "YES";
	}
	return 0;
}