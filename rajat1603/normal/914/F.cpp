#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
char str[N];
int n;
int q;
char tmp[N];
bitset < N > bit[26];
bitset < N > ans;
int main(){
	scanf("%s" , str + 1);
	n = strlen(str + 1);
	for(int i = 1 ; i <= n ; ++i){
		bit[str[i] - 'a'][i] = 1;
	}
	scanf("%d" , &q);
	while(q--){
		int type;
		scanf("%d" , &type);
		if(type == 1){
			int idx;
			scanf("%d" , &idx);
			char ss[5];
			scanf("%s" , ss);
			bit[str[idx] - 'a'][idx] = 0;
			str[idx] = ss[0];
			bit[str[idx] - 'a'][idx] = 1;
			continue;
		}
		int l , r;
		scanf("%d %d" , &l , &r);
		scanf("%s" , tmp + 1);
		ans.reset();
		ans = ~ans;
		int len = 0;
		for(int i = 1 ; tmp[i] ; ++i){
			ans &= bit[tmp[i] - 'a'] >> i;
			++len;
		}
		if(r - len + 1 < l){
			printf("0\n");
			continue;
		}
		ans >>= l - 1;
		int val = ans.count();
		ans >>= (r - len + 1) - l + 1;
		val -= ans.count();
		printf("%d\n" , val);
	}
}