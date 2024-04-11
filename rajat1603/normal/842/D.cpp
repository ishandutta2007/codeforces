#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
const int SN = 1 << 21;
const int LN = 19;
int n , m;
int arr;
int val;
int siz[SN];
bool there[N];
void insert(){
	if(there[arr]){
		return;
	}
	there[arr] = 1;
	int node = 1;
	for(int i = LN - 1 ; i >= 0 ; --i){
		node = node + node + ((arr >> i) & 1);
		++siz[node];
	}
}
void query(){
	int node = 1;
	int num = 0;
	for(int i = LN - 1 ; i >= 0 ; --i){
		if((val >> i) & 1){
			if(siz[node + node + 1] == (1 << i)){
				node = node + node;
				num += 1 << i;
			}
			else{
				node = node + node + 1;
			}
		}
		else{
			if(siz[node + node] == (1 << i)){
				node = node + node + 1;
				num += 1 << i;
			}
			else{
				node = node + node;
			}
		}
	}
	printf("%d\n" , num);
}
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 0 ; i < n ; ++i){
		scanf("%d" , &arr);
		insert();
	}
	while(m--){
		scanf("%d" , &arr);
		val ^= arr;
		query();
	}
}