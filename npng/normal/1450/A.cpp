#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=200;
int n;
char s[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		sort(s+1,s+1+n);
		for(int i=1;i<=n;i++){
			putchar(s[i]);
		}
		puts("");
	}
	return 0;
}