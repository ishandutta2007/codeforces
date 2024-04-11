#include "bits/stdc++.h"
using namespace std;
long long n , k;
int main(){
	cin >> n >> k;
	if(((n / k)) & 1){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}