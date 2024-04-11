#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int n , k;
int arr[N];
int spf[N];
void pre(){
	memset(spf , 0 , sizeof(spf));
	spf[1] = 1;
	for(int i = 2 ; i < N ; ++i){
		if(!spf[i]){
			for(int j = i ; j < N ; j += i){
				if(!spf[j]){
					spf[j] = i;
				}
			}
		}
	}
}
int main(){
	pre();
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	map < int , int > facs;
	facs.clear();
	while(k > 1){
		++facs[spf[k]];
		k /= spf[k];
	}
	for(int i = 1 ; i <= n ; ++i){
		int val = arr[i];
		map < int , int > tmp;
		tmp.clear();
		while(val > 1){
			++tmp[spf[val]];
			val /= spf[val];
		}
		for(auto it : tmp){
			int base = it.first;
			int expo = it.second;
			if(facs.find(base) != facs.end()){
				if(expo >= facs[base]){
					facs.erase(base);
				}
			}
		}
	}
	if(facs.empty()){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
}