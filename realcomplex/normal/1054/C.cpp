#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

struct cd{
	int tl;
	int tr;
	int ix;
	bool operator<(cd b){
		return (tl + tr) < (b.tl + b.tr);
	}
};

const int N = 1005;
int s[N];

int main(){
	fastIO;
	int n;
	cin >> n;
	cd ij[n];
	for(int i = 0; i < n; i++ ){
		cin >> ij[i].tl;
		ij[i].ix = i;
	}
	for(int i = 0 ; i< n;i ++ ){
		cin >> ij[i].tr;
	}
	int st = n;
	
	sort(ij, ij + n);
	int ci, cnt1, cnt2;
	int lt, rt;
	for(int z = 0  ; z < n; z ++  ){
		if(z > 0 and (ij[z].tl + ij[z].tr) != (ij[z - 1].tl + ij[z -  1].tr))
			st -- ;
		ci = ij[z].ix;
		cnt1 = 0, cnt2 = 0;
		lt = ij[z].tl;
		rt = ij[z].tr;
		for(int v = ci - 1; v >= 0; v -- )
			cnt1 += (s[v] > st);
		for(int v = ci + 1; v < n; v ++  )
			cnt2 += (s[v] > st);
		if(cnt1 != lt or cnt2 != rt){
			cout << "NO\n";
			return 0;
		}
		s[ci] = st;
	}
	cout << "YES\n";
	for(int i = 0 ; i < n; i ++ )
		cout << s[i] << " ";
	return 0;
}