#include <stdio.h>
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2010;

vector <pair<int,int> > G[N]; 
int n , m;

struct Node{int s , v;};
bool operator < (Node A , Node B) {return A.v > B.v;}

priority_queue <Node> q; int tmp[N] , ct;
void DIS(int s , int *arr , int &siz)
{
	memset(arr , 0x3f , sizeof(int) * N);
	arr[s] = 0 , q.push((Node){s , 0});
	while(!q.empty()) {
		Node t = q.top(); q.pop();
		if(t.v > arr[t.s]) continue;
		for(auto e : G[t.s])
			if(arr[e.first] > arr[t.s] + e.second) {
				arr[e.first] = arr[t.s] + e.second;
				q.push((Node){e.first , arr[e.first]});
			}
	}
	ct = 0;
	for(int i = 1; i <= n; i++)
		tmp[++ct] = arr[i];
	sort(tmp + 1 , tmp + ct + 1) , siz = unique(tmp + 1 , tmp + ct + 1) - tmp - 1; 
	for(int i = 1; i <= n; i++)
		arr[i] = lower_bound(tmp + 1 , tmp + siz + 1 , arr[i]) - tmp;
}

int d1[N] , d2[N] , s1 , s2;
int a[N][N] , b[N] , c[N][N];
int f[2][N][N] , wh[2][N][N] , ans;

signed main() {
	scanf("%lld%lld" , &n , &m);
	int s , t; scanf("%lld%lld" , &s , &t);
	for(int i = 1; i <= n; i++) scanf("%lld" , &b[i]);
	for(int i = 1 , u , v , w; i <= m; i++) {
		scanf("%lld%lld%lld" , &u , &v , &w);
		G[u].push_back(make_pair(v , w));
		G[v].push_back(make_pair(u , w));
	}
	DIS(s , d1 , s1) , DIS(t , d2 , s2);
	for(int i = 1; i <= n; i++)
		a[d1[i]][d2[i]] += b[i] , c[d1[i]][d2[i]]++;
	for(int i = s1; i >= 1; i--)
		for(int j = s2; j >= 1; j--) {
			a[i][j] += a[i + 1][j] + a[i][j + 1] - a[i + 1][j + 1];
			wh[0][i][j] = min(i == s1 ? s1 : wh[0][i + 1][j] , j == s2 ? s1 : wh[0][i][j + 1]);
			wh[1][i][j] = min(i == s1 ? s2 : wh[1][i + 1][j] , j == s2 ? s2 : wh[1][i][j + 1]);
			if(c[i][j]) wh[0][i][j] = i , wh[1][i][j] = j;
			f[0][i][j] = a[i][j] - f[1][wh[0][i][j] + 1][j];
			f[1][i][j] = a[i][j] - f[0][i][wh[1][i][j] + 1];
			if(i == 1 && j == 1) ans = f[0][i][j];
			f[0][i][j] = min(f[0][i][j] , f[0][i][j + 1]);
			f[1][i][j] = min(f[1][i][j] , f[1][i + 1][j]);
		}
	printf("%s\n" , (ans * 2 == a[1][1] ? "Flowers" : (ans * 2 < a[1][1] ? "Cry" : "Break a heart")));
	return 0;
}