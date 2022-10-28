#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
char a[N];
char b[N];
long long arr[N];
int n , m;
void check(long long a , long long b){
	//a * q + b == 0 , < 0 , > 0
	int ans;
	if(a == 0){
		if(b == 0){
			ans = 0;
		}
		else if(b < 0){
			ans = -1;
		}
		else{
			ans = 1;
		}
	}
	else{
		double q = 1 + sqrt(5);
		q /= 2;
		q *= a;
		q += b;
		if(q < 0){
			ans = -1;
		}
		else{
			ans = 1;
		}
	}
	printf("%c" , "<=>"[ans + 1]);
}
int main(){
	scanf("%s" , a);
	scanf("%s" , b);
	n = strlen(a);
	m = strlen(b);
	reverse(a , a + n);
	reverse(b , b + m);
	for(int i = n ; i < m ; ++i){
		a[i] = '0';
	}
	for(int i = m ; i < n ; ++i){
		b[i] = '0';
	}
	n = max(n , m);
	m = max(m , n);
	reverse(a , a + n);
	reverse(b , b + n);
	for(int i = 0 ; i < n ; ++i){
		arr[i] = a[i] - b[i];
	}
	for(int i = 0 ; i + 2 < n ; ++i){
		if(arr[i] > 1e15){
			printf(">");
			return 0;
		}
		if(arr[i] < -1e15){
			printf("<");
			return 0;
		}
		arr[i + 1] += arr[i];
		arr[i + 2] += arr[i];
	}
	check(arr[n - 2] , arr[n - 1]);
}