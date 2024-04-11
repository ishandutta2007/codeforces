#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 9;
int pw[N];
int nxt[N];
int jp[N];

int main(){
	fastIO;
	int n, m;
	cin >> n >> m;
	int bl = int(sqrt(n));
	for(int i = 0; i < n; i ++ ){
		cin >> pw[i];
	
	}
	
	int p;
	int nx;
	int nxp;
	
	for(int i = n-1; i >= 0 ; i -- ){
		nx = i + pw[i];
		p = i / bl;
		nxp = nx / bl;
		
		if(nxp > p || nx >= n){
			jp[i] = 1;
			nxt[i] = nx;
		}
		else{
			jp[i] = jp[nx] + 1;
			nxt[i] = nxt[nx];
		}
		
	}
	
	int ty;
	int a;
	int b;
	int tot, las;
	int il, ir;
	for(int i = 0 ; i < m; i ++ ){
		cin >> ty;
		if(ty == 0){
			cin >> a >> b;
			-- a;
			pw[a] = b;
			for(int j = a; j >= max(0, a - bl) ; j -- ){
				nx = j + pw[j];
				p = j / bl;
				nxp = nx / bl;	
				if(nxp > p || nx >= n){
					jp[j] = 1;
					nxt[j] = nx;
				}
				else{
					jp[j] = jp[nx] + 1;
					nxt[j] = nxt[nx];
				}
			}
		}
		else{
			cin >> a;
			-- a;
			tot = 0;
			las = a;
			while(nxt[a] < n){
				las = a;
				tot += jp[a] ;
				a = nxt[a] ;
			}
			while(a < n){
				las = a;
				tot ++ ;
				a += pw[a];
			}
			cout << las + 1 << " " << tot << "\n";
		}
	}
	return 0;
}