/*********************************************************************\
   |--\        ---       /\        |-----------| -----   /-------|    |
   |   \        |       /  \       |               |    /             |
   |    \       |      /    \      |               |   |              |
   |     \      |     /      \     |               |   |----|         |
   |      \     |    / ------ \    |-------|       |        |-----|   |
   |       \    |   /          \   |               |              |   |
   |        \   |  /            \  |               |              /   |
  ---        -------            ------           ----- |---------/    |
                                                                      |
    codeforces = nfssdq  ||  topcoder = nafis007                      |
    mail = nafis_sadique@yahoo.com || nfssdq@gmail.com                |
    IIT,Jahangirnagar University(41)                                  |
                                                                      |
**********************************************************************/

#include <bits/stdc++.h>

using namespace std;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         2.0*acos(0.0)
#define linf       (1<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

const int N = int(1e5) + 10;
const LL INF = 1LL << 60;

struct Point {
    LL x,y;
} point[N];
int n;
int tmpt[N];

bool cmpxy(const Point& a, const Point& b) {
	if (a.x != b.x)
		return a.x < b.x;
	return a.y < b.y;
}

bool cmpy(const int& a, const int& b) {
	return point[a].y < point[b].y;
}

LL dis2(int i, int j) {
	return (point[i].x - point[j].x) * (point[i].x - point[j].x)
			+ (point[i].y - point[j].y) * (point[i].y - point[j].y);
}

LL sqr(LL x) {
	return x * x;
}

LL Closest_Pair(int left, int right) {
	LL d = INF;
	if (left == right)
		return d;
	if (left + 1 == right)
		return dis2(left, right);
	int mid = (left + right) >> 1;
	LL d1 = Closest_Pair(left, mid);
	LL d2 = Closest_Pair(mid + 1, right);
	d = min(d1, d2);
	int i, j, k = 0;
	for (i = left; i <= right; i++) {
		if (sqr(point[mid].x - point[i].x) <= d)
			tmpt[k++] = i;
	}
	sort(tmpt, tmpt + k, cmpy);
	for (i = 0; i < k; i++) {
		for (j = i + 1; j < k && sqr(point[tmpt[j]].y - point[tmpt[i]].y) < d;
				j++) {
			LL d3 = dis2(tmpt[i], tmpt[j]);
			if (d > d3)
				d = d3;
		}
	}
	return d;
}

LL sum[100001];
main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    LL a = 0,b,c,d,e = 0,f = 0,g,h = 0,x,y,z;
    cin >> a;
    FOR(i, 1, a + 1){
        cin >> b;
        sum[i] = sum[i - 1] + b;
        point[i - 1].x = i;
        point[i - 1].y = sum[i];
    }


    cout << Closest_Pair(0, a - 1) << endl;
}
/*
4
200 100 -200 100
200 300 100 200
*/