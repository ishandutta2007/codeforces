#include <iostream>

using namespace std;
int cnt[2] = {0, 0};
int A[150000];
int main(){
	int q;
	cin >> q;
	while(q--){
		int n;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> A[i];
		}
		int _min = (1 << 30);
		int ans = 0;
		for(int i=n-1;i>=0;i--){
			if(A[i] > _min){
				ans++;
			}
			_min = min(A[i], _min);
		}
		cout << ans << endl;
	}
}