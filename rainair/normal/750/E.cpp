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

const int MAXN = 2e5 + 5;

struct Node{
	int a[5][5];
	Node(int x=0){CLR(a,0);}
	
	inline Node operator * (const Node &t) const {
		Node res;
		FOR(i,0,4){
			FOR(j,0,4){
				res.a[i][j] = -1e9;
				FOR(k,0,4){
					if(a[i][k] == -1e9 || t.a[k][j] == -1e9) continue;
					res.a[i][j] = std::max(res.a[i][j],a[i][k]+t.a[k][j]);
				}
			}
		}
		return res;
	}
	
	inline void print(){
		FOR(i,0,4) FOR(j,0,4) printf("%d%c",a[i][j]==-1e9?-1:a[i][j]," \n"[j==4]);
	}
}sm[MAXN<<2];
#define lc ((x)<<1)
#define rc ((x)<<1|1)
int a[MAXN],ps[MAXN];

inline void build(int x,int l,int r){
	if(l == r){
		ps[l] = x;
		FOR(i,0,4) FOR(j,0,4) sm[x].a[i][j] = -1e9;
		FOR(i,0,4) sm[x].a[i][i] = 1;
		if(a[l] == 2){
			sm[x].a[0][0] = 0;
			sm[x].a[1][0] = 1;
		}
		if(a[l] == 0){
			sm[x].a[1][1] = 0;
			sm[x].a[2][1] = 1;
		}
		if(a[l] == 1){
			sm[x].a[2][2] = 0;
			sm[x].a[3][2] = 1;
		}
		if(a[l] == 7){
			sm[x].a[3][3] = 0;
			sm[x].a[4][3] = 1;
		}
		if(a[l] == 6){
			sm[x].a[3][3] = 0;
			sm[x].a[4][4] = 0;
		}
		return;
	}
	int mid = (l + r) >> 1;
	build(lc,l,mid);build(rc,mid+1,r);
	sm[x] = sm[rc]*sm[lc];
}

inline Node query(int x,int l,int r,int L,int R){
	if(l == L && r == R) return sm[x];
	int mid = (l + r) >> 1;
	if(R <= mid) return query(lc,l,mid,L,R);
	if(L > mid) return query(rc,mid+1,r,L,R);
	return query(rc,mid+1,r,mid+1,R)*query(lc,l,mid,L,mid);
}

char str[MAXN];
int n,q;

int main(){
	scanf("%d%d",&n,&q);scanf("%s",str+1);
	FOR(i,1,n) a[i] = str[i]-'0';build(1,1,n);
	FOR(i,1,q){
		int l,r;scanf("%d%d",&l,&r);
		int ans = query(1,1,n,l,r).a[4][0];
		printf("%d\n",ans==-1e9?-1:r-l+1-ans);
	}
	return 0;
}