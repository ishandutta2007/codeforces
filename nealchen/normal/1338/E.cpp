#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
namespace Input {
	const int N=1<<20;
	char b[N], *s=b, *t=b;
	int getchar() {
		if(s!=t) return *s++;
		s=b;
		t=b+fread(b, 1, N, stdin);
		return s==t?EOF:*s++;
	}
}
const int N=8000;
const char rev[]={0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
int n, m, ideg[N];
bool del[N];
unsigned e[N][N/32];
long long ans=0;
std::vector<int> v[2];
int rd() {
	int a=0;
	unsigned char c;
	while((c=Input::getchar()-48)>9);
	while(a=a*10+c, (c=Input::getchar()-48)<=9);
	return a;
}
int hex() {
	char c;
	while((c=Input::getchar())<32);
	return c<=57?c-48:c-55;
}
bool test(unsigned *s, int i) {
	return s[i/32]>>i%32&1;
}
int main() {
	n=m=rd();
	for(int i=0; i<n; ++i) {
		for(int j=0; j<n/4; ++j)
			e[i][j/8]|=1u*rev[hex()]<<j%8*4;
		ideg[i]=n-1;
		for(int j=0; j*32<n; ++j)
			ideg[i]-=__builtin_popcount(e[i][j]);
	}
	while(true) {
		int u=-1;
		for(int i=0; i<n; ++i) {
			if(ideg[i]==0&&!del[i]) u=i;
		}
		if(u==-1) break;
		del[u]=true;
		for(int i=0; i<n; ++i)
			ideg[i]-=test(e[u], i);
		--m;
		ans+=(614ll*n+1)*m;
	}
	int max=0, x;
	for(int i=0; i<n; ++i) {
		if(ideg[i]>max) {
			max=ideg[i];
			x=i;
		}
	}
	for(int i=0; i<n; ++i) {
		if(!del[i]) v[test(e[x], i)].push_back(i);
	}
	std::sort(v[0].begin(), v[0].end(), [](int u, int v) {return test(e[v], u);});
	std::sort(v[1].begin(), v[1].end(), [](int u, int v) {return test(e[v], u);});
	ans+=3*v[0].size()*v[1].size();
	for(int i=0; i<2; ++i) {
		for(int j=0; j<v[i].size(); ++j) {
			ans+=2*v[i].size()-j-2;
			for(int k=j+1; k<v[i].size(); ++k)
				ans+=ideg[v[i][j]]+j==ideg[v[i][k]]+k;
		}
	}
	printf("%lld\n", ans);
	return 0;
}