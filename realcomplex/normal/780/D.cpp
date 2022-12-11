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

set<string>used;
set<string>res;

int main(){
	int n;
	cin >> n;	
	string ans[n];
	string a,b;
	for(int i = 0;i<n;i++){
		cin >> a >> b;
		a = a.substr(0,3);
		b = a.substr(0,2) + b[0];
		if(!used.count(b)){
			ans[i] = b;
			used.insert(b);
		}
		else{
			if(res.count(a) or used.count(a)){
				cout << "NO\n";
				return 0;
			}
			ans[i] = a;
			used.insert(a);
		}
		res.insert(a);
	}
	cout << "YES\n";
	for(int i = 0;i<n;i++)
	cout << ans[i] << "\n";
	return 0;
}