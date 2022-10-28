#include "bits/stdc++.h"
using namespace std;
int n;
int mn = 1e9;
int mx = 0;
const bool arr[7] = {0 , 0 , 0 , 0 , 0 , 1 , 1};
int main(){
	scanf("%d" , &n);
	for(int i = 0 ; i < 7 ; ++i){
		int tot = 0;
		for(int j = 0 ; j < n ; ++j){
			int day = i + j;
			tot += (arr[day % 7]);
		}
		mx = max(mx , tot);
		mn = min(mn , tot);
	}
	cout << mn << " " << mx;
}