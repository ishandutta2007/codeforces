#include<bits/stdc++.h>
typedef long long ll;
#define mod 1000000007
#define all(x) (x).begin(),(x).end()
#define pr std::pair<int,int>
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
ll gi(){
	ll x=0,f=1;char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
bool debug=0;
int n,m,A[10000],B[10000],E[51][51],rE[51][51];
std::vector<int>w[10000],rw[10000],G[51],rG[51];
void inc(int&x,int y){x=x+y>=mod?x+y-mod:x+y;}
void dec(int&x,int y){x=x>=y?x-y:x+mod-y;}
int sub(int x,int y){return x>=y?x-y:x+mod-y;}
std::vector<int>path[51][51][2][2];
int f[110][51][2],ans[110];
std::vector<int>seq,rseq;
bool extend(int p,std::vector<int>&seq,int E[51][51],std::vector<int>w[10000]){
	if(p==seq.size()-1)return seq.size()<=n+n;
	int y=seq[p+1],x=seq[p];
	if(E[x][y]){
		for(int i:w[E[x][y]])seq.push_back(i);
		return seq.size()<=n+n&&extend(p+1,seq,E,w);
	}else return 0;
}
int main(){
#ifdef DEBUG
debug=1;
#endif
	n=gi(),m=gi();
	for(int i=1;i<=m;++i){
		int u=gi(),v=gi();A[i]=u,B[i]=v;G[u].push_back(v),G[v].push_back(u);E[u][v]=rE[v][u]=i;
		w[i].resize(gi());for(int j=0;j<w[i].size();++j)w[i][j]=gi();
		rw[i]=w[i],std::reverse(all(rw[i]));
	}
	//-1 -> -1: A->B W=....A
	for(int i=1;i<=m;++i)
		if(w[i].size()&&w[i].back()==A[i]){
			seq=rw[i];
			if(extend(0,seq,rE,rw)){
				path[seq.back()][B[i]][0][0].push_back(seq.size());
				if(debug){printf("-1 -1 path :");for(int i:seq)printf("%d ",i);puts("");}
			}
		}
	//0 -> 0: A->B W=B....
	for(int i=1;i<=m;++i)
		if(w[i].size()&&w[i][0]==B[i]){
			seq=w[i];
			if(extend(0,seq,E,w)){
				path[A[i]][seq.back()][1][1].push_back(seq.size());
				if(debug){printf("0 0 path :");for(int i:seq)printf("%d ",i);puts("");}
			}
		}
	//-1 -> 0: A->B W=...AB....
	bool found=1;
	for(int i=1;i<=m;++i)
		if(w[i].size()){
			int p=-1;
			for(int j=1;j<w[i].size();++j)if(w[i][j-1]==A[i]&&w[i][j]==B[i])p=j;
			if(p==-1)continue;
			seq=rseq={};
			for(int j=p-1;~j;--j)rseq.push_back(w[i][j]);
			for(int j=p;j<w[i].size();++j)seq.push_back(w[i][j]);
			if(extend(0,seq,E,w)&&extend(0,rseq,rE,rw)){
				path[rseq.back()][seq.back()][0][1].push_back(seq.size()+rseq.size()-1);
				std::reverse(all(rseq));
				if(!found){
					printf("%d\n",seq.size()+rseq.size());
					for(int i:rseq)printf("%d ",i);
					for(int i:seq)printf("%d ",i);
					puts("");found=1;
				}
				if(debug){
					printf("-1 0 path :");
					for(int i:rseq)printf("%d ",i);
					for(int i:seq)printf("%d ",i);
					puts("");
				}
			}
		}
	if(!found)puts("0\n");
	// 0 -> -1: A->B W=empty
	for(int i=1;i<=m;++i)
		if(w[i].empty()){
			path[A[i]][B[i]][1][0].push_back(1);
			if(debug)printf("0 -1 path :%d %d\n",A[i],B[i]);
		}
	for(int i=1;i<=n;++i)f[0][i][0]=1;
	for(int le=0;le<=n+n;++le)
		for(int i=1;i<=n;++i)
			for(int o=0;o<2;++o){
				if(!f[le][i][o])continue;
				if(debug)printf("%d %d %d %d\n",le,i,o,f[le][i][o]);
				if(o)inc(ans[le],f[le][i][o]);
				for(int j=1;j<=n;++j)
					for(int to=0;to<2;++to)
						for(int nl:path[i][j][o][to])
							if(nl+le<=n+n)inc(f[le+nl][j][to],f[le][i][o]);
			}
	for(int i=1;i<=n+n;++i)printf("%d\n",ans[i]);
	return 0;
}