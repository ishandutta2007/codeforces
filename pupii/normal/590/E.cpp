#include<bits/stdc++.h>
#define maxn 15000001
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
//1.5e7 int=60M
int n,node[760],slink[maxn],trans[2][maxn],len[maxn],cnt=1,lst=1;
//trans
int Node[10000010],begin[760];
bool G[760][760];
std::string str[760];
void extend(int ch){
	if(trans[ch][lst]){
		int q=trans[ch][lst],p=lst;
		if(len[q]==len[p]+1)lst=q;
		else{
			int nq=++cnt;len[nq]=len[p]+1;slink[nq]=slink[q];
			for(int i=0;i<2;++i)trans[i][nq]=trans[i][q];
			while(p&&trans[ch][p]==q)trans[ch][p]=nq,p=slink[p];
			slink[q]=nq;lst=nq;
		}
		return;
	}
	int p=lst,np=++cnt;len[np]=len[p]+1;lst=np;
	while(p&&!trans[ch][p])trans[ch][p]=np,p=slink[p];
	if(!p)slink[np]=1;
	else{
		int q=trans[ch][p];
		if(len[q]==len[p]+1)slink[np]=q;
		else{
			int nq=++cnt;len[nq]=len[p]+1,slink[nq]=slink[q];
			for(int i=0;i<2;++i)trans[i][nq]=trans[i][q];
			while(p&&trans[ch][p]==q)trans[ch][p]=nq,p=slink[p];
			slink[q]=slink[np]=nq;
		}
	}
}
int matchx[760],matchy[760],vis[760],tm;
int cx[760],cy[760];
bool Match(int x){
	for(int i=1;i<=n;++i)
		if(G[x][i]&&vis[i]<tm){
			vis[i]=tm;
			if(!matchy[i]||Match(matchy[i])){matchy[i]=x,matchx[x]=i;return 1;}
		}
	return 0;
}
void DFS(int x){
	if(cx[x])return;cx[x]=1;
	for(int i=1;i<=n;++i)
		if(G[x][i]&&matchy[i]&&!cy[i])
			cy[i]=1,DFS(matchy[i]);
}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	n=gi();int m=0;
	for(int i=1;i<=n;++i){
		static std::unordered_set<int>st;
		std::cin>>str[i];
		lst=1;
		begin[i]=m+1;
		for(char j:str[i])extend(j-'a'),Node[++m]=lst;
		if(st.count(lst))continue;
		node[i]=lst;st.insert(lst);
	}
	begin[n+1]=m+1;
	memset(trans,0,sizeof trans);
	int*t=trans[0],*st=trans[1],*ID=trans[0];
	for(int i=1;i<=cnt;++i)++t[len[i]];
	for(int i=1;i<=cnt;++i)t[i]+=t[i-1];
	for(int i=1;i<=cnt;++i)st[t[len[i]]--]=i;
	memset(trans[0],0,sizeof trans[0]);
	for(int i=1;i<=n;++i)ID[node[i]]=i;
	for(int _=1,i;_<=cnt;++_){
		i=st[_];
		if(!ID[i])ID[i]=ID[slink[i]];
	}
	for(int i=1;i<=n;++i)
		for(int _=begin[i],x;_<begin[i+1];++_){
			x=Node[_];
			if(ID[x]==i)G[i][ID[slink[x]]]=1;
			else G[i][ID[x]]=1;
		}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				G[i][j]|=G[i][k]&G[k][j];
	int ans=0;
	for(int i=1;i<=n;++i)tm=i,ans+=Match(i);
	for(int i=1;i<=n;++i)if(!matchx[i])DFS(i);
	printf("%d\n",n-ans);
	for(int i=1;i<=n;++i)if(cx[i]&&!cy[i])printf("%d ",i);
	return 0;
}