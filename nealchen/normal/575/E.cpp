#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-'0', (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
auto rd=read<int>;
struct Point {
	int x, y;
};
const int M=1e5;
std::vector<Point> p, cop;
Point operator-(const Point &A, const Point &B) {return {A.x-B.x, A.y-B.y};}
long long times(const Point &A, const Point &B) {return 1ll*A.x*B.y-1ll*A.y*B.x;}
double abs(const Point &u) {return sqrt(1ll*u.x*u.x+1ll*u.y*u.y);}
int main() {
	int n=rd();
	for(int i=1; i<=n; ++i) {
		int x=rd(), y=rd(), v=rd();
#define P(X, Y) {auto _x=(X), _y=(Y); if(abs(_x-x)+abs(_y-y)<=v&&_x>=0&&_x<=M&&_y>=0&&_y<=M) p.push_back({_x, _y});}
		P(0, 0); P(0, M); P(M, 0); P(M, M);
		P(x-v, y); P(x, y-v); P(x, y+v); P(x+v, y);
		P(0, y+(v-x)); P(0, y-(v-x));
		P(M, y+(v-(M-x))); P(M, y-(v-(M-x)));
		P(x+(v-y), 0); P(x-(v-y), 0);
		P(x+(v-(M-y)), M); P(x-(v-(M-y)), M);
#undef P
	}
	std::sort(p.begin(), p.end(), [](auto A, auto B) {return A.x<B.x||(A.x==B.x&&A.y<B.y);});
#define SHELL(x) for(auto A: p) {while(cop.size()>x&&times(cop.back()-cop[cop.size()-2], A-cop.back())>=0) cop.pop_back(); cop.push_back(A);}
	SHELL(1);
	auto m=cop.size();
	std::reverse(p.begin(), p.end());
	SHELL(m);
	cop.pop_back();
	double mx=0;
	Point ans[3];
	m=cop.size();
	for(int i=0, j=m-1, k=m-2; i<m; k=j, j=i++) {
		auto A=cop[i], B=cop[j], C=cop[k];
		double d=abs(A-B)*abs(B-C)*abs(C-A)/abs(times(A-B, B-C));
		if(d>mx) mx=d, ans[0]=A, ans[1]=B, ans[2]=C;
	}
	for(auto P: ans) printf("%d %d\n", P.x, P.y);
	return 0;
}