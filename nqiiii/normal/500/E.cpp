#include<cstdio>
#include<vector>
using namespace std;
const int maxn=200000;
int n,m,p[maxn+10],maxr[maxn+10],fa[maxn+10],ans[maxn+10],c[maxn+10];
vector<pair<int,int> > q[maxn+10];
int getf(int x){return fa[x]==x?x:fa[x]=getf(fa[x]);}
void add(int i,int v){for(;i<=n;i+=i&-i) c[i]+=v;};
int query(int i){
	int ans=0; for(;i;i-=i&-i) ans+=c[i]; return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&p[i],&maxr[i]); maxr[i]+=p[i]; fa[i]=i;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		int x,y; scanf("%d%d",&x,&y); q[x].push_back(make_pair(y,i));
	}
	for(int i=n;i>=1;--i){
		add(i+1,p[i+1]-maxr[i]);
		for(int j=i,lst;j<n&&maxr[j]>=p[j+1];j=lst){
			add(j+1,maxr[j]-p[j+1]); lst=getf(j+1);
			if(maxr[j]>maxr[lst]){
				add(lst+1,maxr[lst]-maxr[j]); maxr[lst]=maxr[j];
			}
			fa[j]=lst;
		}
		for(int j=0;j<q[i].size();++j) ans[q[i][j].second]=query(q[i][j].first);
	}
	for(int i=1;i<=m;++i) printf("%d\n",ans[i]); return 0;
}