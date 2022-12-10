//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef long double LD;
typedef complex<LD> Point;
typedef pair<Point, Point> ppp;

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

const int maxn = 300 * 1000 + 10;
LD Pi;
Point segsum[maxn * 4], P[maxn];
ppp segmul[maxn * 4];
bool laz[maxn * 4];
LD sum[maxn];
int qty[maxn], qfi[maxn], qse[maxn];
int n, m;

void propagate(int);

ppp multip(ppp &A, ppp &B){
	ppp ret;
	ret.L = Point(A.L.x * B.L.x + A.L.y * B.R.x, A.L.x * B.L.y + A.L.y * B.R.y);
	ret.R = Point(A.R.x * B.L.x + A.R.y * B.R.x, A.R.x * B.L.y + A.R.y * B.R.y);
	return ret;
}

Point multip(Point &A, ppp &B){
	Point ret(A.x * B.L.x + A.y * B.R.x, A.x * B.L.y + A.y * B.R.y);
	return ret;
}

void build(int l = 0, int r = n, int id = 1){
	segsum[id] = Point(0, 0);
	segmul[id] = MP(Point(1, 0), Point(0, 1));
	if(r - l == 1){
		P[l] = Point(LD(1) * l, 0);
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, id * 2 + 0);
	build(mid, r, id * 2 + 1);
	return;
}

Point get(int idx, int l = 0, int r = n, int id = 1){
	if(r - l == 1){
		Point ret = P[l];
		ret = multip(ret, segmul[id]);
		ret = ret + segsum[id];
		return ret;
	}
	int mid = (l + r) >> 1;
	Point ret;
	if(idx < mid)
		ret = get(idx, l, mid, id * 2 + 0);
	else
		ret = get(idx, mid, r, id * 2 + 1);
	ret = multip(ret, segmul[id]);
	ret = ret + segsum[id];
	return ret;
}

void add(Point val, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		segsum[id] += val;
		laz[id] = true;
		return;
	}
	if(laz[id]) propagate(id);
	int mid = (l + r) >> 1;
	add(val, st, en, l, mid, id * 2 + 0);
	add(val, st, en, mid, r, id * 2 + 1);
	return;
}

void mul(ppp val, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		segsum[id] = multip(segsum[id], val);
		segmul[id] = multip(segmul[id], val);
		laz[id] = false;
		return;
	}
	if(laz[id]) propagate(id);
	int mid = (l + r) >> 1;
	mul(val, st, en, l, mid, id * 2 + 0);
	mul(val, st, en, mid, r, id * 2 + 1);
	return;
}

void propagate(int id){
	mul(segmul[id], 0, 1, 0, 1, id * 2 + 0);
	mul(segmul[id], 0, 1, 0, 1, id * 2 + 1);
	add(segsum[id], 0, 1, 0, 1, id * 2 + 0);
	add(segsum[id], 0, 1, 0, 1, id * 2 + 1);
	segmul[id] = MP(Point(1, 0), Point(0, 1));
	segsum[id] = Point(0, 0);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cout.precision(10);
	Pi = atan(1) * LD(4);
	scanf("%d%d", &n, &m);
	n++;
	build();
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", qty + i, qfi + i, qse + i);
		if(qty[i] == 1){
			Point A = get(qfi[i] - 1);
			Point B = get(qfi[i]);
			Point AB = B - A;
			LD dis = sqrt(AB.x * AB.x + AB.y * AB.y);
			LD vec = qse[i];
			Point vec2 = (vec / dis) * AB;
			add(vec2, qfi[i], n);
		}
		else{
			qfi[i]--;
			Point A = get(qfi[i]);
			LD deg = LD(qse[i]) / LD(180) * Pi;
			LD sss = sin(deg), ccc = cos(deg);
			add(-A, qfi[i], n);
			mul(MP(Point(ccc, -sss), Point(sss, ccc)), qfi[i], n);
			add(+A, qfi[i], n);
		}
		Point A = get(n - 1);
		cout << fixed << A.x << ' ' << A.y << '\n';
	}
	return 0;
}