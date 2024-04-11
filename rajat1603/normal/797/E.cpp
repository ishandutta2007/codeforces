#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SQN = 310;
int n;
int arr[N];
int ans[N];
int nxt[N];
int q;
int p , k;
vector < pair < int , int > > v[SQN];
void solve(int k){
	for(int i = n ; i >= 1 ; --i){
		int to = i + arr[i] + k;
		if(to > n){
			nxt[i] = 1;
		}
		else{
			nxt[i] = nxt[to] + 1;
		}
	}
	for(auto it : v[k]){
		ans[it.second] = nxt[it.first];
	}
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , arr + i);
	}
	scanf("%d" , &q);
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d %d" , &p , &k);
		if(k >= SQN){
			int res = 0;
			while(p <= n){
				++res;
				p += arr[p] + k;
			}
			ans[i] = res;
		}
		else{
			v[k].emplace_back(make_pair(p , i));
		}
	}
	for(int i = 0 ; i < SQN ; ++i){
		if(!v[i].empty()){
			solve(i);
		}
	}
	for(int i = 1 ; i <= q ; ++i){
		printf("%d\n" , ans[i]);
	}
}