#include "bits/stdc++.h"
using namespace std;
const int LN = 27;
const int SN = 3e6 + 6;
int siz[SN];
int nxt[SN][2];
int cur;
int n;
int type , a , b;
void update(int num , int add){
	int node = 1;
	for(int i = LN - 1 ; i >= 0 ; --i){
		bool bit = ((num >> i) & 1);
		if(!nxt[node][bit]){
			nxt[node][bit] = ++cur;
		}
		node = nxt[node][bit];
		siz[node] += add;
	}
}
int query(int a , int b){
	int res = 0;
	int node = 1;
	int num = 0;
	for(int i = LN - 1 ; i >= 0 && node ; --i){
		bool abit = ((a >> i) & 1);
		bool bbit = ((b >> i) & 1);
		num += num;
		if(bbit){
			res += siz[nxt[node][abit]];
			node = nxt[node][!abit];
			num += !abit;
		}
		else{
			node = nxt[node][abit];
			num += abit;
		}
	}
	printf("%d\n" , res);
}
int main(){
	cur = 1;
	scanf("%d" , &n);
	while(n--){
		scanf("%d %d" , &type , &a);
		if(type == 1){
			update(a , 1);
		}
		else if(type == 2){
			update(a , -1);
		}
		else{
			scanf("%d" , &b);
			query(a , b);
		}
	}
}