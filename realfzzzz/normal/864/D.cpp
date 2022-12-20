#include<bits/stdc++.h>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=2e5+5;
int n,a[maxn];
int cnt[maxn];
bool f[maxn];
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) cnt[a[i]]++;
	set<int> s;
	for(int i=1;i<=n;i++) if(!cnt[i]) s.insert(i);
	printf("%d\n",(int)s.size());
	for(int i=1;i<=n;i++) if(cnt[a[i]]>1){
		int x=*s.begin();
		if(f[a[i]]||x<a[i]){
			cnt[a[i]]--;
			a[i]=x;
			s.erase(x);
		}
		else f[a[i]]=1;
	}
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}