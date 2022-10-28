#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SQN = 340;
int n , m , q;
int a , b;
vector < int > v[N];
int nam[N];
int dia[N];
int cur;
int siz[N];
vector < int > comp[N];
void dfs(int node , int parent){
	nam[node] = cur;
	++siz[cur];
	comp[cur].emplace_back(node);
	for(int next : v[node]){
		if(next != parent){
			dfs(next , node);
		}
	}
}

int dist1[N];
int dist2[N];
int who , val;
int far[N];
void dfs2(int node , int parent , int dist[] , int level){
	if(level > val){
		val = level;
		who = node;
	}
	dist[node] = level;
	for(int next : v[node]){
		if(next != parent){
			dfs2(next , node , dist , level + 1);
		}
	}
}
vector < int > heavy;
int rnk[N];
long long ans[SQN][SQN];
vector < pair < int , long long > > fars[N];
long long brute(int a , int b){
	if(siz[a] > siz[b]){
		swap(a , b);
	}
	int mx = max(dia[a] , dia[b]);
	long long tot = 1LL * siz[a] * siz[b];
	long long res = 0;
	long long cnt = 0;
	int ptr = 0;
	for(int i = int(fars[a].size()) - 1 ; i >= 0 ; --i){
		int d1 = fars[a][i].first;
		if((fars[b].size() - ptr) <= i + i){
			while(ptr < fars[b].size() && d1 + 1 + fars[b][ptr].first <= mx){
				++ptr;
			}
		}
		else{
			ptr = lower_bound(fars[b].begin() + ptr , fars[b].end() , make_pair(mx - d1 , -1LL)) - fars[b].begin();
		}
		int tmp = int(fars[b].size()) - ptr;
		if(tmp){
			cnt += tmp;
			res += fars[b][ptr].second;
			res += 1LL * (d1 + 1LL) * tmp;
		}
		else{
			break;
		}
	}
	res += 1LL * mx * (tot - cnt);
	return res;
}
void precalc(){
	for(int i = 1 ; i <= n ; ++i){
		fars[nam[i]].emplace_back(make_pair(far[i] , far[i]));
	}
	for(int i = 1 ; i <= cur ; ++i){
		sort(fars[i].begin() , fars[i].end());
		for(int j = int(fars[i].size()) - 2 ; j >= 0 ; --j){
			fars[i][j].second += fars[i][j + 1].second;
		}
	}
	for(int i = 0 ; i < heavy.size() ; ++i){
		for(int j = 0 ; j < i ; ++j){
			ans[i][j] = ans[j][i] = brute(heavy[i] , heavy[j]);
		}
	}
}
int main(){
	scanf("%d %d %d" , &n , &m , &q);
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
		v[b].emplace_back(a);
	}
	for(int i = 1 ; i <= n ; ++i){
		if(!nam[i]){
			++cur;
			dfs(i , 0);
			who = i;
			val = 0;
			dfs2(i , 0 , dist1 , 0);
			val = 0;
			dfs2(who , 0 , dist1 , 0);
			val = 0;
			dfs2(who , 0 , dist2 , 0);
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		far[i] = max(far[i] , max(dist1[i] , dist2[i]));
		dia[nam[i]] = max(dia[nam[i]] , far[i]);
	}
	for(int i = 1 ; i <= cur ; ++i){
		if(siz[i] >= SQN){
			rnk[i] = heavy.size();
			heavy.emplace_back(i);
		}
	}
	precalc();
	while(q--){
		scanf("%d %d" , &a , &b);
		if(nam[a] == nam[b]){
			printf("-1\n");
		}
		else{
			a = nam[a];
			b = nam[b];
			if(siz[a] > siz[b]){
				swap(a , b);
			}
			if(siz[a] >= SQN){
				printf("%.9lf\n" , (1.0 * ans[rnk[a]][rnk[b]]) / (1.0 * (1LL * siz[a] * siz[b])));
			}
			else{
				printf("%.9lf\n" , (1.0 * brute(a , b)) / (1.0 * (1LL * siz[a] * siz[b])));
			}
		}
	}
}