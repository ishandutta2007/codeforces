#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define inf 0x3f3f3f3f
 
typedef unsigned long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<long long,int> pli;
typedef double db;
// head
 
const int mod=998244353;
const int N=5e5+5;

int T,n;
char str[N];
int cnt[30];
bool mark[30];
vi vec;
int las[N],nxt[N];

int main() {
	scanf("%d",&T);
	while (T--) {
		bool f=1;
		vec.clear();
		scanf("%s",str+1); n=strlen(str+1);
		rep(i,0,26) cnt[i]=0,mark[i]=0;
		per(i,n+1,1) {
			int c=str[i]-'a';
			cnt[c]++;
			if (!mark[c]) mark[c]=1,vec.pb(c);
		}
		int sz=SZ(vec),p=0;
		rep(i,0,SZ(vec)) {
			int c=vec[i];
			if (cnt[c]%(sz-i)) {f=0; break;}	
			cnt[c]/=sz-i;
			p+=cnt[c];
		}
		
		nxt[0]=1;
		rep(i,1,p+1) nxt[i]=i+1,las[i]=i-1;
		las[p+1]=0;
		
		// debug(p);
		
		int g=1;
		per(i,SZ(vec),0) {
			if (!f) break;
			int c=vec[i];
			// debug(c);
			for (int cur=nxt[0];cur!=p+1;cur=nxt[cur]) {
				if (str[g]!=str[cur]) {f=0; break;}
				else g++;
			}
			for (int cur=nxt[0];cur!=p+1;cur=nxt[cur]) {
				if (str[cur]=='a'+c) {
					int x=las[cur],y=nxt[cur];
					las[y]=x,nxt[x]=y;
				}
			}
			
			// for (int cur=nxt[0];cur!=p+1;cur=nxt[cur]) printf("%c",str[cur]);
			// puts("");
		}
		
		if (f) {
			rep(i,1,p+1) printf("%c",str[i]); printf(" ");
			per(i,sz,0) printf("%c",vec[i]+'a'); puts("");
		}else puts("-1");
		// puts("----");
	}
	return 0;	
}
/*
1
abacabaaacaac
*/