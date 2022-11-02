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
int (*rd)()=read<int>;
const int N=5e6+5;
int n, k, z[N<<1], d[N], dlen[N];
char s[N<<1], ans[N], cur[N];
int main() {
	assert(scanf("%s%d", s, &k)==2);
	n=strlen(s);
	s[n]='#';
	std::reverse(s, s+n);
	std::reverse_copy(s, s+n, s+n+1);
	for(int i=1, j, mx=0; i<=2*n; ++i) {
		z[i]=i<mx?std::min(z[i-j], mx-i):0;
		while(s[z[i]]==s[i+z[i]]) ++z[i];
		if(cmax(mx, i+z[i])) j=i;
	}
	int tot=0;
	for(int i=0; i<n; ) {
		int j=i, k=i+1;
		for(; k<n&&s[j]<=s[k]; ++k) j = s[j]<s[k]?i:j+1;
		d[tot]=i, dlen[tot]=k-j, ++tot;
		while(i<=j) i+=k-j;
	}
	int l=n;
	while(k>2&&tot) {
		--tot;
		memcpy(ans+n-l, s+d[tot], l-d[tot]);
		l=d[tot];
		if(tot==0||dlen[tot]!=1||dlen[tot-1]!=1) --k;
	}
	if(tot<2||k==1) {
		int beg=2*n-l+1, lcp=z[beg];
		memcpy(ans+n-l, s[lcp]<s[beg+lcp]?s:s+beg, l);
	} else {
		strcpy(cur, ans);
		//reverse none
		strcpy(ans+n-l, s+2*n+1-l);
		//reverse former
		int cho=0;
		d[tot]=l;
		for(cho=tot; --cho>=0&&strncmp(s+d[cho+1], s+d[cho], l-d[cho+1])==0; )
			if(strncmp(s+d[cho]+l-d[cho+1], s+2*n+1-d[cho+1], d[cho+1]-d[cho])>0) break;
		++cho;
		memcpy(cur+n-l, s+d[cho], l-d[cho]);
		memcpy(cur+n-d[cho], s+2*n+1-d[cho], d[cho]);
		if(strcmp(cur, ans)<0) strcpy(ans, cur);
		//reverse latter
		cho=0;
		for(int i=1; i<l; ++i) {
			int p=z[2*n+1-i], q=z[i-cho];
			if(p>=i-cho?(q<cho&&s[i-cho+q]<s[q]):(s[p]<s[2*n+1-i+p])) cho=i;
		}
		memcpy(cur+n-l, s+2*n+1-l, l-cho);
		memcpy(cur+n-cho, s, cho);
		if(strcmp(cur, ans)<0) strcpy(ans, cur);
		//reverse both
		cho=0;
		for(int i=1, j=0; cho<l&&i<l&&j<l; ) {
			int t=s[(cho+j)%l]-s[(i+j)%l];
			if(t==0) ++j; else (t<0?i:cho)+=j+1, j=0;
			if(i<cho) std::swap(i, cho);
			i+=(i==cho);
		}
		memcpy(cur+n-l, s+cho, l-cho);
		memcpy(cur+n-cho, s, cho);
		if(strcmp(cur, ans)<0) strcpy(ans, cur);
	}
	puts(ans);
	return 0;
}