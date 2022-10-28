#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n;
char str[N];
int ans;
pair < char , int > arr[N];
pair < char , int > tmp[N];
int siz;
void solve(){
	while(siz > 1){
		++ans;
		int ss = 0;
		for(int i = 1 ; i <= siz ; ++i){
			int val = arr[i].second;
			if(i == 1 || i == siz){
				val -= 1;
			}
			else{
				val -= 2;
			}
			if(val > 0){
				tmp[++ss] = {arr[i].first , val};
			}
		}
		siz = 0;
		int cur = tmp[1].first;
		int cnt = 0;
		for(int i = 1 ; i <= ss ; ++i){
			if(tmp[i].first == cur){
				cnt += tmp[i].second;
			}
			else{
				arr[++siz] = {cur , cnt};
				cur = tmp[i].first;
				cnt = tmp[i].second;
			}
		}
		arr[++siz] = {cur , cnt};
	}
}
int main(){
	scanf("%s" , str + 1);
	n = strlen(str + 1);
	siz = 0;
	int cur = str[1];
	int cnt = 0;
	for(int i = 1 ; i <= n ; ++i){
		if(str[i] == cur){
			++cnt;
		}
		else{
			arr[++siz] = {cur , cnt};
			cnt = 1;
			cur = str[i];
		}
	}
	arr[++siz] = {cur , cnt};
	ans = 0;
	solve();
	printf("%d\n" , ans);
}