#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
const int LN = 20;
int q;
int n;
int last;
int val[N];
int parent[N][LN];
int dpm[N][LN];
int nxt[N][LN];
long long sum[N][LN];
void add(int node , int w){
	++n;
	val[n] = w;
	parent[n][0] = node;
	dpm[n][0] = w;
	for(int i = 1 ; i < LN ; ++i){
		dpm[n][i] = max(dpm[n][i - 1] , dpm[parent[n][i - 1]][i - 1]);
		parent[n][i] = parent[parent[n][i - 1]][i - 1];
	}
	nxt[n][0] = n;
	sum[n][0] = w;
	if(dpm[parent[n][0]][LN - 1] < w){
		nxt[n][1] = 0;
		sum[n][1] = 0;
	}
	else{
		if(val[parent[n][0]] >= w){
			nxt[n][1] = parent[n][0];
			sum[n][1] = w + val[parent[n][0]];
		}
		else{
			int tmp = parent[n][0];
			for(int i = LN - 1 ; i >= 0 ; --i){
				if(dpm[tmp][i] < w){
					tmp = parent[tmp][i]; 
				}
			}
			if(val[tmp] < w){
				tmp = parent[tmp][0];
			}
			nxt[n][1] = tmp;
			sum[n][1] = val[nxt[n][1]] + w;
		}
	}
	for(int i = 2 ; i < LN ; ++i){
		nxt[n][i] = nxt[nxt[nxt[n][i - 1]][1]][i - 1];
		sum[n][i] = sum[n][i - 1] + sum[nxt[nxt[n][i - 1]][1]][i - 1];
	}
	/*cout << n << endl;
	for(int i = 0 ; i <= 3 ; ++i){
		cout << nxt[n][i] << " ";
	}
	cout << endl;*/
}
void query(int node , long long x){
	int tot = 0;
	for(int i = LN - 1 ; i >= 0 && node ; --i){
		//cout << node << " " << i << " " << nxt[node][i] << endl;
		if(nxt[node][i] && sum[node][i] <= x){
			tot += 1 << i;
			x -= sum[node][i];
			node = nxt[nxt[node][i]][1];
			++i;
		}
	}
	last = tot;
}
int main(){
	scanf("%d" , &q);
	n = 1;
	last = 0;
	val[1] = 0;
	nxt[1][0] = 1;
	for(int i = 1 ; i <= q ; ++i){
		int type;
		long long p , q;
		scanf("%d %lld %lld" , &type , &p , &q);
		p ^= last;
		q ^= last;
		if(type == 1){
			add(p , q);
		}
		else{
			query(p , q);
			printf("%d\n" , last);
		}
	}
}