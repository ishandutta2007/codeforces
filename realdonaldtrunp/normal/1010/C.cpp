/**
*    author:  t0urist
*    created: 10.08.1919 11:45:14
**/

#include<bits/stdc++.h>
using namespace std;

int n;
int k;

int gcd(int a, int b){
	if (a < b)swap(a, b);
	while (a){
		swap(a, b);
		a %= b;
	}
	return b;
}
set<int> s;
int main(){
	cin >> n >> k;
	long long int gc = 0;
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		gc = gcd(gc, a);
	}
	long long int z = gc;
	while (1){
		gc %= k;
		if (s.count(gc))break;
		s.insert(gc);
		gc += z;
	}
	cout << s.size() << endl;
	bool f = false;
	for (int el : s){
		if (f == false){
			
		}
		else{
			printf(" ");
		}
		f = true;
		printf("%d", el);
	}
	puts("");
	return 0;
}