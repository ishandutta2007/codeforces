#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define debug printf
#define cerr if(0)cout

typedef long long ll;
typedef pair<int, int> pii;

const int maxx = 6, maxy = 45, maxz = 19;
char t[maxx + 5][maxy + 5];
char dobry[maxx + 5][maxy + 5][maxz + 5];
char klat[][5] = {"####", "#..#", "#..#", "####", "#.##"};
int g[10][10];
int globn;

int kt = 0;
void flasz() {
	for(int i = 1; i <= maxx; ++i) {
		for(int j = 1; j <= maxy; ++j) {
			dobry[i][j][kt] = t[i][j];
			//cerr << t[i][j];
		}
	}
	++kt;
}

void pietro(int p) {
	char wyp = '#';
	if(p % 2) wyp = '.';
	for(int i = 1; i <= maxx; ++i) {
		for(int j = 1; j <= maxy; ++j) {
			t[i][j] = wyp;
		}
	}
}

void schod(int n, int f) {
	f %= 4;
	int x0 = 2, y0 = (n - 1) * 5 + 1;
	if(f == 1) t[x0 + 2][y0 + 2] = '#';
	else if(f == 2) t[x0 + 1][y0 + 2] = '#';
	else if(f == 3) t[x0 + 1][y0 + 1] = '#';
	else t[x0 + 2][y0 + 1] = '#';

}

void klatka(int n, int f) {
	int x0 = 2, y0 = (n - 1) * 5 + 1;
	for(int x = 0; x < 5; ++x) {
		for(int y = 0; y < 4; ++y) {
			t[x + x0][y + y0] = klat[x][y];
		}
	}
	schod(n, f);
}

void otworz(int n) {
	for(int i = 1; i <= 4; ++i)
		t[6][(n - 1) * 5 + i] = '.';
}

void byg(int nr) {
	pietro(nr);
	int okejek = 0;
	if(nr % 2) okejek = (nr - 1) / 2;
	else okejek = 0;
	for(int i = 1; i <= 9; ++i) {
		if(i != okejek) klatka(i, nr);
		else schod(i, nr);
	}
	for(int j = 1; j <= 9; ++j) {
		if(g[okejek][j]) {
			cerr << okejek << " " << j << "\n";
			otworz(j);
		}
	}
}

void montuj() {
	pietro(1);
	for(int i = 1; i <= 9; ++i) {
		klatka(i, 1);
		if(i <= globn) t[6][(i - 1) * 5 + 2] = '0' + i;
		t[5][(i - 1) * 5 + 2] = '.';
	}
	flasz();
	for(int i = 2; i <= 19; ++i) {
		byg(i);
		flasz();
	}
	
}

int main()
{
	cin >> globn;
	for(int i = 1; i <= globn; ++i) {
		for(int j = 1; j <= globn; ++j) {
			cin >> g[i][j];
		}
	}
	for(int i = 1; i <= globn; ++i) {
		for(int j = 1; j <= globn; ++j) {
			cerr << g[i][j] << " ";
		}
		cerr << "\n";
	}
	cout << maxy << " " << maxx << " " << maxz << "\n";
	montuj();
	for(int i = kt - 1; i >= 0; --i) {
		for(int x = 1; x <= maxx; ++x) {
			for(int y = 1; y <= maxy; ++y) {
				cout << dobry[x][y][i];
			}
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}