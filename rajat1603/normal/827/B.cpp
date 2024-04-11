#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , k;
int depth[N];
vector < pair < int , int > > v;
/*
	1 is root , then put k children of 1 , n - k - 1 - k

*/
int main(){
	scanf("%d %d" , &n , &k);
	depth[1] = 0;
	for(int i = 2 ; i <= k + 1 ; ++i){
		v.push_back(make_pair(1 , i));
		depth[i] = depth[1] + 1;
	}
	for(int i = k + 2 ; i <= n ; ++i){
		v.push_back(make_pair(i - k , i));
		depth[i] = depth[i - k] + 1;
	}
	printf("%d\n" , depth[n] + depth[n - 1]);
	for(auto it : v){
		printf("%d %d\n" , it.first , it.second);
	}
}