#include <bits/stdc++.h>
#define REP(a,b) for(int a=0; a<(b); ++a)
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define FWDS(a,b,c,d) for(int a=(b); a<(c); a+=d)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define SIZE(a) ((int)(a).size())
#define VAR(x) #x ": " << x << " "
#define popcount __builtin_popcount
#define popcountll __builtin_popcountll
#define gcd __gcd
#define x first
#define y second
#define st first
#define nd second
#define pb push_back

using namespace std;

template<typename T> ostream& operator<<(ostream &out, const vector<T> &v){ out << "{"; for(const T &a : v) out << a << ", "; out << "}"; return out; }
template<typename S, typename T> ostream& operator<<(ostream &out, const pair<S,T> &p){ out << "(" << p.st << ", " << p.nd << ")"; return out; }

typedef long long LL;
typedef pair<int, int> PII;
typedef long double K;
typedef vector<int> VI;

const int dx[] = {0,0,-1,1}; //1,1,-1,1};
const int dy[] = {-1,1,0,0}; //1,-1,1,-1};

int w, h, n;
set<int> W, H;
multiset<int> MW, MH;
char buff[5];

int main(){
	ios_base::sync_with_stdio(0);
	scanf("%d %d %d", &w, &h, &n);
	W.insert(0);
	W.insert(w);
	H.insert(0);
	H.insert(h);
	MW.insert(w);
	MH.insert(h);
	FWD(i,0,n){
		int a, b, c;
		scanf("%s %d", buff, &c);
		if(buff[0] != 'V') swap(W, H), swap(MW, MH);
		W.insert(c);
		a = *(--W.find(c));
		b = *(++W.find(c));
		MW.erase(MW.find(b-a));
		MW.insert(b-c);
		MW.insert(c-a);
		if(buff[0] != 'V') swap(W, H), swap(MW, MH);
		cout << ((LL)(*(--MW.end()))) * *(--MH.end()) << endl;
	}
	return 0;
}