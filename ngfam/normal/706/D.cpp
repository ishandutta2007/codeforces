#include <bits/stdc++.h>

using namespace std;

const int N = 234567;

int trie[N * 40][2], sz, cnt[N * 40];

void add(int x){
	int node = 0;
	for(int i = 30; i >= 0; --i){
		int shift = x & (1 << i); 
		if(shift > 0) shift = 1;
		if(trie[node][shift] == 0){
			trie[node][shift] = ++sz;	
		}
		node = trie[node][shift];
		++cnt[node];
	}
}

void away(int x){
	int node = 0;
	for(int i = 30; i >= 0; --i){
		int shift = x & (1 << i);
		if(shift > 0) shift = 1; 
		node = trie[node][shift];
		--cnt[node];
	}
}

int fin(int x){
	int node = 0, ans = 0;
	for(int i = 30; i >= 0; --i){
		int shift = (x & (1 << i));
		if(shift > 0) shift = 1;
		if(cnt[trie[node][1 - shift]] > 0){
			node = trie[node][1 - shift];
			ans += 1 << i;
		}
		else{
			node = trie[node][shift];
		}
	}
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	int q; scanf("%d", &q);
	add(0);

	for(int i = 1; i <= q; ++i){
		char quest[5]; int val;
		scanf("%s %d", quest, &val);

		if(quest[0] == '+') add(val);
		else{
			if(quest[0] == '-'){
				away(val);
			}
			else{
				printf("%d\n", fin(val));
			}
		}
	}

	return 0;
}