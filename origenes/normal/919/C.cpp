#include <cstdio>
using namespace std;
typedef long long ll;
char mmap[2134][2134];
int main(){
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	getchar();
	for(int i=1; i<=n; i++){
		mmap[i][0]='*';
		for(int j=1; j<=m; j++){
			scanf("%c", &mmap[i][j]);
		}
		getchar();
		mmap[i][m+1]='*';
	}
	ll res=0;
	for(int i=1; i<=n; i++){
		int cnt=0;
		for(int j=0; j<=m+1; j++){
			if(mmap[i][j]=='.') cnt++;
			else{
				if(cnt>=k) res+=cnt-k+1;
				cnt=0;
			}
		}
	}
	for(int i=1; i<=m; i++){
		int cnt=0;
		for(int j=0; j<=n+1; j++){
			if(mmap[j][i]=='.') cnt++;
			else{
				if(cnt>=k) res+=cnt-k+1;
				cnt=0;
			}
		}
	}
	if(k==1) res/=2;
	printf("%I64d\n", res);
	return 0;
}