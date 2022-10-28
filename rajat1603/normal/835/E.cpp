#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
int n , x , y;
int res[10];
int get(vector < int > who){
	vector < int > lft , rgt;
	while(who.size() > 1){
		lft.clear();
		rgt.clear();
		for(int i = 0 ; i < who.size() ; ++i){
			if(i & 1){
				lft.emplace_back(who[i]);
			}
			else{
				rgt.emplace_back(who[i]);
			}
		}
		printf("? %d" , int(lft.size()));
		for(int x : lft){
			printf(" %d" , x);
		}
		printf("\n");
		fflush(stdout);
		int ans;
		scanf("%d" , &ans);
		if((ans == y) || (ans == (x ^ y))){
			who.swap(lft);
		}
		else{
			who.swap(rgt);
		}
	}
	return who.back();
}
int main(){
	vector < int > who;
	who.clear();
	cin >> n >> x >> y;
	for(int i = 0 ; i < 10 ; ++i){
		vector < int > tmp;
		tmp.clear();
		for(int j = 1 ; j <= n ; ++j){
			if((j >> i) & 1){
				tmp.emplace_back(j);
			}
		}
		if(!tmp.empty()){
			printf("? %d" , int(tmp.size()));
			for(int x : tmp){
				printf(" %d" , x);
			}
			printf("\n");
			fflush(stdout);
			scanf("%d" , &res[i]);
			if((res[i] == y) || (res[i] == (x ^ y))){
				who.swap(tmp);
			}
		}
	}
	int ans1 = get(who);
	int ans2 = 0;
	for(int i = 0 ; i < 10 ; ++i){
		bool one = (res[i] == y) || (res[i] == (x ^ y));
		if((ans1 >> i) & 1){
			if(one){

			}
			else{
				ans2 ^= 1 << i;
			}
		}
		else{
			if(one){
				ans2 ^= 1 << i;
			}
			else{

			}
		}
	}
	if(ans1 > ans2){
		swap(ans1 , ans2);
	}
	printf("! %d %d\n" , ans1 , ans2);
	fflush(stdout);
}