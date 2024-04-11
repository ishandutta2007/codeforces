#include<bits/stdc++.h>
using namespace std;
const int maxn=100010,mod=998244353;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,fa[maxn],dep[maxn],last=1,chg,ans[maxn],al,seq[maxn],sl;
set<int> s[maxn];
int main(){
	n=read();
	FOR(i,2,n){
		dep[i]=dep[fa[i]=read()+1]+1;
		s[fa[i]].insert(i);
		if(dep[i]>dep[last]) last=i;
	}
	chg=last;
	while(chg!=1){
		int i=chg;
		for(int fl=0;i!=1 && (i!=chg || !fl);i=fa[i],fl=1);
		assert(i!=chg);
		while(chg!=1 && s[fa[chg]].size()==1) chg=fa[chg];
		if(chg!=1){
			int was=fa[chg];
			set<int>::iterator hhh=s[was].find(chg);
			for(set<int>::iterator it=s[was].begin();it!=s[was].end();it++){
				int f=*it;
				if(f==chg) continue;
				s[f].insert(chg);
				fa[chg]=f;
				ans[++al]=chg-1;
				s[was].erase(hhh);
				break;
			}
		}
	}
	for(int i=last;i;i=fa[i]) seq[++sl]=i-1;
	ROF(i,n,1) printf("%d ",seq[i]);
	printf("\n%d\n",al);
	ROF(i,al,1) printf("%d ",ans[i]);
}
// orz pb