#include "bits/stdc++.h"
using namespace std;
const int N = 1005;
const int dx[4] = {0 , 1 , 0 , -1};
const int dy[4] = {1 , 0 , -1 , 0};
int n , m;
long long k;
int arr[N][N];
pair < int , pair < int , int > > arr2[N * N];
int cnt = 0;
int parentx[N][N];
int parenty[N][N];
int sz[N][N];
bool done[N][N];
inline pair < int , int > find(int a , int b){
	if(parentx[a][b] == a && parenty[a][b] == b){
		return make_pair(a , b);
	}
	auto it = find(parentx[a][b] , parenty[a][b]);
	parentx[a][b] = it.first;
	parenty[a][b] = it.second;
	return it;
}
inline void join(int a , int b , int c , int d){
	auto it1 = find(a , b);
	auto it2 = find(c , d);
	if(it1 != it2){
		sz[it1.first][it1.second] += sz[it2.first][it2.second];
		parentx[it2.first][it2.second] = it1.first;
		parenty[it2.first][it2.second] = it1.second;
	}
}
int ans[N][N];
void fill(int x , int y){
	int cnt = k / arr[x][y];
	queue < int > qx;
	queue < int > qy;
	memset(ans , -1 , sizeof(ans));
	qx.push(x);
	qy.push(y);
	ans[x][y] = arr[x][y];
	--cnt;
	while(!qx.empty() && cnt){
		int nx = qx.front();
		int ny = qy.front();
		qx.pop();
		qy.pop();
		for(int k = 0 ; k < 4 ; ++k){
			int nnx = nx + dx[k];
			int nny = ny + dy[k];
			if(!done[nnx][nny]){
				continue;
			}
			if(ans[nnx][nny] != -1){
				continue;
			}
			ans[nnx][nny] = arr[x][y];
			--cnt;
			if(!cnt){
				break;
			}
			qx.push(nnx);
			qy.push(nny);
		}
	}
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			if(ans[i][j] == -1){
				ans[i][j] = 0;
			}
			printf("%d " , ans[i][j]);
		}
		printf("\n");
	}
}
int main(){
	scanf("%d %d %lld" , &n , &m , &k);
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			scanf("%d" , &arr[i][j]);
			arr2[++cnt] = make_pair(arr[i][j] , make_pair(i , j));
		}
	}
	sort(arr2 + 1 , arr2 + 1 + cnt);
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			parentx[i][j] = i;
			parenty[i][j] = j;
			sz[i][j] = 1;
		}
	}
	for(int i = cnt ; i >= 1 ; --i){
		int x = arr2[i].second.first;
		int y = arr2[i].second.second;
		for(int k = 0 ; k < 4 ; ++k){
			int nx = x + dx[k];
			int ny = y + dy[k];
			if(done[nx][ny]){
				join(x , y , nx , ny);
			}
		}
		if((k % arr[x][y]) == 0){
			if(sz[find(x , y).first][find(x , y).second] >= k / arr[x][y]){
				printf("YES\n");
				fill(x , y);
				return 0;	
			}
		}
		done[x][y] = 1;
	}
	printf("NO\n");
}