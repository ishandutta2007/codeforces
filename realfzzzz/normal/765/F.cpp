#include<algorithm>
#include<vector>
#include<cmath>
#include<cctype>
#include<cstdio>
using namespace std;
inline int readint(){
	int x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)&&c!='-') c=getchar();
	if(c=='-'){
		f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e5+5,maxs=350;
int n,m,a[maxn];
int s,blocks,bl[maxs],br[maxs],pos[maxn];
int ord[maxn];
bool cmp(int x,int y){
	return a[x]<a[y];
}
int f[maxs][maxn],g[maxs][maxs];
const int inf=2e9;
int query(int l,int r){
	int last=-1,ans=inf;
	for(int i=bl[pos[r]];i<=br[pos[r]];i++) if(l<=ord[i]&&ord[i]<=r){
		if(last>=0) ans=min(ans,a[ord[i]]-last);
		last=a[ord[i]];
	}
	return ans;
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	s=sqrt(n);
	blocks=(n-1)/s+1;
	for(int i=1;i<=blocks;i++){
		bl[i]=(i-1)*s+1;
		if(i==blocks) br[i]=n;
		else br[i]=i*s;
		for(int j=bl[i];j<=br[i];j++){
			pos[j]=i;
			ord[j]=j;
		}
		sort(ord+bl[i],ord+br[i]+1,cmp);
	}
	for(int i=1;i<=blocks;i++) for(int j=1;j<=blocks;j++) if(i!=j){
		int cur=bl[i];
		for(int k=bl[j];k<=br[j];k++){
			while(cur<=br[i]&&a[ord[cur]]<a[ord[k]]) cur++;
			if(cur==bl[i]) f[i][ord[k]]=a[ord[cur]]-a[ord[k]];
			else if(cur==br[i]+1) f[i][ord[k]]=a[ord[k]]-a[ord[cur-1]];
			else f[i][ord[k]]=min(a[ord[cur]]-a[ord[k]],a[ord[k]]-a[ord[cur-1]]);
		}
	}
	for(int i=1;i<=blocks;i++) for(int j=i+1;j<=blocks;j++)
		for(int k=bl[j]+1;k<=br[j];k++) f[i][k]=min(f[i][k],f[i][k-1]);
	for(int i=1;i<=blocks;i++) for(int j=1;j<i;j++)
		for(int k=br[j]-1;k>=bl[j];k--) f[i][k]=min(f[i][k],f[i][k+1]);
	for(int i=1;i<=blocks;i++) for(int j=i-2;j>0;j--)
		for(int k=bl[i];k<=br[i];k++) f[j][k]=min(f[j][k],f[j+1][k]);
	for(int i=1;i<=blocks;i++) for(int j=i+2;j<=blocks;j++)
		for(int k=bl[i];k<=br[i];k++) f[j][k]=min(f[j][k],f[j-1][k]);
	for(int i=1;i<=blocks;i++) for(int j=bl[i];j<=br[i];j++) f[i][j]=inf;
	for(int i=1;i<=blocks;i++){
		g[i][i-1]=inf;
		for(int j=i;j<=blocks;j++){
			g[i][j]=g[i][j-1];
			g[i][j]=min(g[i][j],f[i][br[j]]);
			g[i][j]=min(g[i][j],query(bl[j],br[j]));
		}
	}
	m=readint();
	while(m--){
		int l,r;
		l=readint();
		r=readint();
		if(pos[l]==pos[r]) printf("%d\n",query(l,r));
		else{
			int ans=min(query(l,br[pos[l]]),query(bl[pos[r]],r));
			ans=min(ans,g[pos[l]+1][pos[r]-1]);
			ans=min(ans,f[pos[r]-1][l]);
			ans=min(ans,f[pos[l]+1][r]);
			vector<int> res1,res2;
			for(int i=bl[pos[l]];i<=br[pos[l]];i++) if(ord[i]>=l) res1.push_back(ord[i]);
			for(int i=bl[pos[r]];i<=br[pos[r]];i++) if(ord[i]<=r) res2.push_back(ord[i]);
			int cur=0;
			for(int i=0;i<r-bl[pos[r]]+1;i++){
				while(cur<br[pos[l]]-l+1&&a[res1[cur]]<a[res2[i]]) cur++;
				if(!cur) ans=min(ans,a[res1[cur]]-a[res2[i]]);
				else if(cur==br[pos[l]]-l+1) ans=min(ans,a[res2[i]]-a[res1[cur-1]]);
				else ans=min(ans,min(a[res1[cur]]-a[res2[i]],a[res2[i]]-a[res1[cur-1]]));
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}