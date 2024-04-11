#include "bits/stdc++.h"
using namespace std;
struct point{
	long long x , y;
	point(long long _x = 0 , long long _y = 0){
		x = _x;
		y = _y;
	}
	point operator + (const point &other) const {
		return point(x + other.x , y + other.y);
	}
	point operator - (const point &other) const {
		return point(x - other.x , y - other.y);
	}
	void read(){
		scanf("%lld %lld" , &x , &y);
	}
};
long long dot(point a , point b){
	return a.x * b.x + a.y * b.y;
}
inline long long cross(point a , point b){
	return a.x * b.y - a.y * b.x;
}
inline int orient(point a , point b , point c){//orientation of point c with respect to line from a -> b
	long long val = cross(b - a , c - a);
	if(val > 0){
		return 1;//c comes anticlockwise on line from a -> b
	}
	if(val < 0){
		return -1;//c comes clockwise on line from a -> b
	}
	return 0;//c is collinear with line from a -> b
}
long long dist(point a , point b){
	return dot(a - b , a - b);
}
const int N = 205;
const int K = 55;
int n , k;
point arr[N];
point bottom;
int tot[N][N];
inline long long area(int a , int b , int c){
	return abs(cross(arr[b] - arr[a] , arr[c] - arr[a]));
}
inline long long alsoarea(point a , point b , point c){
	return abs(cross(b - a , c - a));
}
inline bool inside(point p1 , point p2 , point p3 , point q){
	return alsoarea(p1 , p2 , p3) == alsoarea(p1 , p2 , q) + alsoarea(p2 , p3 , q) + alsoarea(p3 , p1 , q);
}
inline int get(int a , int b , int c){
	int res = 0;
	res += (tot[a][b] - inside(bottom , arr[a] , arr[b] , arr[c])) * orient(bottom , arr[a] , arr[b]);
	res += (tot[b][c] - inside(bottom , arr[b] , arr[c] , arr[a])) * orient(bottom , arr[b] , arr[c]);
	res += (tot[c][a] - inside(bottom , arr[c] , arr[a] , arr[b])) * orient(bottom , arr[c] , arr[a]);
	return res;
}
long long dp[2][N][N];
vector < int > v;
int pivot;
bool cmp(int a , int b){
	return orient(arr[pivot] , arr[a] , arr[b]) == -1;
}
bool cmp2(int a , int b){
	return orient(arr[v[pivot]] , arr[v[a]] , arr[v[b]]) == -1;
}
int nxt[N][N];
int prv[N][N];
int how[N][N];
long long solve(int idx){
	v.clear();
	v.emplace_back(idx);
	for(int i = 1 ; i <= n ; ++i){
		if(arr[i].y > arr[idx].y || (arr[i].y == arr[idx].y && arr[i].x > arr[idx].x)){
			v.emplace_back(i);
		}
	}
	if(v.size() < k){
		return 0;
	}
	pivot = v[0];
	sort(v.begin() + 1 , v.end() , cmp);
	int m = v.size();
	for(int i = 1 ; i < m ; ++i){
		nxt[i][0] = 0;
		for(int j = i + 1 ; j < m ; ++j){
			if(!get(v[0] , v[i] , v[j])){
				nxt[i][++nxt[i][0]] = j;
			}
		}
		prv[i][0] = 0;
		for(int j = 0 ; j < i ; ++j){
			prv[i][++prv[i][0]] = j;
		}
		pivot = i;
		sort(nxt[i] + 1 , nxt[i] + 1 + nxt[i][0] , cmp2);
		sort(prv[i] + 1 , prv[i] + 1 + prv[i][0] , cmp2);
		int ptr = nxt[i][0];
		for(int j = prv[i][0] ; j >= 1 ; --j){
			while(ptr >= 1 && orient(arr[v[prv[i][j]]] , arr[v[i]] , arr[v[nxt[i][ptr]]]) == -1){
				--ptr;
			}
			how[i][j] = ptr;
		}
	}
	for(int siz = k ; siz > 1 ; --siz){
		for(int last2 = 1 ; last2 < m ; ++last2){
			int ptr = nxt[last2][0];
			long long bst = -1LL << 50;
			for(int j = prv[last2][0] ; j >= 1 ; --j){
				if(siz == k){
					if(orient(arr[v[prv[last2][j]]] , arr[v[last2]] , arr[v[0]]) != -1){
						dp[siz & 1][prv[last2][j]][last2] = -1LL << 50;
					}
					else{
						dp[siz & 1][prv[last2][j]][last2] = 0;
					}
					continue;
				}
				while(ptr > how[last2][j]){
					bst = max(bst , dp[!(siz & 1)][last2][nxt[last2][ptr]] + area(v[0] , v[last2] , v[nxt[last2][ptr]]));
					--ptr;
				}
				dp[siz & 1][prv[last2][j]][last2] = bst;
			}
		}
	}
	long long res = 0;
	for(int i = 1 ; i < m ; ++i){
		res = max(res , dp[0][0][i]);
	}
	return res;
}
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		arr[i].read();
	}
	bottom = point(-1 , -1);
	for(int i = 1 ; i <= n ; ++i){
		tot[i][i] = 0;
		for(int j = i + 1 ; j <= n ; ++j){
			int res = 0;
			for(int k = 1 ; k <= n ; ++k){
				if(i == k || j == k){
					continue;
				}
				res += inside(bottom , arr[i] , arr[j] , arr[k]);
			}
			tot[i][j] = tot[j][i] = res;
		}
	}
	long long ans = 0;
	for(int i = 1 ; i <= n ; ++i){
		ans = max(ans , solve(i));
	}
	printf("%.2lf\n" , ans / 2.0);
}