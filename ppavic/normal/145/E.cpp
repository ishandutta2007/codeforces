#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 500;
const int OFF = (1 << 20);

struct node{
	int b0, b1, s0, s1;
	node(){
		b0 = 0, b1 = 0, s0 = 0, s1 = 0;
	}
	node(bool ja){
		b0 = !ja, b1 = ja, s0 = 1, s1 = 1;
	}
	void flip(){
		b0 ^= b1, b1 ^= b0, b0 ^= b1;
		s0 ^= s1, s1 ^= s0, s0 ^= s1;		
	}
};

node operator+(const node &L, const node &R){
	node ret; 
	ret.b0 = L.b0 + R.b0;
	ret.b1 = L.b1 + R.b1;
	ret.s0 = max(L.s0 + R.b1, L.b0 + R.s0);
	ret.s1 = max(L.s1 + R.b0, L.b1 + R.s1);
	return ret;
}

node T[2 * OFF];
int prop[2 * OFF], n, q;
char ty[10];

void refresh(int x){
	if(!prop[x]) return;
	T[x].flip();
	if(x < OFF){
		prop[2 * x] ^=  1;
		prop[2 * x + 1] ^= 1;
	}
	prop[x] = 0;
}

void update(int i, int a, int b, int lo, int hi){
	refresh(i);
	if(lo <= a && b <= hi){
		prop[i] ^= 1; refresh(i);
		return;
	}
	if(a > hi || b < lo) return;
	update(2 * i, a, (a + b) / 2, lo, hi);
	update(2 * i + 1, (a + b) / 2 + 1, b, lo, hi);
	T[i] = T[2 * i] + T[2 * i + 1];
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 0;i < n;i++){
		char c; scanf(" %c", &c);
		T[OFF + i] = node(c == '7');
	}
	for(int i = OFF - 1; i ; i--)
		T[i] = T[2 * i] + T[2 * i + 1];
	for(;q--;){
		scanf("%s", ty);
		if(ty[0] == 'c')
			printf("%d\n", T[1].s0);
		else{
			int l, r; scanf("%d%d", &l, &r);
			update(1, 0, OFF - 1, l - 1, r - 1);
		}
	}
}