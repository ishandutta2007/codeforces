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

bool pal(string u){
	for(int i = 0;i<(int)u.size();i++){
		if(u[i] != u[(int)u.size()-i-1])
			return false;
	}
	return true;
}

int main(){
	fastIO;
	string a;
	cin >> a;
	int k;
	cin >> k;
	int n = a.size();
	if(n % k != 0){
		cout << "NO\n";
		return 0;
	}
	int p = n/k;
	int l = 0;
	for(int i = 0;i<k;i++){
		if(!pal(a.substr(l,p))){
			cout << "NO\n";
			return 0;
		}
		l+=p;
	}
	cout << "YES\n";
	return 0;
}