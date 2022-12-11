#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
	fastIO;
	int n;
	cin >> n;
	int a[n];
	for(int i = 0 ; i < n;i ++ )
		cin >> a[i];
	int rot = 0;
	for(int mask = 0; mask < (1 << n) ; mask ++ ){
		rot = 0;
		for(int j = 0 ; j < n; j ++ ){
			if(mask & (1 << j)){
				rot = (rot + a[j]) % 360;
			}
			else{
				rot = (rot - a[j] + 360) % 360;
			}
		}
		if(rot == 0){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}