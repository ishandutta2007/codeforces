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
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	printf("YES\n");
	int l,r;
	l=readint();
	r=readint();
	vector<pair<int,int>> g[30];
	if(l>1) g[1].push_back({2,l-1});
	for(int i=0;i<=19;i++){
		g[1+(l>1)].push_back({i+2+(l>1),1});
		for(int j=0;j<i;j++)
			g[j+2+(l>1)].push_back({i+2+(l>1),1<<j});
	}
	int res=1;
	g[1+(l>1)].push_back({22+(l>1),1});
	for(int i=0;i<=19;i++) if((r-l)>>i&1){
		g[i+2+(l>1)].push_back({22+(l>1),res});
		res+=1<<i;
	}
	int m=0;
	for(int i=1;i<30;i++) m+=g[i].size();
	printf("%d %d\n",22+(l>1),m);
	for(int i=1;i<30;i++) for(auto j:g[i])
		printf("%d %d %d\n",i,j.first,j.second);
	return 0;
}