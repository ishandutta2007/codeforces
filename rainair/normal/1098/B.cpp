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

const int MAXN = 3e5 + 5;
std::vector<int> a[MAXN],ans[MAXN],t[MAXN];
int n,m;
char str[MAXN];

inline void upans(){
	int c1 = 0,c2 = 0;
	FOR(i,1,n) FOR(j,1,m) c1 += (a[i][j] != ans[i][j]),c2 += (a[i][j] != t[i][j]);
	if(c1 > c2){
		FOR(i,1,n) FOR(j,1,m) ans[i][j] = t[i][j];
	}
}

int ctoi[MAXN];
char itoc[MAXN];
int p[MAXN];

int main(){
	ctoi['A'] = 1;ctoi['G'] = 2;ctoi['C'] = 3;ctoi['T'] = 4;
	itoc[1] = 'A';itoc[2] = 'G';itoc[3] = 'C';itoc[4] = 'T';
	scanf("%d%d",&n,&m);
	FOR(i,1,n) a[i].resize(m+1),ans[i].resize(m+1),t[i].resize(m+1);
	FOR(i,1,n){
		scanf("%s",str+1);
		FOR(j,1,m) a[i][j] = ctoi[str[j]];
	}
	FOR(i,1,4) p[i] = i;
	do{// /
		// 
		FOR(i,1,n){
			int t1 = 0,t2 = 0,b = (i&1)*2;
			FOR(j,1,m){
				t1 += (a[i][j] != p[b + (j&1) + 1]);
				t2 += (a[i][j] != p[b + (!(j&1)) + 1]);
			}
			if(t1 < t2){
				FOR(j,1,m) t[i][j] = p[b + (j&1) + 1];
			}
			else{
				FOR(j,1,m) t[i][j] = p[b + (!(j&1)) + 1];
			}
		}
		upans();
		FOR(j,1,m){
			int t1 = 0,t2 = 0,b = (j&1)*2;
			FOR(i,1,n){
				t1 += (a[i][j] != p[b + (i&1) + 1]);
				t2 += (a[i][j] != p[b + (!(i&1)) + 1]);
			}
			if(t1 < t2){
				FOR(i,1,n) t[i][j] = p[b + (i&1) + 1];
			}
			else{
				FOR(i,1,n) t[i][j] = p[b + (!(i&1)) + 1];
			}
		}
		upans();
	}while(std::next_permutation(p+1,p+4+1));
	FOR(i,1,n){
		FOR(j,1,m) printf("%c",itoc[ans[i][j]]);
		puts("");
	}
	return 0;
}