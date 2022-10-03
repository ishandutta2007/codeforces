#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 200005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,m,q,k;
char s[MN];
int a[26][MN];
int main(){
	scanf("%s",s+1),n=strlen(s+1);
	F(i,1,n){
		F(j,0,25)a[j][i]=a[j][i-1];
		++a[s[i]-'a'][i];
	}
	scanf("%d",&q);
	F(_,1,q){
		int l,r;
		scanf("%d%d",&l,&r);
		if(l==r){puts("Yes");continue;}
		int cnt=0;
		F(j,0,25)if(a[j][r]-a[j][l-1]>0)++cnt;
		if(cnt==1){puts("No");continue;}
		if(cnt>=3){puts("Yes");continue;}
		if(s[l]==s[r]){puts("No");continue;}
		else {puts("Yes");continue;}
	}
	return 0;
}