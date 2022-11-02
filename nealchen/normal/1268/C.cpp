#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
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
auto rd=read<int>;
const int N=2e5+5, S=1<<19;
int n, a[N], bit[N], cnt[S];
long long f[N], sum[S];
std::priority_queue<int> lo;
std::priority_queue<int, std::vector<int>, std::greater<int>> hi;
void increase(int o, int l, int r, int v) {
	if(l==r) {
		++cnt[o];
		sum[o]+=v;
	} else {
		int mid=(l+r)/2;
		if(v<=mid) increase(o<<1, l, mid, v); else increase(o<<1|1, mid+1, r, v);
		cnt[o]=cnt[o<<1]+cnt[o<<1|1];
		sum[o]=sum[o<<1]+sum[o<<1|1];
	}
}
int rem=0;
long long query(int o, int l, int r) {
	if(rem==0) return 0;
	if(rem>=cnt[o]) {
		rem-=cnt[o];
		return sum[o];
	}
	int mid=(l+r)/2;
	long long L=query(o<<1, l, mid);
	long long R=query(o<<1|1, mid+1, r);
	return L+R;
}
long long q(int arg) {
	rem=arg;
	return query(1, 1, n);
}
int main() {
	n=rd();
	for(int i=1; i<=n; ++i) a[rd()]=i;
	for(int i=1; i<=n; ++i) {
		f[i]=f[i-1];
		for(int j=a[i]; j<=n; j+=j&-j) f[i]+=bit[j];
		for(int j=a[i]; j; j&=j-1) ++bit[j];
	}
	for(int i=1; i<=n; ++i) {
		if(i==1) {
			hi.push(a[1]);
		} else {
			if(a[i]<=hi.top()) {
				lo.push(a[i]);
				while(lo.size()>hi.size()) {
					hi.push(lo.top());
					lo.pop();
				}
			} else {
				hi.push(a[i]);
				while(hi.size()>lo.size()+1) {
					lo.push(hi.top());
					hi.pop();
				}
			}
		}
		int l=i/2, r=(i-1)/2, m=hi.top();
		increase(1, 1, n, a[i]);
		rem=l;
		f[i]+=sum[1]-q(l+1)-q(l)+(m+m-l-1ll)*l/2-(m+m+r+1ll)*r/2;
	}
	for(int i=1; i<=n; ++i) std::cout<<f[i]<<" \n"[i==n];
	return 0;
}