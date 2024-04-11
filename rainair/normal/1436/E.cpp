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

const int MAXN = 1e5 + 5;
int n,a[MAXN];

struct Node{
    int l,r,c;
    Node(int l=0,int r=0,int c=0) : l(l),r(r),c(c) {}

    inline bool operator < (const Node &t) const {
        return l < t.l || (l == t.l && r < t.r);
    }
};
std::set<Node> S;
int cnt[MAXN],t = 1;
bool vis[MAXN];

inline void add(int x){
    cnt[x]++;
    while(cnt[t]) ++t;
}

int suf[MAXN],val[MAXN],lst[MAXN];

inline int calc(int x){
    auto p = S.upper_bound(Node(x,1e9));--p;
    return p->c;
}

inline void cover(int l,int r,int c){
    vis[c] = 1;
	auto p = S.upper_bound(Node(l,-1));--p;
	if(p->l != l){
		int ll = p->l,rr = p->r,c = p->c;
		S.erase(Node(ll,rr,c));
		S.insert(Node(ll,l-1,c));
		p = S.insert(Node(l,rr,c)).fi;
	}
	while(p->r <= r){
		auto las = p;
		p++;S.erase(las);
	}
	if(p->l <= r && p->r > r){
		int ll = p->l,rr = p->r,c = p->c;
		S.erase(Node(ll,rr,c));
		p = S.insert(Node(ll,r,c)).fi;
		S.insert(Node(r+1,rr,c));
	}
	if(p->l <= r){
		S.erase(p);
	}
	S.insert(Node(l,r,c));
}

int main(){
    S.insert(Node(-1e9,-1e9));S.insert(Node(1e9,1e9));
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),lst[i] = n+1;
    ROF(i,n,1) suf[i] = lst[a[i]],lst[a[i]] = i;
    FOR(i,1,n){
        add(a[i]);val[i] = t;vis[t] = 1;
        S.insert(Node(i,i,val[i]));
    }
    FOR(i,1,n){
        int l = i+1,r = suf[i]-1,ans = -1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(calc(mid) >= a[i]) ans = mid,r = mid-1;
            else l = mid+1;
        }
//        if(i == 2){
//            for(auto x:S) printf("%d %d %d\n",x.l,x.r,x.c);
//        }
        if(ans != -1 && ans <= suf[i]-1){
//            printf("%d %d %d\n",ans,suf[i]-1,a[i]);
            cover(ans,suf[i]-1,a[i]);
        }
    }
    FOR(i,1,n+23){
        if(!vis[i]){
            printf("%d\n",i);
            exit(0);
        }
    }
    return 0;
}