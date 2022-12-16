#include <stdio.h>
#include <vector>
#define MN 200000

int n,fib[30];
bool ban[MN+5];
std::vector<int> e[MN+5];

void add(int u,int v){
	e[u].push_back(v);
}

bool check(int,int);

int dfs(int u,int f,int s){
	int sz = 1;
	int cnt = 0;
	for(auto v:e[u]){
		if(v==f) continue;
		if(ban[v]) continue;
		if(++cnt>=s) throw false;
		int r = dfs(v,u,s);
		if(r==fib[s-1]){
			ban[u] = true;
			if(check(v,s-1)){
				ban[u] = false;
				ban[v] = true;
				if(check(u,s-2)){
					ban[v] = false;
					throw true;
				}else{
					ban[v] = false;
					throw false;
				}
			}else{
				ban[u] = false;
				throw false;
			}
		}
		if(r==fib[s-2]){
			ban[u] = true;
			if(check(v,s-2)){
				ban[u] = false;
				ban[v] = true;
				if(check(u,s-1)){
					ban[v] = false;
					throw true;
				}else{
					ban[v] = false;
					throw false;
				}
			}else{
				ban[u] = false;
				throw false;
			}
		}
		sz += r;
	}
	return sz;
}

bool check(int u,int s){
	if(fib[s]<=3) return true;
	try{
		dfs(u,0,s);
		return false;
	}catch(bool res){
		return res;
	}
}

int main(){
	fib[0] = fib[1] = 1;
	for(int i=2;i<30;i++)
		fib[i] = fib[i-1]+fib[i-2];
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v),add(v,u);
	}
	int s;
	for(int i=29;i>=0;i--){
		if(fib[i]==n){
			s = i;
			break;
		}
		if(i==0){
			puts("NO");
			return 0;
		}
	}
	puts(check(1,s)?"YES":"NO");
	return 0;
}