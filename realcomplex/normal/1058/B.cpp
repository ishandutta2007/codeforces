#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ll,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

bool is[105][105];

int main(){
	fastIO;
	for(int i = 0;i < 105; i ++ )
		for(int j = 0;j < 105;j ++ )
			is[i][j] = true;
	int n, d;
	cin >> n >> d;
	for(int i = 0;i < d; i ++ ){
		for(int j = 0;j < d-i;j ++ ){
			is[i][j] = false;
			is[n - i][n - j] = false;
		}
	}
	int cnt = 0;
	for(int i = d + 1; i <= n; i ++ ){
		for(int j = 0; j <= cnt ; j ++ ){
			is[j][i] = false;
			is[i][j] = false;
		} 
		cnt ++ ;
	}
	int m;
	cin >> m;
	int xi, yi;
	for(int i = 0;i < m;i ++ ){
		cin >> xi >> yi;
		cout << (is[xi][yi] == true ? "yes" : "no") << "\n";
	}
	return 0;
}