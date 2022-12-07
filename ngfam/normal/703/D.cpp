#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int a[N], sxor[N], n, ans[N];
int last[N];
struct fenwick{
	int bit[N];

	void upd(int i, int x){
		for(; i < N; i += i & -i) bit[i] ^= x;
	}

	int ask(int i){
		int result = 0;
		for(; i > 0; i &= i - 1) result ^= bit[i];
		return result;
	}
}fwt;

typedef pair<int,int> ii;

ii shift[N];

int gtx[N];

struct quest{
	int l;
	int r;
	int id;
	int type;
}item[N * 2];

bool cmp(quest u, quest v){
	if(u.r == v.r){
		return u.type < v.type;
	}
	return u.r < v.r;
}

int nextInt(){
  char c = getchar();
  while(!isdigit(c)){
    c = getchar();
  }
  int answer = 0;
  while(isdigit(c)){
    answer = (answer << 1) + (answer << 3) + c - '0';
    c = getchar();
  }
  return answer;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
//		freopen("1.out", "w", stdout);
	#endif
  n = nextInt();
	int sz = 0;
  vector < int > small;
	for(int i = 1; i <= n; ++i){
    a[i] = nextInt();
		item[++sz] = {a[i], i, i, 0};
	//	shift[i] = ii(a[i], i);
    small.push_back(a[i]);
	}
	sort(small.begin(), small.end());
	small.resize(unique(small.begin(), small.end()) - small.begin());
	for(int i = 1; i <= sz; ++i){
    int fin = lower_bound(small.begin(), small.end(), item[i].l) - small.begin() + 1;
    gtx[fin] = item[i].l;
    item[i].l = fin;
	}
	for(int i = 1; i <= n; ++i){
		sxor[i] = sxor[i - 1] ^ a[i];
	}
	int q; scanf("%d", &q);
	for(int i = 1; i <= q; ++i){
		int l, r;
		l = nextInt();
		r = nextInt();
		item[++sz] = {l, r, i, 1};
	}
	sort(item + 1, item + sz + 1, cmp);
	for(int i = 1; i <= sz; ++i){
		int l = item[i].l, r = item[i].r;

	//	/cout << item[i].type << " " << l << " " << r << endl;

		if(item[i].type == 0){
			if(last[l] != 0){
				fwt.upd(last[l], gtx[l]);
			}
			fwt.upd(item[i].r, gtx[l]);
			last[l] = r;
		}
		else{
			ans[item[i].id] = (fwt.ask(r) ^ fwt.ask(l - 1)) ^ (sxor[r] ^ sxor[l - 1]);
		}
	}
	for(int i = 1; i <= q; ++i){
		printf("%d\n", ans[i]);
	}
	return 0;
}
///