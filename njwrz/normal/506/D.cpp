#include<bits/stdc++.h>
using namespace std;
map<int,int> p[100005];
int get_fa(int color,int v){
	if(!p[color].count(v)||p[color][v]==v)return p[color][v]=v;
	return p[color][v]=get_fa(color,p[color][v]);
} 
void put(int color,int a,int b){
	a=get_fa(color,a);
	b=get_fa(color,b);
	if(a!=b){
		if(rand()&1)swap(a,b);
		p[color][b]=a;
	}
}
vector<pair<int,int> > A[100005];
map<pair<int,int>,int> M;
int main(){
	int n,m,a,b,c;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&a,&b,&c);
		a--;b--;c--;
		put(c,a,b);
	}
	for(int color=0;color<m;color++){
		for(map<int,int>::iterator it=p[color].begin();it!=p[color].end();it++){
			A[it->first].push_back(make_pair(color,it->second));
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<A[i].size();j++){
			A[i][j].second=get_fa(A[i][j].first,i);
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d%d",&a,&b);
		a--;b--;
		if(A[a].size()>A[b].size()||(A[a].size()==A[b].size()&&a>b)){
			swap(a,b);
		}
		if(M.count(make_pair(a,b))){
			printf("%d\n",M[make_pair(a,b)]);
			continue;
		}
		int ans=0;
		for(int j=0;j<A[a].size();j++){
			if(binary_search(A[b].begin(),A[b].end(),A[a][j]))ans++;
		} 
		M[make_pair(a,b)]=ans;
		printf("%d\n",ans);
	}
	return 0;
}