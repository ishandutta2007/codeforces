#include <cstdio>
#include <vector>
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar(), c-'0'>9&c!='-');
	for(a=(b=c=='-')?0:c-'0'; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
int main() {
	int (*rd)()=read<int>, n=rd();
	long long ans=0;
	std::vector<int> v;
	for(int i=0; i<n; ++i) {
		int a=rd(), b=rd(), c=rd(), d=rd();
		if(a+b>=c+d) {
			ans+=a+c;
			v.push_back(a+b);
			v.push_back(c+d);
		} else {
			if(a>d) ans+=a-d;
			if(b>c) ans-=b-c;
		}
	}
	std::sort(v.begin(), v.end(), std::greater<int>());
	for(size_t i=1; i<v.size(); i+=2) ans-=v[i];
	std::cout<<ans<<std::endl;
	return 0;
}