//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

int calc(int a, int b){
	if(a < b) return 2 - calc(b, a);
	LL suma = 0,
	   sumb = 0;
	int pos = 0;
	for(int i = 0; i < b; i++){
		int npos = (pos + (a - pos + b - 1) / b * b) % a;
		suma += b - npos;
		sumb += a - (b - npos);
		pos = npos;
	}
	return (suma == sumb) ? 1 : 2 * (suma < sumb);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	string s[3] = {"Dasha", "Equal", "Masha"};
	cout << s[calc(a, b)] << '\n';
	return 0;
}