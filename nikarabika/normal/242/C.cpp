#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define MT(x, y, z) MP(x, MP(y, z))
#define L first
#define M second.first
#define R second.second

typedef long long int LL;
typedef pair<int, int> pie;
typedef pair<int, pie> piie;

int an[8][2] = {{-1, -1}, {-1, 0}, {-1, +1}, {0, -1}, {0, +1}, {+1, -1}, {+1, 0}, {+1, +1}};
const int maxn = 1e5 + 85 - 85 + 10;
vector<int> b[maxn], d[maxn];
piie a[maxn];
int n, x0, Y0, x1, Y1, Min = 2e9, Max = -1;
set<piie> s;

bool hast(int x, int y){
	if(x < 1 or x > Max - Min + 1)
		return false;
	int id = lower_bound(b[x].begin(), b[x].end(), y) - b[x].begin();
	if(id >= b[x].size() or b[x][id] != y)
		return false;
	return true;
}

int getd(int x, int y){
	int id = lower_bound(b[x].begin(), b[x].end(), y) - b[x].begin();
	return d[x][id];
}

void setd(int x, int y, int val){
	int id = lower_bound(b[x].begin(), b[x].end(), y) - b[x].begin();
	d[x][id] = val;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> x0 >> Y0 >> x1 >> Y1;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i].L >> a[i].M >> a[i].R;
	sort(a, a + n);
	int st = lower_bound(a, a + n, MT(x0, 0, 0)) - a, en = st;
	while(st > 0 and a[st].L - a[st - 1].L <= 1)
		st--;
	while(en + 1 < n and a[en + 1].L - a[en].L <= 1)
		en++;
	for(int i = st; i <= en; i++)
		Min = min(Min, a[i].L), Max = max(Max, a[i].L);
	if(x1 > Max or x1 < Min){
		cout << -1 << endl;
		return 0;
	}
	int lastrow = -2e9, p;
	for(int i = st; i <= en; i++){
		if(a[i].L != lastrow)
			p = a[i].M;
		else if(p > a[i].R)
			continue;
		else
			p = max(p, a[i].M);
		while(p <= a[i].R)
			b[a[i].L - Min + 1].PB(p++);
		lastrow = a[i].L;
	}
	for(int i = 1; i <= Max - Min + 1; i++)
		d[i].resize(b[i].size(), 2e9);
	x0 = x0 - Min + 1;
	x1 = x1 - Min + 1;
	setd(x0, Y0, 0);
	s.insert(MT(0, x0, Y0));
	while(s.size()){
		int x = s.begin()->M, y = s.begin()->R;
		s.erase(s.begin());
		int dxy = getd(x, y);
		for(int i = 0; i < 8; i++){
			int xp = x + an[i][0], yp = y + an[i][1];
			if(!hast(xp, yp))
				continue;
			int dxyp = getd(xp, yp);
			if(dxy + 1 < getd(xp, yp)){
				s.erase(MT(dxyp, xp, yp));
				setd(xp, yp, dxy + 1);
				s.insert(MT(dxy + 1, xp, yp));
			}
		}
	}
	if(getd(x1, Y1) == 2e9)
		cout << -1 << endl;
	else
		cout << getd(x1, Y1) << endl;
	return 0;
}