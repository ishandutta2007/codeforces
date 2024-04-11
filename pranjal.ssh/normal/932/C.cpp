#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}

vector<int> A;
void f(int l, int r) {
	A.resize(r-l+1);
	FOR (i, 0, sz(A)-1) A[i]=l+i;
	FOR (i, 1, sz(A)-1) printf("%d ", A[i]);
	printf("%d ", A[0]);
}

int main()
{
	int N, A, B;

	scanf("%d %d %d", &N, &A, &B);
	
	::A.reserve(N);

	FOR (a, 0, N) {
		ll bB = N - a*1LL*A;
		if (bB == 0) {
			int off = 1;
			FOR (it, 0, a-1) {
				f(off, off+A-1);
				off += A;
			}
			
			return 0;
		} else if (bB > 0 and bB % B == 0) {
			ll b = bB / B;
			int off = 1;
			
			FOR (it, 0, a-1) {
				f(off, off+A-1);
				off += A;
			}
			FOR (it, 0, b-1) {
				f(off, off+B-1);
				off += B;
			}
			
			return 0;
		}
	}
	cout << "-1\n";

	return 0;
}