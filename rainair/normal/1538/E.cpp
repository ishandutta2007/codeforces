#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

inline bool chk(char a,char b,char c,char d){
	return a == 'h' && b == 'a' && c == 'h' && d == 'a';
}

inline int gao(std::string str){
	int res = 0;
	FOR(i,0,SZ(str)-4){
		res += chk(str[i],str[i+1],str[i+2],str[i+3]);
	}
	return res;
}

struct Node{
	std::string pre,suf;LL sm;
	Node(char c=0){pre.resize(1);suf.resize(1);pre[0] = suf[0] = c;sm = 0;}

	Node operator + (const Node &t) const {
		Node res;res.pre = pre;res.suf = t.suf;
		res.sm = sm+t.sm+gao(suf+t.pre);
		if(SZ(res.pre) < 3){
			res.pre += t.pre;
			if(SZ(res.pre) > 3) res.pre.resize(3);
		}
		if(SZ(res.suf) < 3){
			res.suf = suf+res.suf;
			while(SZ(res.suf) > 3) res.suf.erase(res.suf.begin());
		}
		return res;
	}
}a[12345];

std::map<std::string,int> S;

inline int getid(std::string str){
	if(!S.count(str)) S[str] = SZ(S)+1;
	return S[str];
}

inline void Solve(){
	S.clear();int q;scanf("%d",&q);int v;
	FOR(i,1,q){
		std::string str,opt;
		std::cin >> str >> opt;v = getid(str);
		if(opt == ":="){
			std::cin >> str;
			a[v] = Node(str[0]);
			FOR(i,1,SZ(str)-1) a[v] = a[v]+Node(str[i]);
		}
		else{
			std::string s1,s2;
			std::cin >> s1 >> s2 >> s2;
			a[v] = a[getid(s1)]+a[getid(s2)];
		}
	}
	printf("%lld\n",a[v].sm);
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}