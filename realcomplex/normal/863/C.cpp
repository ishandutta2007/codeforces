#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

int A[3][3];
int B[3][3];

int whoWins(int a1, int b1){
	if(a1 == 0){
		if(b1 == 2)
			return 0;
		else if(b1 == 1)
			return 1;
		else
			return 2;
	}
	if(a1 == 1){
		if(b1 == 0)
			return 0;
		else if(b1 == 2)
			return 1;
		else
			return 2;
	}  
	if(a1 == 2){
		if(b1 == 2)
			return 2;
		if(b1 == 1)
			return 0;
		else
			return 1;
	}
}

int main(){
	fastIO;
	ll k;
	int a, b;
	cin >> k >> a >> b;
	-- a, -- b;
	for(int i = 0; i < 3; i ++ ){
		for(int j = 0; j < 3; j ++ ){
			cin >> A[i][j];
			A[i][j] -- ;
		}
	}
	for(int i = 0;i < 3;i ++ ){
		for(int j = 0;j < 3; j ++ ){
			cin >> B[i][j];
			B[i][j] -- ;
		}
	}
	vector<pii> lis;
	bool ok = true;
	int ax, bx;
	while(ok){
		lis.push_back(mp(a, b));
		for(int i = 0;i < (int)lis.size() - 1; i ++ ){
			if(mp(a, b) == lis[i])
				ok = false;
		}
		ax = A[a][b];
		bx = B[a][b];
		a = ax;
		b = bx;
	}
	int n = lis.size();
	ll s1 = 0, s2 = 0;
	int ww;
	for(int i = 0;i < n-1;i ++ ){
		ww = whoWins(lis[i].fi, lis[i].se);
		if(ww == 0)
			s1 ++ ;
		else if(ww == 1)
			s2 ++ ;
		k -- ;
		if(k == 0){
			cout << s1 << " " << s2 << "\n";
			return 0;
		}
	}
	ll c1 = 0, c2 = 0;
	ll sz;
	for(int i = 0; i < n - 1; i ++ ){
		if(lis[i] == lis[n - 1]){
			sz = 0;
			c1 = 0, c2 = 0;
			for(int j = i; j < n - 1;j ++ ){
				sz ++ ;
				ww = whoWins(lis[j].fi, lis[j].se);
				if(ww == 0)
					c1 ++ ;
				else if(ww == 1)
					c2 ++ ;
			}
			s1 += (k / sz) * c1;
			s2 += (k / sz) * c2;
			k %= sz;
			for(int x = 0; x < k; x ++ ){
				ww = whoWins(lis[i + x].fi, lis[i + x].se);
				if(ww == 0)	
					s1 ++ ;
				else if(ww == 1)
					s2 ++ ;
			}
			cout << s1 << " " << s2 << "\n";
			return 0;
		}
	}
	return 0;
}