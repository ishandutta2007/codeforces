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
#define y0 yzero

const int maxn = 5e5 + 85 - 69;
int x[maxn],
	y[maxn],
	n, x0, y0;
char ty[maxn];

bool isq(int id){
	return id != -1 and ty[id] == 'Q';
}

bool isr(int id){
	return id != -1 and ty[id] == 'R';
}

bool isb(int id){
	return id != -1 and ty[id] == 'B';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n
		>> x0 >> y0;
	int up = -1, dn = -1, ri = -1, le = -1,
		upri = -1, uple = -1, dnri = -1, dnle = -1;
	for(int i = 0; i < n; i++){
		cin >> ty[i] >> x[i] >> y[i];
		x[i] -= x0;
		y[i] -= y0;
		if(x[i] == 0){
			if(y[i] > 0 and (up == -1 or y[up] > y[i])) up = i;
			if(y[i] < 0 and (dn == -1 or y[dn] < y[i])) dn = i;
		}
		else if(y[i] == 0){
			if(x[i] > 0 and (ri == -1 or x[ri] > x[i])) ri = i;
			if(x[i] < 0 and (le == -1 or x[le] < x[i])) le = i;
		}
		else if(x[i] == y[i]){
			if(x[i] > 0 and (upri == -1 or x[upri] > x[i])) upri = i;
			if(x[i] < 0 and (dnle == -1 or x[dnle] < x[i])) dnle = i;
		}
		else if(x[i] == -y[i]){
			if(x[i] < 0 and (uple == -1 or x[uple] < x[i])) uple = i;
			if(x[i] > 0 and (dnri == -1 or x[dnri] > x[i])) dnri = i;
		}
	}
	if(isq(up) or isq(dn) or isq(ri) or isq(le) or isq(upri) or isq(dnle) or isq(uple) or isq(dnri)){
		cout << "YES\n";
		return 0;
	}
	if(isr(up) or isr(dn) or isr(le) or isr(ri)){
		cout << "YES\n";
		return 0;
	}
	if(isb(upri) or isb(uple) or isb(dnri) or isb(dnle)){
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";
	return 0;
}