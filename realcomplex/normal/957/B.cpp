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
	int n,m;
	cin >> n >> m;
	char l[n][m];
	set<set<int>>cor;
	for(int i = 0;i<n;i++){
		set<int>c;
		for(int j = 0;j<m;j++){
			cin >> l[i][j];
			if(l[i][j] == '#')
				c.insert(j);
		}
		cor.insert(c);
	}
	for(auto x : cor){
		for(auto y : x){
			for(auto r : cor){
				if(r != x)
					if(r.count(y)){
						cout << "NO\n";
						return 0;
					}
			}
		}
	}
	cout << "Yes\n";
	return 0;
}