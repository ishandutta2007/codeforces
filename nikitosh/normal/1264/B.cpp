#include <bits/stdc++.h> 
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif
 
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using uint = unsigned int;
using vi = vector<int>;
using pii = pair<int, int>;
 
#define FNAME ""

const int N = 10, M = 2e5 + 5;

int a[M], cnt[N], curCnt[N], check[N];
  
void handle(int& ind, int dlt, bool& ok) {
	if (a[ind - dlt] == 3) {
		if (curCnt[2] == 0) {
			ok = 0;
			return;
		}
		curCnt[2]--;
		a[ind] = 2;
		ind += dlt;
		return;
	}		
	if (a[ind - dlt] == 0) {
		if (curCnt[1] == 0) {
			ok = 0;
			return;
		}
		curCnt[1]--;
		a[ind] = 1;
		ind += dlt;
		return;
	}		
	if (a[ind - dlt] == 2) {
		int nxt = 3;
		if (curCnt[3] == 0)
			nxt = 1;
		if (curCnt[nxt] == 0) {
			ok = 0;
			return;
		}
		curCnt[nxt]--;
		a[ind] = nxt;
		ind += dlt;
		return;
	}		
	if (a[ind - dlt] == 1) {
		int nxt = 0;
		if (curCnt[0] == 0)
			nxt = 2;
		if (curCnt[nxt] == 0) {
			ok = 0;
			return;
		}
		curCnt[nxt]--;
		a[ind] = nxt;
		ind += dlt;
		return;
	}		
}  

/*
void handle2(int& ind, int dlt, bool& ok) {
	if (a[ind - 1] == 1) {
		if (curCnt[2] == 0) {
			ok = 0;
			return;
		}
		curCnt[2]--;
		a[ind] = 2;
		ind += dlt;
		return;
	}		
	if (a[ind - 1] == 2) {
		if (curCnt[1] == 0) {
			ok = 0;
			return;
		}
		curCnt[1]--;
		a[ind] = 1;
		ind += dlt;
		return;
	}		
} 
*/
  
int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int sum = 0;
	forn (i, 4)
		cin >> cnt[i], sum += cnt[i];
	if (sum == 1) {
		cout << "YES\n";
		forn (i, 4)
			if (cnt[i])
				cout << i;
		return 0;
	}
	forn (i, 4)
		forn (j, 4) {
			forn (g, 4)
				curCnt[g] = cnt[g];
			curCnt[i]--;
			curCnt[j]--;
			bool ok = 1;
			forn (g, 4)
				if (curCnt[g] < 0) {
					ok = 0;
					break;
				}
			if (!ok)
				continue;
			a[0] = i, a[sum - 1] = j;
			int it1 = 1;
			int it2 = sum - 2;
			while (it1 <= it2) {
				handle(it1, 1, ok);
				if (!ok)
					break;
			}
			if (!ok)
				continue;
			forn (g, 4)
				check[g] = 0;
			forn (g, sum)
				check[a[g]]++;
			forn (g, 4)
				if (check[g] != cnt[g])
					ok = 0;
			forn (g, sum - 1)
				if (abs(a[g] - a[g + 1]) != 1)
					ok = 0;
			if (ok) {
				cout << "YES\n";
				forn (g, sum)
					cout << a[g] << " ";
				return 0;
			} 
		}
	cout << "NO\n";	
	return 0;
}