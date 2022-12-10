//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef complex<LD> point;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

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

const int maxn = 4e4 + 85 - 69;
point p[maxn];
int n;

LD zcross(point p1, point p2){
	return p1.x * p2.y - p1.y * p2.x;
}

LD tria(int id1, int id2, int id3){
	point p1 = p[id1], p2 = p[id2], p3 = p[id3];
	p2 -= p1;
	p3 -= p1;
	return abs(zcross(p2, p3)) / (LD)2;
}

LD leng(point p1){
	return sqrt(p1.x * p1.x + p1.y * p1.y);
}

bool clo(void){
	LD area = 0;
	for(int i = 0; i < n; i++)
		area += zcross(p[i], p[(i + 1) % n]);
	return area < 0;
}

LD solve0(void){
	int ptr = 0;
	LD area = 0,
	   ret = 1e18;
	/*for(int i = 0; i < n; i++)
		cout << p[i] << '\n';
	cout << endl;
		for(int j = 0; j < n; j++)
			cout << p[j] << endl;
		cout << endl;*/
	for(int i = 0; i < n; i++){
		point rot = (p[(i + 1) % n] - p[i]);
		rot /= leng(rot);
		rot = point(0, -1) / rot;
		/*for(int j = 0; j < n; j++)
			cout << p[j] * rot << endl;*/
		while((p[(ptr + 1) % n] * rot).y <= (p[ptr] * rot).y){
			area += tria(i, ptr, (ptr + 1) % n);
			//cerr << "+" << i << ' ' << ptr << ' ' << (ptr+1) % n << " -> " << area<< endl;
			ptr++;
			if(ptr == n) ptr = 0;
		}
		//cout << i << ' ' << ptr << ' ' << area << endl;
		//cout << endl;
		point p1 = p[i]*rot;
		point p2 = p[ptr]*rot;
		p1 -= p2;
		smin(ret, abs(p1.x) * abs(p1.y) / LD(2) - area);
		area -= tria(i, (i + 1) % n, ptr);
	}
	return ret;
}

LD solve1(void){
	reverse(p, p + n);
	int ptr = 0;
	LD area = 0,
	   ret = 1e18;
	for(int i = 0; i < n; i++){
		point rot = (p[(i + 1) % n] - p[i]);
		rot /= leng(rot);
		rot = point(-1, 0) / rot;
		while((p[(ptr + 1) % n] * rot).x <= (p[ptr] * rot).x){
			area += tria(i, ptr, (ptr + 1) % n), ptr++;
			if(ptr == n) ptr = 0;
		}
		//cout << i << ' ' << ptr << ' ' << area << endl;
		point p1 = p[i] * rot;
		point p2 = p[ptr] * rot;
		p1 -= p2;
		smin(ret, abs(p1.x) * abs(p1.y) / LD(2) - area);
		area -= tria(i, (i + 1) % n, ptr);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		LD fi, se;
		cin >> fi >> se;
		p[i] = point(fi, se);
	}
	//cout << "#" << clo() << endl;
	if(clo())
		reverse(p, p + n);
	LD ans = solve0();
	smin(ans, solve1());
	cout << fixed << setprecision(18) << ans << '\n';
	return 0;
}