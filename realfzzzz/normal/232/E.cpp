#include<bits/stdc++.h>
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
const int maxn=500+5,maxq=6e5+5;
int n,m,q,X1[maxq],Y1[maxq],X2[maxq],Y2[maxq];
char g[maxn][maxn];
int ord[maxq];
bitset<maxn> s1[maxn][maxn],s2[maxn][maxn];
bool ans[maxq];
void solve(int L,int R,int l,int r){
	int mid=L+(R-L)/2,ml=1;
	for(int i=1;i<=m;i++){
		s1[mid][i]=0;
		if(g[mid][i]=='#') ml=i+1;
		else for(int j=ml;j<=i;j++) s1[mid][i][j]=1;
	}
	ml=m;
	for(int i=m;i>0;i--){
		s2[mid][i]=0;
		if(g[mid][i]=='#') ml=i-1;
		else for(int j=i;j<=ml;j++) s2[mid][i][j]=1;
	}
	if(L==R){
		for(int i=l;i<=r;i++){
			int x=ord[i];
			ans[x]=s1[R][Y2[x]][Y1[x]];
		}
		return;
	}
	for(int i=mid+1;i<=R;i++) for(int j=1;j<=m;j++)
		if(g[i][j]=='#') s1[i][j]=0;
		else s1[i][j]=s1[i-1][j]|s1[i][j-1];
	for(int i=mid-1;i>=L;i--) for(int j=m;j>0;j--)
		if(g[i][j]=='#') s2[i][j]=0;
		else s2[i][j]=s2[i+1][j]|s2[i][j+1];
	vector<int> v1,v2;
	for(int i=l;i<=r;i++){
		int x=ord[i];
		if(X2[x]<=mid) v1.push_back(x);
		else if(X1[x]>mid) v2.push_back(x);
		else ans[x]=(s1[X2[x]][Y2[x]]&s2[X1[x]][Y1[x]]).any();
	}
	for(int i=0;i<(int)v1.size();i++) ord[i+l]=v1[i];
	for(int i=0;i<(int)v2.size();i++) ord[i+l+v1.size()]=v2[i];
	solve(L,mid,l,l+v1.size()-1);
	solve(mid+1,R,l+v1.size(),l+v1.size()+v2.size()-1);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=readint();
	m=readint();
	for(int i=1;i<=n;i++) scanf("%s",g[i]+1);
	q=readint();
	for(int i=1;i<=q;i++){
		X1[i]=readint();
		Y1[i]=readint();
		X2[i]=readint();
		Y2[i]=readint();
	}
	for(int i=1;i<=q;i++) ord[i]=i;
	solve(1,n,1,q);
	for(int i=1;i<=q;i++) printf(ans[i]?"Yes\n":"No\n");
	#ifdef LOCAL
	fprintf(stderr,"%d\n",(int)clock());
	#endif
	return 0;
}