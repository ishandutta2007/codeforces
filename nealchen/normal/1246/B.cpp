#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-'0', (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
auto rd=read<int>;
const int N=1e5+1;
int n, k, a[N], b[N], cnt[N], mp[N], pr[N], pcnt;
int power(int a, int b) {
	int ans=1;
	for(; b; a*=a, b>>=1) if(b&1) ans*=a;
	return ans;
}
int main() {
	n=rd(), k=rd();
	std::generate(a, a+n, rd);
	int max=*std::max_element(a, a+n);
	for(int i=2; i<=max; ++i) {
		if(!mp[i]) pr[pcnt++]=mp[i]=i;
		for(int j=0; j<pcnt&&pr[j]<=max/i; ++j) {
			mp[i*pr[j]]=pr[j];
			if(i%pr[j]==0) break;
		}
	}
	long long ans=0;
	for(int i=0; i<n; ++i) {
		int m=a[i], b=1;
		long double ln=0;
		a[i]=1;
		while(m!=1) {
			int p=mp[m], id=0;
			for(; m%p==0; m/=p) ++id;
			a[i]*=power(p, id%=k);
			if(id) id=k-id;
			ln+=id*log(p);
			b*=power(p, id);
		}
		if(ln<=log(max)+1&&b<=max) ans+=cnt[b];
		++cnt[a[i]];
	}
	printf("%lld\n", ans);
	return 0;
}