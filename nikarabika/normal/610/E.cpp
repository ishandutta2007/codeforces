#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 85 - 69;
int seg1[maxn * 4], seg2[100][maxn * 4], laz2[maxn * 4];
char s[maxn], charac[maxn / 10 + 10];
bool mark[maxn];
int n, m, k;

int atob(int x, int y){return x * k + y;}

void build2(int l = 0, int r = n - 1, int id = 1){
	if(r <= l)
		return;
	if(r - l == 1){
		seg2[atob(s[l] - 'a', s[r] - 'a')][id] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build2(l, mid, id * 2 + 0);
	build2(mid, r, id * 2 + 1);
	for(int i = 0; i < k * k; i++)
		seg2[i][id] = seg2[i][id * 2 + 0] + seg2[i][id * 2 + 1];
	return;
}

void modify1(int val, int st, int en, int l = 0, int r = n, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		seg1[id] = val;
		return;
	}
	int mid = (l + r) >> 1;
	modify1(val, st, en, l, mid, id * 2 + 0);
	modify1(val, st, en, mid, r, id * 2 + 1);
	return;
}

int get1(int idx, int l = 0, int r = n, int id = 1){
	if(idx < l or r <= idx)
		return -1;
	if(r - l == 1)
		return seg1[id];
	int mid = (l + r) >> 1;
	return max(seg1[id],
			max(get1(idx, l, mid, id * 2 + 0),
				get1(idx, mid, r, id * 2 + 1)));
}

void push2(int, int, int);

void modify2(int val, int st, int en, int l = 0, int r = n - 1, int id = 1){
	if(st >= r or en <= l)
		return;
	if(st <= l and r <= en){
		for(int i = 0; i < k * k; i++)
			seg2[i][id] = 0;
		laz2[id] = val;
		seg2[val][id] = r - l;
		return;
	}
	int mid = (l + r) >> 1;
	push2(l, r, id);
	modify2(val, st, en, l, mid, id * 2 + 0);
	modify2(val, st, en, mid, r, id * 2 + 1);
	for(int i = 0; i < k * k;i++)
		seg2[i][id] = seg2[i][id * 2 + 0] + seg2[i][id * 2 + 1];
	return;
}

void push2(int l, int r, int id){
	if(laz2[id] != -1){
		int mid = (l + r) >> 1;
		modify2(laz2[id], l, mid, l, mid, id * 2 + 0);
		modify2(laz2[id], mid, r, mid, r, id * 2 + 1);
		laz2[id] = -1;
	}
	return;
}

inline int count2(void){
	int ret = 0;
	for(int i = 0; i < k * k; i++)
		ret += seg2[i][1] * mark[i];
	return ret;
}

inline int str(int tm, int idx){return tm ? charac[tm] - 'a' : s[idx] - 'a';}

int main(){
	memset(laz2, -1, sizeof laz2);
	//cin >> n >> m >> k;
	scanf("%d%d%d", &n, &m, &k);
	//cin >> s;
	scanf("%s", s);
	build2();
	for(int ii = 1; ii <= m; ii++){
		int ty;
		//cin >> ty;
		scanf("%d", &ty);
		if(ty == 1){
			int fi, se, th;
			char ch;
			//cin >> fi >> se >> ch;
			scanf("%d%d", &fi, &se);
			scanf("%c", &ch);
			scanf("%c", &ch);
			th = ch - 'a';
			charac[ii] = ch;
			fi--;
			modify1(ii, fi, se);
			if(fi < se - 1) modify2(atob(th, th), fi, se - 1);
			if(fi > 0) modify2(atob(str(get1(fi - 1), fi - 1), th), fi - 1, fi);
			if(se < n) modify2(atob(th, str(get1(se), se)), se - 1, se);
		}
		else{
			char t[k + 5];
			//cin >> t;
			scanf("%s", t);
			memset(mark, false, sizeof mark);
			for(int i = 0; i < k; i++)
				for(int j = 0; j <= i; j++)
					mark[atob(t[i] - 'a', t[j] - 'a')] = true;
			//cout << count2() + 1 << '\n';
			printf("%d\n", count2() + 1);
		}
	}
	return 0;
}