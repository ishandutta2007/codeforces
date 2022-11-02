#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int p_A = 0, p_B = 0;
	int ans = 1;
	for(int i=0;i<n;i++){
		int a, b;
		cin >> a >> b;
		if(p_A == p_B){
			ans += max(0, min(a, b) - max(p_A, p_B));
		}else{
			ans += max(0, min(a, b) - max(p_A, p_B) + 1);
		}
		p_A = a, p_B = b;
	}
	cout << ans;
}