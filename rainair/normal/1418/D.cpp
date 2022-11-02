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
int n,q;
int p[MAXN];
std::set<int> S;
std::multiset<int> ans;

inline int query(){
	if(S.size() <= 2) return 0;
	return *S.rbegin()-*S.begin()-*ans.rbegin();
}

inline void add(int x){
	if(S.size() == 0){
		S.insert(x);return;
	}
	auto p = S.insert(x).fi;
	auto pre = p,suf=p;
	if(pre != S.begin()){
		pre--;
		ans.insert(x-*pre);
	}
	++suf;
	if(suf != S.end()){
		ans.insert(*suf-x);
	}
	if(p != S.begin() && suf != S.end()) ans.erase(ans.find(*suf-*pre));
}

inline void del(int x){
	if(S.size() <= 2){
		ans.clear();S.erase(x);
		return;
	}
	auto p = S.find(x);
	auto pre = p,suf = p;
	if(p != S.begin()){
		pre--;
		ans.erase(ans.find(x-*pre));
	}
	++suf;
	if(suf != S.end()){
		ans.erase(ans.find(*suf-x));
	}
	if(p != S.begin() && suf!= S.end()) ans.insert(*suf-*pre);
	S.erase(x);
}

int main(){
	scanf("%d%d",&n,&q);
	FOR(i,1,n) scanf("%d",p+i),add(p[i]);
	printf("%d\n",query());
	FOR(i,1,q){
		int opt,x;scanf("%d%d",&opt,&x);
		if(opt == 1) add(x);
		else del(x);
		printf("%d\n",query());
	}
	return 0;
}