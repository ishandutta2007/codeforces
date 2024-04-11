#include<bits/stdc++.h>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)

typedef double db;
typedef long long ll;

const int N=2e5+50;
int a[N];
char str[N];
int b[N];
int c[N];
int main() {
	int n;
	scanf("%d",&n);
	FOR(i,1,n) scanf("%d",&a[i]);
	scanf("%s",str+1);
	sort(a+1,a+n+1);
	FOR(i,1,n) {
		if(str[i]!=str[i-1]) {
			b[i]=1;
		}
	}
	int l=1,r=n;
	DOR(i,n,1) {
		if(b[i]==1) c[i]=a[r--];
		else c[i]=a[l++];
	}
	int c1=0,c2=0;
	FOR(i,1,n) {
		if(str[i]=='L') {
			if(c1<=c2) {
				++c1;
				printf("%d L\n",c[i]);
			} else {
				++c2;
				printf("%d R\n",c[i]);
			}
		} else {
			if(c1>=c2) {
				++c2;
				printf("%d R\n",c[i]);
			} else {
				++c1;
				printf("%d L\n",c[i]);
			}
		}
	}
	return 0;
}