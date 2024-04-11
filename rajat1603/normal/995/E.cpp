#include "bits/stdc++.h"
using namespace std;
int s , t , p;
inline int one(int x){
	return x < (p - 1) ? x + 1 : 0;
}
inline int two(int x){
	return x ? x - 1 : (p - 1);
}
inline int three(int x){
	int res = 1;
	int b = p - 2;
	while(b){
		if(b & 1){
			res = (1LL * res * x) % p;
		}
		x = (1LL * x * x) % p;
		b >>= 1;
	}
	return res;
}
pair < int , int > arr[50000];
int v[50000][100];
int lol[100];
int get(int node , int s){
	if(s == 1){
		return one(node);
	}
	if(s == 2){
		return two(node);
	}
	if(s == 3){
		return three(node);
	}
}
int main(){
	srand(clock());
	cin >> s >> t >> p;
	if(s == t){
		cout << 0 << endl;
		return 0;
	}
	for(int i = 0 ; i < 50000 ; ++i){
		int node = s;
		for(int j = 0 ; j < 100 ; ++j){
			int x = 1 + (rand() % 3);
			int add;
			if(x == 1){
				node = one(node);
				add = 1;
			}
			if(x == 2){
				node = two(node);
				add = 2;
			}
			if(x == 3){
				node = three(node);
				add = 3;
			}
			v[i][j] = add;
		}
		arr[i] = make_pair(node , i);
	}
	sort(arr , arr + 50000);
	while(1){
		int node = t;
		for(int i = 0 ; i < 100 ; ++i){
			int x = 1 + (rand() % 3);
			if(x == 1){
				node = two(node);
			}
			if(x == 2){
				node = one(node);
			}
			if(x == 3){
				node = three(node);
			}
			lol[i] = x;
		}
		int idx = lower_bound(arr , arr + 50000 , make_pair(node , 0)) - arr;
		if(idx < 50000 && arr[idx].first == node){
			int who = arr[idx].second;
			printf("200\n");
			int node = s;
			for(int i = 0 ; i < 100 ; ++i){
				printf("%d " , v[who][i]);
				node = get(node , v[who][i]);
			}
			for(int i = 99 ; i >= 0 ; --i){
				printf("%d%c" , lol[i] , " \n"[!i]);
				node = get(node , lol[i]);
			}
			return 0;
		}
	}
}