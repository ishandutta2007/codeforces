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
	int n;
	cin >> n;
	int l[n],r[n];
	int li = 0,ri = 0;
	for(int i = 0;i<n;i++){
		cin >> l[i] >> r[i];
		li += l[i];
		ri += r[i];
	}
	int maxs = ab(li-ri);
	int k = 0;
	for(int i = 0;i<n;i++){
		if(ab((ri-r[i]+l[i]) - (li-l[i]+r[i])) > maxs){
			maxs = ab((ri-r[i]+l[i]) - (li-l[i]+r[i]));
			k = i+1;
		}
	}
	cout << k << "\n";
	return 0;
}