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

const int N = (int)2e6 + 9;
int v[N];

map<char,char> rev;

int main(){
	fastIO;
	rev['N'] = 'S';
	rev['S'] = 'N';
	rev['W'] = 'E';
	rev['E'] = 'W';
	int n;
	cin >> n;
	string a,b;
	cin >> a >> b ;
	for(auto &x : b)
		x = rev[x];
	reverse(b.begin(),b.end());
	string f = b + '$' + a;
	for(int i = 1,j = 0 ;i<(int)f.size();i++){
		while(f[i] != f[j] and j > 0){
			j = v[j-1];
		}
		if(f[i] == f[j]){ // go foward
			j ++ ;
		}
		v[i] = j;
	}
	if(v[f.size()-1] == 0){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}
	return 0;
}