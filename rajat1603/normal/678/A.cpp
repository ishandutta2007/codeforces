#include "bits/stdc++.h"
using namespace std;
long long n , k;
long long ans;
int main(){
	cin >> n >> k;
	ans = (n / k) * k;
	ans += k;
	cout << ans;
}