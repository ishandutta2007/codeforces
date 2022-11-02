#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
bool isPrime[1000001];
 
int32_t main(){
	isPrime[0] = isPrime[1] = 0;
	fill(isPrime + 2, isPrime + 1000001, 1);
	for(int i = 2; i <= 1000000; i++){
		if(isPrime[i]){
			for(int j = 2; (long long) i * j <= 1000000; j++){
				isPrime[i * j] = 0;
			} 
		}
	}
	long long n;
	cin >> n;
	vector<long long> A;
	if(n % 2 == 0){
		while(n % 2 == 0){
			n /= 2;
		}
		A.push_back(2);
	}
	for(int i = 3; i * i <= n; i += 2){
		if(isPrime[i] && n % i == 0){
			while(n % i == 0){
				n /= i;
			}
			A.push_back(i);
		}
	}
	if(n != 1){
		A.push_back(n);
	}
	if(A.size() >= 2){
		cout << 1 << endl;
	}else if(A.size() == 1){
		cout << A.front() << endl;
	}else{
		cout << 1 << endl;
	}
}