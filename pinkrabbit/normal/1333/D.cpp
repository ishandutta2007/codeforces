#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 10005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,k,c,d;char s[MN];
vector<int>V[MN];
int main(){
	scanf("%d%d%s",&n,&k,s+1);
	while(1){
		int ok=0;
		F(i,1,n-1)if(s[i]=='R'&&s[i+1]=='L'){c+=!ok,ok=1;V[c].pb(i);swap(s[i],s[i+1]),++d;++i;}
		if(!ok)break;
	}
//	F(i,1,c){for(int x:V[i])printf("%d,",x);puts("");}
	if(k>d)return puts("-1"),0;
	if(k<c)return puts("-1"),0;
	F(i,1,c){
		while(!V[i].empty()&&k>c-i+1)printf("1 %d\n",V[i].back()),--k,V[i].pop_back();
		if(!V[i].empty()){
			--k;
			printf("%d",(int)V[i].size());
			for(int x:V[i])printf(" %d",x);
			puts("");
		}
	}
	return 0;
}