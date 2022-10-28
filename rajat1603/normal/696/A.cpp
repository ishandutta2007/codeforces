#include "bits/stdc++.h"
using namespace std;
int q;
long long u , v;
int w;
int type;
map < long long , long long > mp;
void update(long long a , long long b , int w){
	while(a != b){
		if(a > b){
			mp[a] += w;
			a >>= 1;
		}
		else{
			mp[b] += w;
			b >>= 1;
		}
	}
}
long long query(long long a , long long b){
	long long res = 0;
	while(a != b){
		if(a > b){
			res += mp[a];
			a >>= 1;
		}
		else{
			res += mp[b];
			b >>= 1;
		}
	}
	return res;
}
int main(){
	scanf("%d" , &q);
	mp.clear();
	while(q--){
		scanf("%d %lld %lld" , &type , &u , &v);
		if(type == 1){
			scanf("%d" , &w);
			update(u , v , w);
		}
		else{
			printf("%lld\n" , query(u , v));
		}
	}
}