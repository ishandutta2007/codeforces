#include <cstdio>
#include <vector>
#include <algorithm>
const int Maxn=(1<<19);
const int Maxk=19;
const int Inf=0x3f3f3f3f;
int n,k;
struct Trie_Node{
	int ch[2];
}node[Maxn*Maxk+5];
int id_tot=1;
void insert(int x){
	int root=1;
	for(int i=k-1;i>=0;i--){
		if(node[root].ch[(x>>i)&1]==0){
			node[root].ch[(x>>i)&1]=++id_tot;
		}
		root=node[root].ch[(x>>i)&1];
	}
}
struct Value{
	int min_val;
	int l_val,r_val;
	Value(int _min_val=Inf,int _l_val=Inf,int _r_val=-Inf){
		min_val=_min_val,l_val=_l_val,r_val=_r_val;
	}
};
std::vector<Value> solve(int u,int dep=k){
	if(u==0){
		std::vector<Value> ans;
		ans.resize(1<<dep);
		for(int i=0;i<(1<<dep);i++){
			ans[i]=Value();
		}
		return ans;
	}
	if(dep==0){
		std::vector<Value> ans;
		ans.push_back(Value(Inf,0,0));
		return ans;
	}
	std::vector<Value> l_ans,r_ans,ans;
	l_ans=solve(node[u].ch[0],dep-1),r_ans=solve(node[u].ch[1],dep-1);
	ans.resize(1<<dep);
	for(int i=0;i<(1<<(dep-1));i++){
		if(l_ans[i].l_val!=Inf&&r_ans[i].l_val!=Inf){
			ans[i].min_val=std::min(l_ans[i].min_val,r_ans[i].min_val);
			ans[i].min_val=std::min(ans[i].min_val,(r_ans[i].l_val|(1<<(dep-1)))-l_ans[i].r_val);
			ans[i].r_val=r_ans[i].r_val|(1<<(dep-1));
			ans[i].l_val=l_ans[i].l_val;
		}
		else if(l_ans[i].l_val==Inf){
			ans[i]=r_ans[i];
			ans[i].l_val|=(1<<(dep-1));
			ans[i].r_val|=(1<<(dep-1));
		}
		else{
			ans[i]=l_ans[i];
		}
	}
	for(int i=(1<<(dep-1));i<(1<<dep);i++){
		int j=i-(1<<(dep-1));
		if(l_ans[j].l_val!=Inf&&r_ans[j].l_val!=Inf){
			ans[i].min_val=std::min(l_ans[j].min_val,r_ans[j].min_val);
			ans[i].min_val=std::min(ans[i].min_val,(l_ans[j].l_val|(1<<(dep-1)))-r_ans[j].r_val);
			ans[i].l_val=r_ans[j].l_val;
			ans[i].r_val=l_ans[j].r_val|(1<<(dep-1));
		}
		else if(l_ans[j].l_val==Inf){
			ans[i]=r_ans[j];
		}
		else{
			ans[i]=l_ans[j];
			ans[i].l_val|=(1<<(dep-1));
			ans[i].r_val|=(1<<(dep-1));
		}
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		insert(a);
	}
	std::vector<Value> ans=solve(1);
	for(int i=0;i<(int)ans.size();i++){
		printf("%d ",ans[i].min_val);
	}
	puts("");
	return 0;
}