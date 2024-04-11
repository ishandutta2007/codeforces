#include<bits/stdc++.h>
#include<unistd.h>
#include <unordered_map>
using namespace std;


typedef long long int lint;
typedef pair<int,int> pi;

const int N=100005,M=100005,Q=100005;
struct UnionFindSet{

	static const int MAXN=2*M;
	int par[MAXN];
	int size[MAXN];
	void init(){
		memset(par,-1,sizeof(par));
		for(int i=0;i<MAXN;++i) size[i]=1;
	}
	int root(int a){
		if(par[a]==-1) return a;
		return par[a]=root(par[a]);
	}
	void unite(int a,int b){
		a=root(a);b=root(b);
		if(a==b) return;
		if(size[a]<size[b]) swap(a,b);

		par[b]=a;
		size[a]+=size[b];
	}
	bool same(int a,int b){
		return root(a)==root(b);
	}
};

UnionFindSet u;

int n,m,q;

vector<int> color[N];
pair<pi,int> es[M];
int sum[N];

int get_position(const vector<int>& ar,int indx,int c){
	return sum[indx]+lower_bound(ar.begin(),ar.end(),c)-ar.begin();
}
int main(){
	cin>>n>>m;
	for(int i=0;i<m;++i){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);--a;--b;
		color[a].push_back(c);
		color[b].push_back(c);
		
		es[i]=make_pair(make_pair(a,b),c);
	}
	
	for(int i=0;i<n;++i){
		sort(color[i].begin(),color[i].end());
		color[i].erase(unique(color[i].begin(),color[i].end()),color[i].end());
		sum[i+1]=sum[i]+color[i].size();
	}
	u.init();
	for(int i=0;i<m;++i){
		int a=es[i].first.first,b=es[i].first.second,c=es[i].second;
		int A=get_position(color[a],a,c),B=get_position(color[b],b,c);
		u.unite(A,B);
	}

	int q;cin>>q;

	unordered_map<lint,int> memo;
	for(int qcnt=0;qcnt<q;++qcnt){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		int res=0;
		if(color[a].size()>color[b].size()){
			swap(a,b);
		}

		pi p=make_pair(a,b);
		if(memo.count(a*1ll*n+b)){
			res=memo[a*1ll*n+b];
		}else{
			for(int i=0;i<color[a].size();++i){
				int c=color[a][i];
				if(binary_search(color[b].begin(),color[b].end(),c)){
					int trg=get_position(color[b],b,c);
					if(u.same(trg,sum[a]+i)){
						++res;
					}
				}
			}
			memo[a*1ll*n+b]=res;
		}
		printf("%d\n",res);
	}
	return 0;
}