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
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
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

double dis(int x1, int y1, int x2, int y2){
	return hypot(x1-x2, y1-y2);
}

double ar[100001];
int pos[100001][2];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	int ax,ay,bx,by,tx,ty; cin >> ax>> ay >> bx >> by >> tx >> ty;
	int n; cin >> n;
	double res = 0, sum = 0;
	REP(i, n){
		cin >> pos[i][0] >> pos[i][1];
		sum += 2.0 * dis(pos[i][0], pos[i][1], tx, ty);
		ar[i] = dis(pos[i][0], pos[i][1], bx, by) - dis(pos[i][0], pos[i][1], tx, ty);
	}
	
	double mn = 1e16, mn2 = 1e16;
	int m_id = -1;
	REP(i, n){
		if(ar[i] < mn){
			mn2 = mn;
			m_id = i;
			mn = ar[i];
		} else if(ar[i] < mn2){
			mn2 = ar[i];
		}
	}
	
	res = sum + mn;
	
	REP(i, n){
		double v = dis(pos[i][0], pos[i][1], ax, ay) - dis(pos[i][0], pos[i][1], tx, ty);
		res = min(res, sum + v);
		if(m_id == i){
			res = min(res, sum + v + mn2);
		} else {
			res = min(res, sum + v + mn); 
		}
	}
	
	cout << fixed << setprecision(10) << res << endl;
}