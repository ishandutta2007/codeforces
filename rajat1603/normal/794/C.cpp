#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
char str1[N];
char str2[N];
int freq1[26];
int freq2[26];
char ans[N];
int l , r , who;
int main(){
	scanf("%s" , str1);
	scanf("%s" , str2);
	for(r = 0 ; str1[r] ; ++r){
		++freq1[str1[r] - 'a'];
		++freq2[str2[r] - 'a'];
	}
	l = r + 1 >> 1;
	for(int i = 0 ; i < 26 ; ++i){
		for(int j = freq1[i] ; j > 0 ; --j){
			freq1[i] -= !l;
			l -= !!l;
		}
	}
	l = r >> 1;
	for(int i = 25 ; i >= 0 ; --i){
		for(int j = freq2[i] ; j > 0 ; --j){
			freq2[i] -= !l;
			l -= !!l;
		}
	}
	while(l < r){
		int mn1 = 26 , mx1 = 0 , mn2 = 26 , mx2 = 0;
		for(int i = 0 ; i < 26 ; ++i){
			if(freq1[i]){
				mx1 = i;
				mn1 = (mn1 == 26) ? i : mn1;
			}
			if(freq2[i]){
				mx2 = i;
				mn2 = (mn2 == 26) ? i : mn2;
			}
		}
		if(who){
			if(mn1 < mx2){
				ans[l++] = 'a' + mx2;
				--freq2[mx2];
			}
			else{
				ans[--r] = 'a' + mn2;
				--freq2[mn2];
			}
		}
		else{
			if(mn1 < mx2){
				ans[l++] = 'a' + mn1;
				--freq1[mn1];
			}
			else{
				ans[--r] = 'a' + mx1;
				--freq1[mx1];
			}
		}
		who ^= 1;
	}
	printf("%s\n" , ans);
}