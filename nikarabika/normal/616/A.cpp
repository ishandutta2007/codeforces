#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#undef n1
#undef n2
#define n1 N
#define n2 NN

const int maxn = 1e6 + 10;
char n1[maxn], n2[maxn];
vector<int> v1, v2;

int main(){
	scanf("%s", n1);
	scanf("%s", n2);
	int p = 0, q = 0;
	while(n1[p] == '0') p++;
	while(n2[q] == '0') q++;
	v1.PB(0), v2.PB(0);
	while(n1[p] != 0)
		v1.PB(n1[p++] - '0');
	while(n2[q] != 0)
		v2.PB(n2[q++] - '0');
	if(sz(v1) < sz(v2))
		printf("<\n");
	else if(sz(v1) > sz(v2))
		printf(">\n");
	else{
		int pos = 0;
		while(pos < sz(v1)){
			if(v1[pos] < v2[pos]){
				printf("<\n");
				return 0;
			}
			if(v1[pos] > v2[pos]){
				printf(">\n");
				return 0;
			}
			pos++;
		}
	printf("=\n");
	}
	return 0;
}