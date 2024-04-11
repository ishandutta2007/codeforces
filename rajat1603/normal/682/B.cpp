#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
multiset < int > mp;
int main(){
	scanf("%d" , &n);
	mp.clear();
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
		mp.insert(arr[i]);
	}
	for(int i = 1 ; i ; ++i){
		if(mp.find(i) == mp.end()){
			auto it = mp.lower_bound(i);
			if(it == mp.end()){
				cout << i << endl;
				return 0;
			}
			mp.erase(it);
		}
	}
}