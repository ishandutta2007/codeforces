#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , s1 , s2;
int arr[N];
bool check(int p){
	set < int > s;
	s.insert(s1);
	s.insert(s2);
	for(int i = 1 ; i <= n ; ++i){
		while(!s.empty() && abs(*s.begin() - arr[i]) > p){
			s.erase(s.begin());
		}
		while(!s.empty() && abs(*prev(s.end()) - arr[i]) > p){
			s.erase(prev(s.end()));
		}
		if(s.empty()){
			return 0;
		}
		s.insert(arr[i]);
	}
	return 1;
}
int main(){
	scanf("%d %d %d" , &n , &s1 , &s2);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	int l = abs(s2 - s1);
	int r = 1e9 + 9;
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	printf("%d\n" , l);
}