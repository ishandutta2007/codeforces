#include <cstdio>
#include <vector>
#include <algorithm>

#define PB push_back

using namespace std;

const int B = 350;
const int N = 1e5 + 500;
const int M = 1e4 + 50;

int ima[N / B][M];
int off[N], A[N], dob[N];
vector < int > dobri;
char ty[10];
int n, q;

inline void dodaj_jen(int x, int d){
	ima[x / B][A[x]]--;
	A[x] += d;
	ima[x / B][A[x]]++;
}

void dodaj(int l, int r,int d){
	if(r - l + 1 <= 2 * B){
		for(int k = l;k <= r;k++)
			dodaj_jen(k, d);
		return;
	}
	while((l % B) != 0)
		dodaj_jen(l++, d);
	while((r + 1) % B != 0)
		dodaj_jen(r--, d);
	for(int i = l;i <= r;i += B){
		off[i / B] += d;
	}
}

int kolko(int l, int r){
	if(r - l + 1 <= 2 * B){
		int ret = 0;
		for(int k = l;k <= r;k++){
			ret += dob[A[k] + off[k / B]];
		}
		return ret;
	}
	int ret = 0;
	while((l % B) != 0)
		ret += dob[A[l] + off[l / B]], l++;
	while((r + 1) % B != 0)
		ret += dob[A[r] + off[r / B]], r--;
	for(int i = l;i <= r;i += B){
		for(int x : dobri)
			if(x - off[i / B] >= 0)	
				ret += ima[i / B][x - off[i / B]];
	}
	return ret;
}

int main(){
	for(int i = 0;i < M;i++){
		dob[i] = 1; int cur = i;
		for(;cur; cur /= 10)
			dob[i] &= (cur % 10 == 4) || (cur % 10 == 7);
		if(dob[i])
			dobri.PB(i);
	}
	scanf("%d%d", &n, &q);
	for(int i = 0;i < n;i++){
		ima[i / B][0]++; int tmp; scanf("%d", &tmp);
		dodaj_jen(i, tmp);
	}
	for(;q--;){
		scanf("%s", ty);
		if(ty[0] == 'c'){
			int l, r; scanf("%d%d", &l, &r);
			printf("%d\n", kolko(l - 1, r - 1));
		}
		else{
			int l, r, d; scanf("%d%d%d", &l, &r, &d);
			dodaj(l - 1, r - 1, d);
		}
	}
}