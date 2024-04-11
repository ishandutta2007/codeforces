#include <iostream>
#include <vector>
#include <utility>
#include <random>

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

int A[200];
int main(){
	int q;
	cin >> q;
	for(int C = 0; C<q; C++){
		int n;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> A[i];
		}
		int res = 0;
		for(int i=0;i<n-1;i++){
			if(abs(A[i] - A[i+1]) != n - 1 && abs(A[i] - A[i+1]) != 1){
				cout << "NO" << endl;
				goto Ans;
			}
		}
		if(abs(A[0] - A[n-1]) != n - 1 && abs(A[0] - A[n-1]) != 1){
			cout << "NO" << endl;
			goto Ans;
		}
		cout << "YES" << endl;
		Ans:
		;
	}
	return 0;
}