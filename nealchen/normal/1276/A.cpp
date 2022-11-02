#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
inline bool cmin(auto &a, const auto &b) {return b<a?(a=b, true):false;}
inline bool cmax(auto &a, const auto &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-'0', (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
auto rd=read<int>;
const int N=1.5e5+5;
char s[N];
int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%s", s);
		int n=strlen(s);
		std::vector<int> pos;
		for(int i=0; i<n; ++i) {
			bool one=strncmp(s+i, "one", 3)==0, two=i>=2&&strncmp(s+i-2, "two", 3)==0;
			if(one&&two) pos.push_back(i);
			if(one&&!two) pos.push_back(i+1);
			if(!one&&two) pos.push_back(i-1);
		}
		printf("%d\n", (int)pos.size());
		for(int i: pos) printf("%d ", i+1);
		puts("");
	}
	return 0;
}