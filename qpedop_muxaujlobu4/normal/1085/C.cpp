#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct MC {
	int x;
	int y;
};
bool cmp(const MC& MC1, const MC& MC2) {
	if(MC1.y < MC2.y)return true;
	if (MC1.y == MC2.y && MC1.x < MC2.x)return true;
	return false;
}
int ct = 0;
int a[1001][1001];
void DestroyForest(const MC& MC1) {
	a[MC1.x][MC1.y] = 1;
	++ct;
}
int main()
{
	for (int i = 0; i < 1001; ++i)
		for (int j = 0; j < 1001; ++j)
			a[i][j] = 0;
	vector<MC>b(3);
	cin >> b[0].x >> b[0].y >> b[1].x >> b[1].y >> b[2].x >> b[2].y;
	sort(b.begin(), b.end(), cmp);
	MC DsOb=b[0];
	DestroyForest(b[0]);
	while (DsOb.y < b[1].y) {
		++DsOb.y;
		DestroyForest(DsOb);
	}
	MC DsCopy = DsOb;
	while (b[1].x - DsOb.x > 0) {
		++DsOb.x;
		DestroyForest(DsOb);
	}
	while (b[1].x - DsOb.x < 0) {
		--DsOb.x;
		DestroyForest(DsOb);
	}
	DsOb = DsCopy;
	while (b[2].x - DsOb.x > 0) {
		++DsOb.x;
		if (a[DsOb.x][DsOb.y] == 0)DestroyForest(DsOb);
	}
	while (b[2].x - DsOb.x < 0) {
		--DsOb.x;
		if (a[DsOb.x][DsOb.y] == 0)DestroyForest(DsOb);
	}
	while (b[2].y > DsOb.y) {
		++DsOb.y;
		DestroyForest(DsOb);
	}
	cout << ct << "\n";
	for (int i = 0; i < 1001; ++i)
		for (int j = 0; j < 1001; ++j)
			if (a[i][j] == 1)cout << i << " " << j << "\n";
	return 0;
}