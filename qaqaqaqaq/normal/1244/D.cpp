#include<bits/stdc++.h>
using namespace std;
 
const int maxn=100007;
vector<int> e[maxn],vec;
int mp[5],perm[5],n,col[maxn],val[maxn][3];
long long maxv=1e15;
 
long long get_ans(int u,int dep){
	col[u]=perm[dep%3]+1;
	if (u==vec[1]) return val[u][col[u]-1];
	if (col[e[u][0]]){
		return val[u][col[u]-1]+get_ans(e[u][1],dep+1);
	}
	else{
		return val[u][col[u]-1]+get_ans(e[u][0],dep+1);
	}
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=0;i<3;++i){
		for (int j=1;j<=n;++j){
			cin>>val[j][i];
		}
	}
	for (int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i=1;i<=n;++i){
		if (e[i].size()>=3){
			cout<<-1<<endl;
			return 0;
		}
		if (e[i].size()==1){
			vec.push_back(i);	
		}
	} 
	for (int i=0;i<3;++i){
		perm[i]=i;
	}
	do{
		memset(col,0,sizeof(col));
		long long tmp=get_ans(vec[0],0);
		if (tmp<maxv){
			maxv=tmp;
			for (int i=0;i<3;++i){
				mp[i]=perm[i];
			}
		}
	}while(next_permutation(perm,perm+3));
	memset(col,0,sizeof(col));
	for (int i=0;i<3;++i){
		perm[i]=mp[i];
	}
	get_ans(vec[0],0);
	cout<<maxv<<endl;
	for (int i=1;i<=n;++i){
		cout<<col[i]<<" ";
	}
	return 0;
}