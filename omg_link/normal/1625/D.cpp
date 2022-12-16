#include <stdio.h>
#include <algorithm>
#include <vector>
#define MN 300000

using std::sort;
using std::vector;

struct Spider{
	int a,id;
}sp[MN+5];

int n,k;
vector<int> ans;

struct Trie{
	struct Node{
		int ch[2];
	}T[MN*30+5];
	
	int root,nodeCnt;
	
	int getNode(){
		++nodeCnt;
		T[nodeCnt] = {0,0};
		return nodeCnt;
	}
	
	void reset(){
		nodeCnt = 0;
		root = 0;
	}
	
	void insert(int& u,int w,int v,int id){
		if(u==0) u = getNode();
		if(w==-1){
			T[u].ch[0] = id;
			T[u].ch[1] = v;
			return;
		}
		insert(T[u].ch[(v>>w)&1],w-1,v,id);
	}
	
	int find(int u,int w,int v){
		if(w==-1){
			if((T[u].ch[1]^v)>=k){
				return T[u].ch[0];
			}else{
				return -1;
			}
		}
		if(T[u].ch[((v>>w)&1)^1]){
			return find(T[u].ch[((v>>w)&1)^1],w-1,v);
		}else{
			return find(T[u].ch[(v>>w)&1],w-1,v);
		}
	}
	
}trie;

void solve(vector<Spider> sp){
	trie.reset();
	for(Spider spider:sp){
		trie.insert(trie.root,29,spider.a,spider.id);
	}
	for(Spider spider:sp){
		int id = trie.find(trie.root,29,spider.a);
		if(id!=-1){
			ans.push_back(id);
			ans.push_back(spider.id);
			return;
		}
	}
	ans.push_back(sp[0].id);
	return;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&sp[i].a);
		sp[i].id = i;
	}
	if(k==0){
		printf("%d\n",n);
		for(int i=1;i<=n;i++)
			printf("%d%c",i," \n"[i==n]);
		return 0;
	}
	int lim = 1;
	while(lim<=k) lim <<= 1;
	sort(sp+1,sp+1+n,[](Spider a,Spider b)->bool{
		return a.a < b.a;
	});
	for(int i=1;i<=n;i++){
		vector<Spider> v;
		int l = i;
		int r = i;
		while(r+1<=n&&sp[r+1].a/lim==sp[i].a/lim){
			r++;
		}
		for(int j=l;j<=r;j++){
			v.push_back({sp[j].a&(lim-1),sp[j].id});
		}
		solve(v);
		i = r;
	}
	if(ans.size()==1){
		puts("-1");
	}else{
		printf("%d\n",(int)ans.size());
		for(int x:ans){
			printf("%d ",x);
		}
		puts("");
	}
}