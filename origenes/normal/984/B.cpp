#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=123;
int n, m;
char mmap[maxn][maxn];
bool check(int x, int y){
	int cnt=0;
	if(mmap[x][y]=='*') return true;
	if(mmap[x-1][y]=='*') cnt++;
	if(mmap[x+1][y]=='*') cnt++;
	if(mmap[x][y-1]=='*') cnt++;
	if(mmap[x][y+1]=='*') cnt++;
	if(mmap[x-1][y-1]=='*') cnt++;
	if(mmap[x-1][y+1]=='*') cnt++;
	if(mmap[x+1][y-1]=='*') cnt++;
	if(mmap[x+1][y+1]=='*') cnt++;
	if(mmap[x][y]=='.'){
		return cnt==0;
	}
	return cnt==mmap[x][y]-'0';
}
int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
	scanf("%d%d", &n, &m);
	for(int i=1; i<=n; i++)
		scanf("%s", mmap[i]+1);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(!check(i, j)){
				puts("NO");
				//cout<<i<<' '<<j<<endl;
				return 0;
			}
		}
	}
	puts("YES");
	return 0;
}