#include <iostream>

using namespace std;
typedef long long ll;
long long f(long long x, long long t){
	long long ans = 0;
	while(x / t){
		ans += x % t + 1;
		x /= t;
	}
	ans += x;
	return ans;
}

int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		long long v1, v2;
		cin >> v1 >> v2;
		cout << f(v1, v2) << endl;
	}
}