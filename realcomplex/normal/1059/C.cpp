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

const int N = (int)1e6 + 9;
bool vis[N];

int main(){
	fastIO;
	int n;
	cin >> n;
	if(n == 3){
		cout << "1 1 3\n";
		return 0;
	}
	
	int p;
	int rem = 0;
	for(int log = 1; log < 25; log ++ ){
		p = 1 << log;
		for(int j = 1; j <= n;j ++ ){
			if(vis[j] == true)
				continue;
			if(j % p != 0){
				rem ++ ;
				if(rem == n){
					int r = (1 << (log - 1));
					for(int z = 1; z <= n; z ++ ){
						if(r * z > n)
							break;
						if(r * (z + 1) > n){
							r = r * z;
						}
					}
					if(log > 1){
						int g = (1 << (log - 2));
						for(int z = 1; z <= n; z ++ ){
							if(g * z > n)
								break;
							if(g * (z + 1) > n)
								g = g * z;
						}
						r = max(r, g);
					}
					cout << r << " ";
				}
				else{
					cout << (1 << (log - 1)) << " ";
				}
				vis[j] = true;
			}
		}
	}
	return 0;
}