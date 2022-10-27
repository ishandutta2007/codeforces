#include<iostream>
#include<cstdio>
#include<vector>
#include<bitset>
using namespace std;
int n,m,x,h,s1,s2;
int s[100005];
vector<int> son[100001];
bitset<100001> f,g,tp;
int ans[100001],p[100001];
char qwq[100001];
inline void dfs(int i,int d){
	s[d]++,h=max(h,d);
	for(int j:son[i]) dfs(j,d+1);
}
inline void getans(int i,int d){
	if(ans[d]) qwq[i]='a'+(ans[d]==1);
	for(int j:son[i]) getans(j,d+1);
}
int main(){
	cin>>n>>m;
	for(int i=2;i<=n;i++){
		cin>>x;
		son[x].push_back(i);
	}
	dfs(1,1);
	f[0]=1;
	for(int i=1;i<=h;i++){
		tp=f<<s[i];
		g=(~f)&tp,f|=tp;
		while(g.any()){
			int pos=g._Find_first();
			g[pos]=0,p[pos]=i;
		}
	}
	if(!f[m]){
		cout<<h+1<<endl;
		s1=m,s2=n-m;
		for(int i=1;i<=h;i++){
			if(s1>=s[i]) s1-=s[i],ans[i]=-1;
			else if(s2>=s[i]) s2-=s[i],ans[i]=1;
			else{
				for(int j=i+2;j<=h;j++){
					if(s1>=s[j]) s1-=s[j],ans[j]=-1;
					else s2-=s[j],ans[j]=1;
				}
				s1-=s[i+1],ans[i+1]=-1;
				getans(1,1);
				for(int j=1;j<=n;j++)
					if(!qwq[j]&&son[j].size()) s2--,qwq[j]='b';
				for(int j=1;j<=n;j++)
					if(!qwq[j]){
						if(s1) s1--,qwq[j]='a';
						else s2--,qwq[j]='b';
					}
				break;
			}
		}
	}
	else{
		cout<<h<<endl;
		for(int i=m;i;i-=s[p[i]]) ans[p[i]]=-1;
		for(int i=1;i<=h;i++) if(!ans[i]) ans[i]=1;
		getans(1,1);
	}
	for(int i=1;i<=n;i++) putchar(qwq[i]);
}