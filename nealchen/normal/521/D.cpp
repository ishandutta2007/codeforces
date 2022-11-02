#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-48, (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-48)<=9; a=a*10+c);
	return b?-a:a;
}
int (*rd)()=read<int>;

const int N=1e5+1;
int t[N], id[N], b[N], set[N], setcho[N], cho[N], off, res[N];
long long a[N];
long double effect[1<<17], *zkw[1<<18], delta[N];
std::vector<int> inc[N], mul;
bool cmp(int x, int y) {return b[x]<b[y];}
void getchoice(int x) {
	if(inc[x].empty()) {
		effect[x]=0;
	} else {
		int i=inc[x].back();
		inc[x].pop_back();
		cho[x]=i;
		effect[x]=1.0l*(a[x]+b[i])/a[x];
	}
	for(x|=off; x>>=1; ) zkw[x]=zkw[2*x+(*zkw[2*x]<*zkw[2*x+1])];
}
int main() {
	int k=rd(), n=rd(), m=rd();
	for(int i=1; i<=k; ++i) a[i]=set[i]=rd();
	for(int i=1; i<=n; ++i) {
		t[i]=rd(), id[i]=rd(), b[i]=rd();
		if(t[i]==1&&cmax(set[id[i]], b[i])) setcho[id[i]]=i;
		if(t[i]==2) inc[id[i]].push_back(i);
		if(t[i]==3) mul.push_back(i);
	}
	for(int i=1; i<=k; ++i) {
		if(set[i]>a[i]) {
			int j=setcho[i];
			b[j]=set[i]-a[i];
			inc[i].push_back(j);
		}
		std::sort(inc[i].begin(), inc[i].end(), cmp);
	}
	std::sort(mul.begin(), mul.end(), cmp);
	for(off=1; off<=k; off*=2);
	for(int i=0; i<off; ++i) zkw[off+i]=effect+i;
	for(int i=off; --i; ) zkw[i]=zkw[2*i];
	for(int i=1; i<=k; ++i) getchoice(i);
	int cnt=0;
	while(cnt<m&&*zkw[1]>1) {
		int i=zkw[1]-effect;
		res[cnt]=cho[i];
		delta[cnt]=effect[i];
		++cnt;
		a[i]+=b[cho[i]];
		getchoice(i);
	}
	int pos=cnt;
	while(cnt<m&&!mul.empty()) {
		int i=mul.back();
		mul.pop_back();
		res[cnt]=i;
		delta[cnt]=b[i];
		++cnt;
	}
	while(pos>0&&!mul.empty()&&b[mul.back()]>delta[pos-1]) {
		res[--pos]=mul.back();
		mul.pop_back();
	}
	std::sort(res, res+cnt, [](int x, int y) {return t[x]<t[y];});
	printf("%d\n", cnt);
	for(int i=0; i<cnt; ++i) printf("%d%c", res[i], " \n"[i==cnt-1]);
	return 0;
}