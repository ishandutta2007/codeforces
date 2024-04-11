#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef pair < ll, ll > pll;

const int N = 1e5 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int OFF = (1 << 18);

int flip[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

int T, H, M;

int reflect(int h, int m){
	int hh = -1, mm = -1;
	if(flip[h % 10] != -1 && flip[h / 10] != -1)
		mm = 10 * flip[h % 10] + flip[h / 10];
	if(flip[m % 10] != -1 && flip[m / 10] != -1)
		hh = 10 * flip[m % 10] + flip[m / 10];
	if(hh >= 0 && hh < H && mm >= 0 && mm < M)
		return hh * M + mm;
	return -1;
}

int main(){
	scanf("%d", &T);
	for(;T--;){
		int h, m; scanf("%d%d %d:%d", &H, &M, &h, &m);
		while(reflect(h, m) == -1){
			m++; 
			if(m == M) h++, m = 0;
			if(h == H) h = 0;
		}
		if(h < 10) printf("0");
		printf("%d:", h);
		if(m < 10) printf("0");
		printf("%d\n", m);
	}
	return 0;
}