#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

const int N = 1005;

char fl[N][N];
bool ok[N][N];

int main(){
	fastIO;
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i ++ ){
		for(int j = 0; j < m ; j ++ ){
			cin >> fl[i][j];
			if(fl[i][j] == '.')
				ok[i][j] = true;
		}
	}
	bool p;
	for(int i = 0;i < n-2; i ++ ){
		for(int j = 0;j < m-2; j ++ ){
			p = true;
			for(int x = 0;x < 3; x ++ ){
				for(int z = 0; z < 3; z ++ ){
					if(x == 1 and z == 1)
						continue;
					if(fl[i + x][j + z] == '.')
						p = false;
				}
			}
			if(p){
				for(int x = 0;x < 3; x ++ ){
					for(int z = 0; z < 3; z ++ ){
						if(x == 1 and z == 1)
							continue;
						ok[i + x][j + z] = true;
					}
				}
			}
		}
	}
	for(int i = 0; i < n;i ++ ){
		for(int j = 0;j < m ; j ++ ){
			if(!ok[i][j]){
				cout << "NO\n";
				exit(0);
			}
		}
	}
	cout << "YES\n";
	return 0;
}