#include <bits/stdc++.h>
using namespace std;

typedef long long meoww;

meoww nya, meow, purr, kya, nyans = 0;
vector<meoww> cats;
vector<vector<meoww>> cats_next_door;
vector<meoww> meowed;

void meowfs(meoww nyaow, meoww consecutive_meows) {
	meowed[nyaow] = 1;
	if (consecutive_meows > meow) {return;}
	if (cats_next_door[nyaow].size() == 1 && nyaow > 1) {nyans++; return;}
	for (meoww nyan = 0; nyan < cats_next_door[nyaow].size(); nyan++) {
		if (meowed[cats_next_door[nyaow][nyan]] == 0) {
			if (cats[cats_next_door[nyaow][nyan]] == 1) {meowfs(cats_next_door[nyaow][nyan], consecutive_meows+1);} else {meowfs(cats_next_door[nyaow][nyan], 0LL);}
		}
	}
}

int main() {
	
	cin >> nya >> meow;
	cats.resize(nya+1);
	meowed.resize(nya+1, 0);
	cats_next_door.resize(nya+1, vector<meoww>(0));
	for (meoww nyan = 1; nyan <= nya; nyan++) {
		cin >> cats[nyan];
	}
	while (--nya) {
		cin >> purr >> kya;
		cats_next_door[purr].push_back(kya);
		cats_next_door[kya].push_back(purr);
	}
	meowfs(1, cats[1]);
	
	cout << nyans;
	
	return 0;
}