#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e6 + 5;
char str[MAXN];
int n;
int a[10][10][10];
int f[10];

int main(){
	FOR(x,0,9){
		FOR(y,0,9){
			CLR(f,-1);
			f[x] = f[y] = 0;
			std::queue<int> q;
			q.push(x);if(x != y) q.push(y);
			while(!q.empty()){
				int v = q.front();q.pop();
				if(f[(v+x)%10] == -1){
					f[(v+x)%10] = f[v]+1;
					q.push((v+x)%10);
				}
				if(f[(v+y)%10] == -1){
					f[(v+y)%10] = f[v]+1;
					q.push((v+y)%10);
				}
			}
			FOR(i,0,9) a[x][y][i] = f[i];
		}
	}
	scanf("%s",str+1);int n = strlen(str+1);
	int st = 1;
	if(str[1] == '0') st = 2;
	FOR(x,0,9){
		FOR(y,0,9){
			int now = 0,ans = 0;
			FOR(i,st,n){
				int o = str[i]-'0';
				int t = a[x][y][(o-now+10)%10];
				// if(x == 1 && y == 0){
					// DEBUG(x);DEBUG(t);
				// }
				if(t == -1){
					ans = -1;break;
				}
				ans += t;
				now = o;
			}
			printf("%d%c",ans," \n"[y==9]);
		}
	}
	return 0;
}