// LUOGU_RID: 93499072
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=5e3+5,maxs=(1<<20)+5;
int n,a,b,m=0;
char s[maxn];
int l[26],r[26],cnt[26],ord[26];
bool f[maxs];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	a=read();
	b=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		int c=s[i]-'a';
		if(!l[c]) l[c]=i;
		r[c]=i;
		cnt[c]++;
	}
	for(int i=0;i<26;i++) if(r[i]) ord[m++]=i;
	sort(ord,ord+m,[](int a,int b){
		return r[a]<r[b];
	});
	f[0]=1;
	for(int i=1;i<(1<<m);i++){
		int l2=n+1,r2=0,s=0,c=0;
		for(int j=0;j<m;j++) if(i>>j&1){
			l2=min(l2,l[ord[j]]);
			r2=r[ord[j]];
			s|=1<<j;
			c+=cnt[ord[j]];
			if(s!=i) f[i]|=f[s]&&f[i^s];
		}
		if((r2-l2+1)*a<=c*b)
			for(int j=0;j<m;j++)
				if(i>>j&1) f[i]|=f[i^(1<<j)];
	}
	vector<int> ans;
	for(int i=0;i<m;i++)
		if(f[((1<<m)-1)^(1<<i)]) ans.push_back(ord[i]);
	sort(ans.begin(),ans.end());
	printf("%d ",(int)ans.size());
	for(int i:ans) printf("%c ",i+'a');
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}