#include <bits/stdc++.h>
#define FWD(a,b,c) for(int a=(b); a<(c); ++a)
#define BCK(a,b,c) for(int a=(b); a>(c); --a)
#define ALL(a) (a).begin(), (a).end()
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
typedef pair<unsigned, unsigned> PUU;
typedef long long LL;
typedef long double K;
typedef tuple<int, int, int> III;

const int mod = 1000000007;
const int INF = 1000000000;

struct block {
	vector<int> data;
	map<int, int> cnt;
	int size(){ return data.size(); }
	int count(int x){ return cnt[x]; }
	void insert(int i, int x){
		++cnt[x];
		data.insert(data.begin()+i, x);
	}
	void remove(int i){
		--cnt[data[i]];
		data.erase(data.begin()+i);
	}
	int count(int i, int j, int x){
		int c = 0; while(i <= j) c += data[i++] == x;
		return c;
	}
};

int n, m, s, t;
int T[100010];
vector<block> S;

void build(){
	s = 4*sqrt(n);
	t = 0;
	int k = 0;
	while(k < n){
		S.push_back(block());
		S.back().data.reserve(min(s, n-k));
		FWD(i,k,min(n,k+s))
			S.back().insert(i-k, T[i]);
		k += s;
	}
}

void rebuild(){
	n = 0;
	for(block &b : S)
		FWD(i,0,b.size()) T[n++] = b.data[i];
	S.clear();
	build();
}

int usun(int i){
	int p = 0;
	for(block &b : S){
		if(i < p + b.size()){
			int x = b.data[i-p];
			b.remove(i-p);
			return x;
		}
		p += b.size();
	}
}

void dodaj(int i, int x){
	int p = 0;
	for(block &b : S){
		if(i <= p + b.size()){
			b.insert(i-p, x);
			return;
		}
		p += b.size();
	}
}

int policz(int i, int j, int x){
	int p = 0;
	int c = 0;
	bool ins = 0;
	//printf("policz %d %d %d\n", i, j, x);
	for(block &b : S){
		//printf("w bloku [%d, %d)\n", p, p+b.size());
		if(!ins && i < p + b.size()){
			//printf("poczatek jest tu\n");
			if(j < p + b.size()){
				//printf("koniec tez\n");
				return b.count(i-p, j-p, x);
			}
			c += b.count(i-p, b.size()-1, x);
			ins = 1;
		}else{
			//printf("koniec jest tu\n");
			if(j < p + b.size())
				return c + b.count(0, j-p, x);
			if(ins){
				//printf("caly w srodku\n");
				c += b.count(x);	
			}
		}
		p += b.size();
	}
}

int main(){
	scanf("%d", &n);
	FWD(i,0,n) scanf("%d", &T[i]);
	scanf("%d", &m);
	build();
	int lastans = 0;
	FWD(i,0,m){
		int t, a, b, c;
		scanf("%d %d %d", &t, &a, &b);
		a = (a + lastans - 1) % n;
		b = (b + lastans - 1) % n;
		if(a > b) swap(a, b);
		if(t == 1){
			dodaj(a, usun(b));
			if(++t == s) rebuild();
		}else{
			scanf("%d", &c);
			c = (c + lastans - 1) % n + 1;
			lastans = policz(a, b, c);
			printf("%d\n", lastans);
		}
		//printf("state\n");
		//for(block &b : S)
		//	FWD(i,0,b.size())
		//		printf("%d ", b.data[i]);
		//printf("\n");
	}
	return 0;
}