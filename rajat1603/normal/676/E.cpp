#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int lol = 54321;
int n , k;
int arr[N];
char str[10];
int qcnt = 0;
int turn = 0;
inline int add(int a , int b , int mod){
	return (a + b < mod) ? (a + b) : (a + b - mod); 
}
inline int mult(int a , int b , int mod){
	return (1LL * a * b) % mod;
}
inline int fix(int num , int mod){
	return ((num % mod) + mod) % mod;
}
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 0 ; i <= n ; ++i){
		scanf("%s" , str);
		if(str[0] == '?'){
			arr[i] = lol;
			++qcnt;
		}
		else{
			arr[i] = 0;
			int j = 0;
			int mul = 1;
			if(str[0] == '-'){
				j = 1;
				mul = -1;
			}
			for(; str[j] ; ++j){
				arr[i] *= 10;
				arr[i] += str[j] - '0';
			}
			arr[i] *= mul;
			turn ^= 1;
		}
	}
	if(k == 0){
		if(arr[0] == 0){
			cout << "Yes\n";
			return 0;
		}
		if(arr[0] != lol){
			cout << "No\n";
			return 0;
		}
		if(turn == 0){
			cout << "No\n";
			return 0;
		}
		if(turn == 1){
			cout << "Yes\n";
			return 0;
		}
	}
	if(!qcnt){
		for(int i = 0 ; i <= n ; ++i){
			if(arr[i] % k){
				cout << "No\n";
				return 0;
			}
			arr[i] /= k;
			arr[i + 1] += arr[i];
		}
		if(arr[n] != 0){
			printf("No\n");
			return 0;
		}
		printf("Yes\n");
		return 0;
	}
	for(int i = 0 ; i < qcnt - 1 ; ++i){
		turn ^= 1;
	}
	if(turn == 1){
		cout << "Yes\n";
	}
	else{
		cout << "No\n";
	}
}