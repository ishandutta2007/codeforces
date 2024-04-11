#include "bits/stdc++.h"
using namespace std;
const int N = 3005;
const int inf = 1e7 + 7;
int n , m;
vector < int > v[N];
int a , b;
int dist[N][N];
pair < int , int > pq1[N][5];
pair < int , int > pq2[N][5];
int sz1[N];
int sz2[N];
int ans = -1;
vector < int > answer;
int main(){
	scanf("%d %d" , &n , &m);
	for(int i = 1 ; i <= n ; ++i){
		v[i].clear();
		sz1[i] = 0;
		sz2[i] = 0;
	}
	answer.clear();
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			dist[i][j] = inf;
		}
	}
	for(int i = 1 ; i <= m ; ++i){
		scanf("%d %d" , &a , &b);
		v[a].emplace_back(b);
	}
	for(int i = 1 ; i <= n ; ++i){
		dist[i][i] = 0;
		queue < int > q;
		while(!q.empty()){
			q.pop();
		}
		q.push(i);
		while(!q.empty()){
			int node = q.front();
			q.pop();
			for(int next : v[node]){
				if(dist[i][node] + 1 < dist[i][next]){
					dist[i][next] = dist[i][node] + 1;
					q.push(next);
				}
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			if(j != i && dist[i][j] < inf){
				pq1[i][sz1[i]++] = make_pair(-dist[i][j] , j);
				sort(pq1[i] , pq1[i] + sz1[i]);
				sz1[i] = min(sz1[i] , 4);
				pq2[j][sz2[j]++] = make_pair(-dist[i][j] , i);
				sort(pq2[j] , pq2[j] + sz2[j]);
				sz2[j] = min(sz2[j] , 4);
			}
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 0 ; j < sz1[i] ; ++j){
			pq1[i][j].first *= -1;
		}
		for(int j = 0 ; j < sz2[i] ; ++j){
			pq2[i][j].first *= -1;
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= n ; ++j){
			if(j == i || dist[i][j] >= inf){
				continue;
			}
			for(int x = 0 ; x < sz2[i] ; ++x){
				for(int y = 0 ; y < sz1[j] ; ++y){
					int node1 = pq2[i][x].second;
					int node2 = pq1[j][y].second;
					int dist1 = pq2[i][x].first;
					int dist2 = pq1[j][y].first;
					if(node1 != j && node1 != node2 && node2 != i){
						int val = dist[i][j] + dist1 + dist2;
						if(val > ans){
							ans = val;
							answer.resize(4);
							answer[0] = node1;
							answer[1] = i;
							answer[2] = j;
							answer[3] = node2;
						}
						break;
					}
				}
			}
		}
	}
	for(auto it : answer){
		printf("%d " , it);
	}
}