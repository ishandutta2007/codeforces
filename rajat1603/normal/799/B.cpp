#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int p[N];
int a[N];
int b[N];
int q;
int c;
priority_queue < pair < int , int > > pq[4];
bool done[N];
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , p + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , a + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d" , b + i);
	}
	for(int i = 1 ; i <= n ; ++i){
		pq[a[i]].push(make_pair(-p[i] , i));
	}
	for(int i = 1 ; i <= n ; ++i){
		pq[b[i]].push(make_pair(-p[i] , i));
	}
	scanf("%d" , &q);
	for(int i = 1 ; i <= q ; ++i){
		scanf("%d" , &c);
		int who = -1;
		while(!pq[c].empty()){
			auto it = pq[c].top();
			pq[c].pop();
			if(!done[it.second]){
				who = it.second;
				break;
			}
		}
		if(who != -1){
			done[who] = 1;
			who = p[who];
		}
		printf("%d%c" , who , " \n"[i == q]);
	}
}