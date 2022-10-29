#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,n,a) for (int i=(n)-1;i>=(a);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define make_unique(x) { sort(all(x)); x.resize(unique(all(x))-x.begin()); }
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
mt19937 mrand(time(0));
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int inf=1<<30;
const int mod=998244353;
// head
const int N=1e6+5;
int n,a[N];
char t[N];

struct unite_set {
    vector<int> fa,siz;
   	unite_set(int n):fa(n),siz(n,1) { iota(fa.begin(),fa.end(),0); }
   	void clear() { iota(all(fa),0); fill(all(siz),1); }
    int find(int x) {
    	return fa[x]==x?x:fa[x]=find(fa[x]);
    }
    bool same(int x, int y) { return find(x)==find(y); }
    bool merge(int x, int y) {// y->x
        x=find(x);
        y=find(y);
        if (x==y) return false;
        siz[x]+=siz[y];
        fa[y]=x;
        return true;
    }
    int size(int x) { return siz[find(x)]; }
};


void solve() {
	scanf("%d",&n);
	scanf("%s",t+1);	

	vector<int> pre(30,-1);
	vector<bool> vis(30,0);


	string s="";

	unite_set st(30);

	rep(i,1,n+1) {
		int c=t[i]-'a';

		if (~pre[c]) {
			printf("%c",pre[c]+'a');
		} else {
			int p=-1;
			rep(j,0,26) {
				if (!vis[j]&&j!=c&&(st.size(j)==26||!st.same(j,c))) {
					p=j;
					break;
				}
			}
			st.merge(c,p);

			// (p,c)
			vis[p]=1;
			pre[c]=p;
			printf("%c",pre[c]+'a');
		}
	}

	puts("");
}

int main() {
	int tt;
	scanf("%d",&tt);
	while (tt--) {
		solve();
	}

	return 0;
}