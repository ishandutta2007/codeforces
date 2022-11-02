#include <iostream>

using namespace std;
int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int ans = 0;
		long long n;
		cin >> n;
		while(n % 3 == 0){
			n = n / 3 * 2;
			ans++; 
		}
		while(n % 5 == 0){
			n = n / 5 * 4;
			ans++;
		}
		while(n % 2 == 0){
			n /= 2;
			ans++;
		}
		if(n == 1){
			cout << ans << endl;
		}else{
			cout << -1 << endl;
		}
	}
}