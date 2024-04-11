#include "bits/stdc++.h"
using namespace std;
const int N = 205;
int n , k;
int arr[N];
int ans = -1e9;
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	for(int l = 1 ; l <= n ; ++l){
		int sum = 0;
		multiset < int > s1;
		s1.clear();
		for(int r = l ; r <= n ; ++r){
			sum += arr[r];
			s1.insert(arr[r]);
			multiset < int > s2;
			s2.clear();
			for(int i = 1 ; i <= n ; ++i){
				if(i < l || i > r){
					s2.insert(arr[i]);
					while(s2.size() > k){
						s2.erase(s2.begin());
					}
				}
			}
			int cnt = min(k , int(s1.size()));
			int tmpsum = sum;
			ans = max(ans , tmpsum);
			auto it = s1.begin();
			for(int i = 0 ; i < cnt ; ++i){
				tmpsum -= *it;
				s2.insert(*it);
				++it;
			}
			it = prev(s2.end());
			for(int i = 0 ; i < cnt ; ++i){
				tmpsum += *it;
				--it;
			}
			ans = max(ans , tmpsum);
		}
	}
	printf("%d\n" , ans);
}