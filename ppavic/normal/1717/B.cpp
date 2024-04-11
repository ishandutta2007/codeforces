#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>

#define PB push_back
#define X first
#define Y second

using namespace std;

typedef long long ll;

int n, k, r, c;

int main(){
	int T; scanf("%d", &T);
	for(;T--;){
		scanf("%d%d%d%d", &n, &k, &r, &c);
		r--;c--;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				printf((i + j) % k == (r + c) % k ? "X" : ".");
			}
			printf("\n");
		}
	}
	return 0;
}