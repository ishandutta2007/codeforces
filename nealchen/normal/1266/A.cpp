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
char s[114];
int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		scanf("%s", s);
		int m=strlen(s), s3=0, n0=0, n2=0;
		for(int i=0; i<m; ++i) {
			s[i]-='0';
			s3+=s[i]%3;
			n0+=(s[i]==0);
			n2+=(s[i]%2==0);
		}
		if(s3%3==0&&n0&&(m==1||n2>1)) puts("red"); else puts("cyan");
	}
	return 0;
}