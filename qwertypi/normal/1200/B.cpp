#include <iostream>
#include <vector>
#include <utility>

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

int A[100];
int main(){
	int t;
	cin >> t;
	for(int Case = 0; Case < t; Case++){
		int n, m, k;
		cin >> n >> m >> k;
		for(int i=0;i<n;i++){
			cin >> A[i];
		}
		int curH = A[0];
		bool End = false;
		for(int i=0;i<n-1;i++){
			if(A[i] >= A[i+1] - k){
				int _new = max(A[i+1] - k, 0);
				m += A[i] - _new;
			}else{
				m -= A[i+1] - k - A[i];
				if(m < 0){
					cout << "NO" << endl;
					End = true;
					break;
				}
			}
		}
		if(End){
			continue;
		}
		cout << "YES" << endl;
	}
	return 0;
}