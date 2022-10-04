#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
typedef long long LL;
typedef double ld;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;

map<int,int> mp;
set<int> st;

int n,q,m,k;
int a[300005],b[300005];
int M[3005][3005];
char str[300005];

int main(){
	scanf("%d",&n);
	F2(i,0,n) scanf("%d",a+i);
	int ok=0;
	F2(S,0,1<<n){
		int s=0;
		F2(i,0,n)s+=(S>>i&1)?a[i]:-a[i];
		if(s%360==0)ok=1;
	}
	puts(ok?"YES":"NO");
	return 0;
}