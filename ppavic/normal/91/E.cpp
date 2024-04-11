#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pt;
typedef pair < ll, int > res;

const int N = 1e5 + 500;
const int OFF = (1 << 17);

inline ll ccw(pt A, pt B, pt C){
	return (ll)A.X * (B.Y - C.Y) + (ll)B.X * (C.Y - A.Y) + (ll)C.X * (A.Y - B.Y);
}

struct hull{	
	vector < pt > cur;
	vector < int > ind;
	void add(pt A, int tko){
		while((int)cur.size() >= 2 && ccw(cur[(int)cur.size() - 2], cur.back(), A) >= 0)
			cur.pop_back(), ind.pop_back();
		cur.PB(A); ind.PB(tko);
	}
	ll get(int i,int t){
		if(i >= (int)cur.size() || i < 0) return -1;
		return (ll)cur[i].X * t + (ll)cur[i].Y;
	}
	res query(int t){
		int lo = 0, hi = (int)cur.size() - 1;
		while(lo < hi){
			int mid = (lo + hi) / 2, mid2 = (lo + hi) / 2 + 1;
			if(get(mid, t) >= get(mid2, t))
				hi = mid;
			else
				lo = mid2;
		}
		return (res){get(lo, t), ind[lo]};
	}
};

hull T[2 * OFF];

void update(int i, pt nw){
	for(int j = OFF + i; j ; j /= 2)
		T[j].add(nw, i);
}

res query(int i, int a, int b, int lo, int hi, int t){
	if(lo <= a && b <= hi)
		return T[i].query(t);
	if(a > hi || b < lo)
		return {-1, 0};
	return max(query(2 * i, a, (a + b) / 2, lo, hi, t), query(2 * i + 1, (a + b) / 2 + 1, b, lo, hi, t));
}

vector < pair < pt, int > > v;
int n, q;

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++){
		int st, del; scanf("%d%d", &st, &del);
		v.PB({{del, st}, i});
	}
	sort(v.begin(), v.end());
	for(pair < pt, int > tmp : v)
		update(tmp.Y, tmp.X);
	for(int koji = 1;q--;koji++){
		int l, r, t; scanf("%d%d%d", &l, &r, &t);
		printf("%d\n", query(1, 0, OFF - 1, l, r, t).Y);
		//printf("%d %lld\n", query(1, 0, OFF - 1, l, r, t).Y, query(1, 0, OFF - 1, l, r, t).X);
	}


}