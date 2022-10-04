#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define dF2(i,a,b) for(int i=a;i>(b);--i)
typedef long long LL;
const int INF=0x3f3f3f3f;

map<int,int> mp;
set<int> st;

int n,q,m,k;
int a[500005],c[500005];
char str[500005];

int main(){
	scanf("%d",&n);
	F(i,1,n){
		scanf("%s",str);
		k=strlen(str);
		int o=0,b=0;
		F2(j,0,k){
			if(str[j]=='(') ++o;
			else if(o) --o; else ++b;
		}
		if(o&&b) continue;
		if(o)a[o]++;
		else if(b)c[b]++;
		else m++;
	} m/=2;
	F(i,1,500000) m+=min(a[i],c[i]);
	printf("%d\n",m);
	return 0;
}