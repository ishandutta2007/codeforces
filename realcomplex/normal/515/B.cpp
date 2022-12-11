#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) ((a < 0) ? (-(a)) : (a))

const int A = (int)1e5 + 9;
int x[101];
int y[101];

int main(){
	fastIO;
	int n,m;
	cin >> n >> m;
	int b;
	cin >> b;
	int c;
	while(b--){cin >> c;
		x[c] = 1;
	}
	cin >> b;
	while(b--){cin >> c;
		y[c] = 1;
	}
	for(int i = 0;i<A;i++){
		if(x[i%n] == 1 or y[i%m] == 1){
			x[i%n] = 1;
			y[i%m] = 1;
		}
	}
	for(int i = 0;i<n;i++){
		if(x[i] == 0){
			cout << "No\n";
			return 0;
		}
	}
	for(int i = 0;i<m;i++){
		if(y[i] == 0){
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}