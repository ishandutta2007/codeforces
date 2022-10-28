#include "bits/stdc++.h"
using namespace std;
int s , v1 , v2 , t1 , t2;
int main(){
	cin >> s >> v1 >> v2 >> t1 >> t2;
	int a = t1 + v1 * s + t1;
	int b = t2 + v2 * s + t2;
	if(a < b){
		printf("First\n");
	}
	if(a > b){
		printf("Second\n");
	}
	if(a == b){
		printf("Friendship\n");
	}
}