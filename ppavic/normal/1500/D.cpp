#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
 
#define PB push_back
#define X first
#define Y second
 
using namespace std;
 
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef pair < int, vi > piv;
 
const int N =  1e3 + 550;
 
vector < pii > v[N][N];
 
vector < pii > A[3];
int n, k, maax[N][N], B[N][N], sol[N], cnt[N * N], cookie;
 
void spoji(int x, int &mx, vector < pii > &ret){
	ret.PB({1, x}); int kol = 1; cnt[x] = cookie;
	for(int b = 0;b < 3;b++){ 
		reverse(A[b].begin(), A[b].end());
		for(pii &tmp : A[b])
			tmp.X++;
	}
	for(;!(A[0].empty() && A[1].empty() && A[2].empty());){
		int miin = N;
		vi sad;
		for(int b = 0;b < 3;b++)
			if(!A[b].empty()) miin = min(A[b].back().X, miin);
		if(miin > mx) return;
		for(int b = 0;b < 3;b++){
			while(!A[b].empty() && A[b].back().X == miin){
				if(cnt[A[b].back().Y] != cookie)
					sad.PB(A[b].back().Y), cnt[A[b].back().Y] = cookie, kol++;
				A[b].pop_back();
			}
		}
		if(kol > k){
			mx = miin - 1;
			return;
		}
		for(int x : sad) ret.PB({miin, x});
	}
}
 
 
int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			scanf("%d", &B[i][j]);
	for(int i = n - 1;i >= 0;i--){
		for(int j = n - 1;j >= 0;j--){
			cookie++;
			maax[i][j] = 1 + min(min(maax[i + 1][j], maax[i][j + 1]), maax[i + 1][j + 1]);
			A[0] = v[i + 1][j], A[1] = v[i][j + 1], A[2] = v[i + 1][j + 1];
			spoji(B[i][j], maax[i][j], v[i][j]);
			sol[maax[i][j]]++;
			if((int)v[i][j].size() > k){
				printf("KOJI KURAC\n");
				return 0;
			}
		}
	}
	for(int i = N - 2;i >= 0;i--)
		sol[i] += sol[i + 1];
	for(int i = 1;i <= n;i++)
		printf("%d\n", sol[i]);
	return 0;
}