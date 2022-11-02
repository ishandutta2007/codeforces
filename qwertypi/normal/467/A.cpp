#include <iostream>
#include <algorithm>
#include <set>
#include <numeric> 
using namespace std;

int A[100];
int main(){
	int n;
	cin >> n;
	int ans = 0;
	for(int i=0;i<n;i++){
		int a, b;
		cin >> a >> b;
		if(b - a >= 2){
			ans++;
		}
	}
	cout << ans;
	return 0;
}