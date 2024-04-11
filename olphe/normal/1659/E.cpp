#include "bits/stdc++.h"
using namespace std;

class UnionFind {
	vector<int>parent;
	vector<int>rank;
public:
	UnionFind(int num) {
		num++;
		parent.resize(num);
		rank.resize(num);
		for (int i = 0; i < num; i++) {
			parent[i] = i;
			rank[i] = 0;
		}
	}
	int Find(int node) {
		if (parent[node] == node)return node;
		else return parent[node] = Find(parent[node]);
	}
	void Unite(int u, int v) {
		u = Find(u);
		v = Find(v);
		if (u == v)return;
		if (rank[u] < rank[v])parent[u] = v;
		else {
			parent[v] = u;
			if (rank[u] == rank[v])rank[u]++;
		}
	}
	bool Check_Same(int u, int v) {
		return Find(u) == Find(v);
	}
};

void Solve(){
    int N,M,L,R,K;
	cin>>N>>M;
	vector<UnionFind> uf(30,UnionFind(N));
	vector<int>ok(N);
	int root=-1;
	for(int i=0;i<M;i++){
	    cin>>L>>R>>K;
	    L--,R--;
	    for(int j=0;j<30;j++){
	        if(K>>j&1){
	            uf[j].Unite(L,R);
	        }
	    }
	    if(K%2==0){
	        root=L;
	        ok[L]=ok[R]=1;
	    }
	}
	cin>>K;
	vector<int>x(K),y(K);
	for(int i=0;i<K;i++){
	    cin>>x[i]>>y[i];
	    x[i]--,y[i]--;
	}
	vector<int>ans(K,2);
	for(int i=0;i<K;i++){
	    for(int j=0;j<30;j++){
	        if(uf[j].Check_Same(x[i],y[i])){
	            ans[i]=0;
	        }
	    }
	}
	if(root!=-1){
	    for(int i=0;i<N;i++){
	        if(ok[i]){
	            for(int j=1;j<30;j++){
	                uf[j].Unite(i,root);
	            }
	        }
	    }
	    for(int i=0;i<K;i++){
	        if(ans[i]==0)continue;
	        for(int j=1;j<30;j++){
	            if(uf[j].Check_Same(x[i],root))ans[i]=1;
	        }
	    }
	}
	for(auto i:ans)cout<<i<<endl;
}

int main() {
	int T;
	T=1;
	//cin>>T;
	while(T--){
		Solve();
	}
	
	return 0;
}