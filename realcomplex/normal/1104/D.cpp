#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

map<pii, char> answ;

char query(int x, int  y){
	cout << "? " << x << " " << y << endl;
	fflush(stdout);
	char ret;
	cin >> ret;
	return ret;
}

void answer(int a){
	cout << "! " << a << endl;
}

void play(){
	if(query(0, 1) == 'x'){
		answer(1);
		return;
	}
	int dv = 0;
	int dc = 1;
	while(query(dc, dc * 2) == 'y'){
		dc *= 2;
	}
	dv += dc;
	dc /= 2;
	while(dc > 0){
		if(query(dv, dv + dc) == 'y')
			dv += dc;
		dc /= 2;
	}
	answer(dv + 1);
}

int main(){
	string t;
	while(1){
		cin >> t;
		if(t == "end")
			return 0;
		play();
	}
	return 0;
}