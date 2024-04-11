#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int K = 12;
int n , k , q;
int arr[K][N];
int who[N][K];
int nrr[N * K][K];
int siz;
vector < int > lol[N];
int when[1 << K];
int parent[N * K];
bitset < 1 << K > bit[N + K];
int idx[N * K];
int main(){
	scanf("%d %d %d" , &n , &k , &q);
	for(int i = 0 ; i < k ; ++i){
		for(int j = 0 ; j < n ; ++j){
			scanf("%d" , &arr[i][j]);
		}
	}
	for(int i = 0 ; i < n ; ++i){
		vector < int > tmp;
		for(int j = 0 ; j < k ; ++j){
			tmp.emplace_back(arr[j][i]);
		}
		sort(tmp.begin() , tmp.end());
		for(int j = 0 ; j < k ; ++j){
			for(int x = 0 ; x < k ; ++x){
				nrr[siz][x] = (arr[x][i] > tmp[j]);
			}
			who[i][j] = siz;
			++siz;
		}
		lol[i].swap(tmp);
	}
	memset(when , -1 , sizeof(when));
	for(int i = 0 ; i < siz ; ++i){
		int mask = 0;
		for(int j = 0 ; j < k ; ++j){
			if(nrr[i][j]){
				mask |= 1 << j;
			}
		}
		parent[i] = when[mask];
		if(when[mask] == -1){
			when[mask] = i;
		}
	}
	int cnt = 0;
	for(int i = 0 ; i < siz ; ++i){
		if(parent[i] == -1){
			idx[i] = cnt++;
		}
	}
	for(int i = 0 ; i < siz ; ++i){
		if(parent[i] != -1){
			continue;
		}
		parent[i] = i;
		for(int j = 0 ; j < k ; ++j){
			if(nrr[i][j]){
				bit[j].set(idx[i]);
			}
		}
	}
	int who = k;
	while(q--){
		int type , x , y;
		scanf("%d %d %d" , &type , &x , &y);
		if(type == 1){
			bit[who] = bit[x - 1] | bit[y - 1];
			++who;
		}
		else if(type == 2){
			bit[who] = bit[x - 1] & bit[y - 1];
			++who;
		}
		else{
			int ans = lol[y - 1][k - 1];;
			for(int j = 0 ; j < k ; ++j){
				int idx = ::idx[parent[::who[y - 1][j]]];
				if(!bit[x - 1].test(idx)){
					ans = min(ans , lol[y - 1][j]);
				}
			}
			printf("%d\n" , ans);
		}
	}
}