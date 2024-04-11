#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <set>
#define MN 300000
typedef std::pair<int,int> pii;
int n,t[MN+5];
pii s[MN+5];
int oc,o[MN*5+5][3];
std::multiset<pii> ss;
void opt(pii &x,pii &y,int d){
	if(x.first>y.first) exit(-1);
	++oc;
	o[oc][0]=x.second,o[oc][1]=y.second,o[oc][2]=d;
	x.first+=d,y.first-=d;
	if(x.first>y.first) exit(-1);
}
pii begins(){
	auto it=ss.begin();
	pii ret=(*it);
	ss.erase(it);
	return ret;
}
pii ends(){
	auto it=ss.end();
	--it;
	pii ret=(*it);
	ss.erase(it);
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i].first);
		s[i].second=i;
	}
	std::sort(s+1,s+1+n);
	for(int i=1;i<=n;i++)
		scanf("%d",&t[i]);
	std::sort(t+1,t+1+n);
	for(int i=1,j=1;i<=n;i++){
		if(s[i].first==t[i]) continue;
		if(s[i].first>t[i]) return 0*puts("NO");
		while(s[i].first!=t[i]){
			while(j<=n&&s[j].first<=t[j]) j++;
			if(j>n||j<i) return 0*puts("NO");
			int d=std::min(t[i]-s[i].first,s[j].first-t[j]);
			opt(s[i],s[j],d);
		}
	}
	puts("YES");
	printf("%d\n",oc);
	for(int i=1;i<=oc;i++)
		printf("%d %d %d\n",o[i][0],o[i][1],o[i][2]);
}