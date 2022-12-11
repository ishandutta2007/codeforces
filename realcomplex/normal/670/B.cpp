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

int main(){
	fastIO;
	int n,k;
	cin >> n >> k;
	int id[n];
	int l = 1;
	for(int i = 0;i<n;i++){
		cin >> id[i];
		if(k <= l){
			cout << id[k-1] << "\n";
			return 0;
		}
		k -= l++;
	}
	return 0;
}