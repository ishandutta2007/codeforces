#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n;
char str[N];
void solve1(){
	int idx;
	for(int i = 1 ; i <= n ; ++i){
		if(str[i] == 'P'){
			idx = i;
		}
	}
	int cntl = 0;
	int timl = 0;
	int cntr = 0;
	int timr = 0;
	for(int i = idx ; i >= 1 ; --i){
		if(str[i] == '*'){
			++cntl;
			timl = idx - i;
		}
	}
	for(int i = idx ; i <= n ; ++i){
		if(str[i] == '*'){
			++cntr;
			timr = i - idx;
		}
	}
	if(cntl > cntr){
		printf("%d %d\n" , cntl , timl);
		return;
	}
	if(cntr > cntl){
		printf("%d %d\n" , cntr , timr);
		return;
	}
	printf("%d %d\n" , cntl , min(timl , timr));
}
int sum1[N];
int sum2[N];
int prv[N];
int how[N];
bool ok[N];
bool check(int mid){
	for(int i = n ; i >= 1 ; --i){
		if(str[i] == 'P'){
			if(prv[min(n , i + mid)] == i){
				how[i] = min(n , i + mid);
			}
			else{
				how[i] = how[prv[min(n , i + mid)]];
			}
		}
		else{
			how[i] = 0;
		}
	}
	ok[n + 1] = 1;
	for(int i = n ; i >= 1 ; --i){
		if(str[i] == '.'){
			ok[i] = ok[i + 1];
			continue;
		}
		if(str[i] == 'P'){
			ok[i] = ok[how[i] + 1];
			continue;
		}
		int cnt = sum2[min(n , i + mid)] - sum2[i];
		if(cnt == 0){
			ok[i] = 0;
			continue;
		}
		if(cnt == 1){
			int idx = prv[min(n , i + mid)];
			ok[i] = ok[idx + 1];
			continue;
		}
		if(cnt >= 3){
			int idx = prv[min(n , i + mid)];
			ok[i] = ok[how[idx] + 1];
			continue;
		}
		int right = prv[min(n , i + mid)];
		int left = prv[right - 1];
		if(ok[left + 1]){
			ok[i] = 1;
			continue;
		}
		int idx = prv[min(n , left + mid)];
		if(idx == right){
			ok[i] = ok[min(n , left + mid) + 1];
			continue;
		}
		ok[i] = ok[how[idx] + 1];
	}
	return ok[1];
}
int main(){
	scanf("%d" , &n);
	scanf("%s" , str + 1);
	int cnt = 0;
	for(int i = 1 ; i <= n ; ++i){
		cnt += str[i] == 'P';
	}
	if(cnt == 1){
		solve1();
		return 0;
	}
	for(int i = 1 ; i <= n ; ++i){
		sum1[i] = sum1[i - 1] + (str[i] == '*');
		sum2[i] = sum2[i - 1] + (str[i] == 'P');
		prv[i] = prv[i - 1];
		if(str[i] == 'P'){
			prv[i] = i;
		}
	}
	int l = 1;
	int r = n;
	while(l < r){
		int mid = l + r >> 1;
		if(check(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}
	printf("%d %d\n" , sum1[n] , l);
}