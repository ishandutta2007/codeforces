#include <iostream>

using namespace std;

int n;
int x1[155555];
int y1[155555];
int x2[155555];
int y2[155555];

void lol(int k) {
	int ax = -1e9;
	int bx = 1e9;
	int ay = -1e9;
	int by = 1e9;
	for (int i = 1; i <= n; i++) {
		if (i == k) continue;
		ax = max(ax,x1[i]);
		bx = min(bx,x2[i]);
		ay = max(ay,y1[i]);
		by = min(by,y2[i]);
	}
	if (ax <= bx && ay <= by) {
		cout << ax << " " << ay << "\n";
		exit(0);
	}
}

int main() {
	cin >> n;
	pair<int,int> ax = {-1e9,0};
	pair<int,int> bx = {1e9,0};
	pair<int,int> ay = {-1e9,0};
	pair<int,int> by = {1e9,0};
	for (int i = 1; i <= n; i++) {
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		ax = max(ax,{x1[i],i});
		bx = min(bx,{x2[i],i});
		ay = max(ay,{y1[i],i});
		by = min(by,{y2[i],i});
	}
	lol(ax.second);
	lol(bx.second);
	lol(ay.second);
	lol(by.second);
}