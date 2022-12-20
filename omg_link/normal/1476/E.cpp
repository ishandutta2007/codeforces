#include <stdio.h>
#include <queue>
#include <vector>
#define MN 100000

int n,m,k;
int p[531441];
char ss[MN+5][5];

int v(char* s){
	int r = 0;
	for(;*s;s++){
		r *= 27;
		if(*s=='_')
			r += 26;
		else
			r += *s-'a';
	}
	return r;
}

int din[MN+5],ans[MN+5];
std::vector<int> e[MN+5];

void add(int u,int v){
	if(u==v) return;
	if(v==0) return;
	e[u].push_back(v);
	din[v]++;
}

void dfsadd(int u,int w,char* s){
	if(!s[w]){
		add(u,p[v(s)]);
		return;
	}
	dfsadd(u,w+1,s);
	if(s[w]!='_'){
		char c = s[w];
		s[w] = '_';
		dfsadd(u,w+1,s);
		s[w] = c;
	}
}

bool topoSort(){
	std::queue<int> q;
	for(int i=1;i<=n;i++)
		if(din[i]==0)
			q.push(i);
	int id = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		ans[++id] = u;
		for(auto v:e[u])
			if(--din[v]==0)
				q.push(v);
	}
	return id==n;
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%s",&ss[i][0]);
		p[v(ss[i])] = i;
	}
	for(int i=1;i<=m;i++){
		static char s[5];
		static int id;
		scanf("%s%d",s,&id);
		bool flag = true;
		for(int i=0;s[i];i++){
			if(ss[id][i]=='_') continue;
			if(ss[id][i]!=s[i]) flag = false;
		}
		if(!flag){
			puts("NO");
			return 0;
		}
		dfsadd(id,0,s);
	}
	if(topoSort()){
		puts("YES");
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
	}else{
		puts("NO");
	}
}