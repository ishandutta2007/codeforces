#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n;
int arr[N];
int lft1[N];
int lft2[N];
int rgt1[N];
int rgt2[N];
stack < int > s1 , s2 , s3 , s4;
long long ans;
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		while(!s1.empty() && arr[s1.top()] <= arr[i]){
			s1.pop();
		}
		if(s1.empty()){
			lft1[i] = 1;
		}
		else{
			lft1[i] = s1.top() + 1;
		}
		s1.push(i);
		while(!s2.empty() && arr[s2.top()] >= arr[i]){
			s2.pop();
		}
		if(s2.empty()){
			lft2[i] = 1;
		}
		else{
			lft2[i] = s2.top() + 1;
		}
		s2.push(i);
	}
	for(int i = n ; i >= 1 ; --i){
		while(!s3.empty() && arr[s3.top()] < arr[i]){
			s3.pop();
		}
		if(s3.empty()){
			rgt1[i] = n;
		}
		else{
			rgt1[i] = s3.top() - 1;
		}
		s3.push(i);
		while(!s4.empty() && arr[s4.top()] > arr[i]){
			s4.pop();
		}
		if(s4.empty()){
			rgt2[i] = n;
		}
		else{
			rgt2[i] = s4.top() - 1;
		}
		s4.push(i);
	}
	for(int i = 1 ; i <= n ; ++i){
		ans += 1LL * arr[i] * (i - lft1[i] + 1LL) * (rgt1[i] - i + 1LL);
		ans -= 1LL * arr[i] * (i - lft2[i] + 1LL) * (rgt2[i] - i + 1LL);
	}
	printf("%lld\n" , ans);
}