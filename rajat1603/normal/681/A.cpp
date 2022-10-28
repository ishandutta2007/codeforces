#include "bits/stdc++.h"
using namespace std;
int n;
string str;
int a , b;
int main(){
	cin >> n;
	while(n--){
		cin >> str >> a >> b;
		if(a >= 2400 && (b > a)){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}