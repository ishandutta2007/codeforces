#include <cstdio>
#include <algorithm>
const int N=3e5+5;
int n, t[N], sum[N];
char s[N];
bool cmax(int &a, int b) {return a<b?(a=b, 1):0;}
int main() {
	scanf("%d%s", &n, s);
	for(int i=0; i<n; ++i) {
		if(s[i]=='(') t[i]=1; else t[i]=-1;
		sum[i+1]=sum[i]+t[i];
	}
	if(sum[n]) {
		puts("0\n1 1");
		return 0;
	}
	int min=*std::min_element(sum, sum+n), nmin=0;
	for(int i=1; i<=n; ++i) nmin += sum[i]==min;
	int L, R, ans=nmin, chol=1, chor=1, cur=0;
	//min=m+1
	for(L=1; sum[L]!=min; ++L) cur += sum[L]==min+1;
	for(R=n; sum[R]!=min; --R) cur += sum[R]==min+1;
	if(R<n&&cmax(ans, cur)) chol=L, chor=R+1;
	//min=m-1
	for(int l=0, r; l<=n; l=r) {
		cur=0;
		for(r=l+1; r<=n&&sum[r]!=min; ++r);
		for(int i=l+1; i<r; ++i) cur += sum[i]==min+1;
		if(cmax(ans, cur)) chol=l+1, chor=r;
	}
	//min=m+2
	cur=nmin;
	for(L=1; sum[L]>min+1; ++L) cur += sum[L]==min+2;
	for(R=n; sum[R]>min+1; --R) cur += sum[R]==min+2;
	if(R<n&&cmax(ans, cur)) chol=L, chor=R+1;
	//min=m
	for(int l=0, r; l<=n; l=r) {
		cur=nmin;
		for(r=l+1; r<=n&&sum[r]>min+1; ++r);
		for(int i=l+1; i<r; ++i) cur += sum[i]==min+2;
		if(cmax(ans, cur)) chol=l+1, chor=r;
	}
	printf("%d\n%d %d\n", ans, chol, chor);
	return 0;
}