#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define int ll

signed main(){
	fastIO;
	int n;
	cin >> n;
	int a[n];
	for(int i = 0 ; i < n ; i ++ )
		cin >> a[i];
	int answ = 0;
	int li = 0;
	int cl, cr;
	int dis;
	int value;
	int dv;
	int should;
	while(li < n){
		answ ++ ;
		cl = li;
		while(cl < n && a[cl] == -1){
			cl ++ ;
		}
		if(cl == n)
			break;
		cr = cl + 1;
		while(cr < n && a[cr] == -1){
			cr ++ ;
		}
		if(cr == n)
			break;
		dis = cr - cl;
		value = a[cr] - a[cl];
		if(value % dis != 0){
			li = cr;
		}
		else{
			value /= dis;
			dv = li;
			while(dv < n){
				should = a[cl] + (dv - cl) * value;
				if(should <= 0)
					break;
				if(a[dv] != -1 && a[dv] != should) 
					break;
				dv ++ ;
			}
			li = max(dv, cr);
		}
	}
	cout << answ << "\n";
	return 0;
}