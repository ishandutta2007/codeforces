#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>

#define X first
#define Y second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef vector < pii > vp;
typedef set < int > si;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 20;
const int OFF = (1 <<  LOG);

int n, m;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= (n + 1) / 2;i++){
		if(i == n - i + 1){
			for(int l = 1, r = m;l <= r;l++,r--){
				printf("%d %d\n", i, l);
				if(l != r) 
					printf("%d %d\n", i, r);
			}
		}
		else{
			for(int j = 1;j <= m;j++){
				printf("%d %d\n%d %d\n", i, j, n - i + 1, m - j + 1);
			}
		}
	}
	return 0;
}