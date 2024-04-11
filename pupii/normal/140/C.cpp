#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
int r[100010],A[100010],B[100010],C[100010];
std::unordered_map<int,int>M;
std::set<std::pair<int,int>>s;
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int m=0,n=gi();
	for(int i=1;i<=n;++i)++M[r[i]=gi()];
	for(auto[x,y]:M)
		s.insert({y,x});
	while(s.size()>2){
		auto a=*s.rbegin(),b=*++s.rbegin(),c=*++++s.rbegin();
		++m,A[m]=a.second,B[m]=b.second,C[m]=c.second;
		s.erase(a),s.erase(b),s.erase(c);
		if(a.first>1)s.insert({a.first-1,a.second});
		if(b.first>1)s.insert({b.first-1,b.second});
		if(c.first>1)s.insert({c.first-1,c.second});
	}
	printf("%d\n",m);
	for(int i=1;i<=m;++i){
		int a=std::min(std::min(A[i],B[i]),C[i]);
		int c=std::max(std::max(A[i],B[i]),C[i]);
		printf("%d %d %d\n",c,A[i]+B[i]+C[i]-a-c,a);
	}
	return 0;
}