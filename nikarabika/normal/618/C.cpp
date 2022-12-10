//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef complex<LL> Point;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()
#define x real()
#define y imag()

const int maxn = 1000 * 100;
LL dis[maxn];
Point P[maxn];
int n;

LL cross(Point AB, Point AC){
	return AB.x * AC.y - AB.y * AC.x;
}

LL dist(Point d){
	return d.x * d.x + d.y * d.y;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		LL xx, yy;
		cin >> xx >> yy;
		P[i] = Point(xx, yy);
	}
	for(int i = 1; i < n; i++)
		dis[i] = dist(P[0] - P[i]);
	dis[0] = 1000LL * 1000 * 1000;
	dis[0] *= dis[0];
	dis[0] *= 8LL;
	int id = min_element(dis + 1, dis + n) - dis;
	dis[id] = dis[0];
	int id2 = 0;
	for(int i = 0; i < n; i++)
		if(dis[i] != dis[0])
			if(cross(P[id] - P[0], P[i] - P[0]) != 0LL and dis[i] < dis[id2])
				id2 = i;
	cout << 1 << ' ' << id + 1 << ' ' << id2 + 1 << endl;
	return 0;
}