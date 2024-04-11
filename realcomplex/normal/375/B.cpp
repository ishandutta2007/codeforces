#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


const int N = (int)5005;

int sub[N][N];
int tr[N][N];

int mk[N];

int main(){
	fastIO;
	int n, m;
	cin >>  n >> m;
	char t;
	for(int i = 0; i < n; i ++ ){
		for(int j = 0 ;j < m ; j ++ ){
			cin >> t;
			sub[i][j] = t- '0';
		}
	}
	int answ = 0;
	for(int i = 0 ; i < n; i ++ ){
		for(int j = m - 1; j >= 0 ; j -- ){
			if(sub[i][j] == 1){
				tr[i][j] = 1;
				tr[i][j] = max(tr[i][j], tr[i][j + 1] + 1);
			}
		}
	}
	for(int i = 0; i <m ; i ++ ){
		for(int x = 0 ;x < N; x ++ )
			mk[x] = 0;
		for(int j = 0; j < n; j ++ ){
			mk[tr[j][i]] ++ ;
		}
		for(int j = n; j >= 0 ; j -- ){
			mk[j] += mk[j + 1];
		}
		for(int j = 1; j < N; j ++ ){
			answ = max(answ, j * mk[j]);
		}
	}
	cout << answ << "\n";
	return 0;
}