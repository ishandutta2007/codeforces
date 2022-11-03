#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct data{int w,i;};
bool operator<(const data&a,const data&b){return a.w>b.w;}
ll A[100010];
data p1[100010];
std::vector<data>p2[100010],p3;
double Ln2[100010],Ln3[100010];
int t[100010];
double W[100010];
struct cmp{bool operator()(int a,int b){return W[a]<W[b];}};
std::priority_queue<int,std::vector<int>,cmp>que;
int op[100010],ans2[100010],ans3[100010];
int main(){
	int n=gi(),k=gi(),lim=gi();
	for(int i=1;i<=n;++i)A[i]=gi();
	for(int i=1;i<=k;++i){
		int o=gi(),p=gi(),x=gi();
		op[i]=o;
		if(o==3)p3.push_back({x,i});
		else if(o==1){if(x>p1[p].w)p1[p]={x,i};}
		else p2[p].push_back({x,i});
	}
	for(int i=1;i<=n;++i)if(p1[i].w>A[i])p2[i].push_back({p1[i].w-A[i],p1[i].i});
	std::sort(p3.begin(),p3.end());
	for(int i=1;i<=std::min((int)p3.size(),lim);++i)ans3[i]=p3[i-1].i,Ln3[i]=Ln3[i-1]+log(p3[i-1].w);
	for(int i=p3.size()+1;i<=lim;++i)Ln3[i]=Ln3[i-1];
	for(int i=1;i<=n;++i){
		std::sort(p2[i].begin(),p2[i].end());
		if(!p2[i].empty())W[i]=log(A[i]+p2[i][0].w)-log(A[i]),que.push(i);
	}
	while(!que.empty()){
		static int i;
		++i;Ln2[i]=Ln2[i-1];
		int x=que.top();que.pop();
		Ln2[i]+=W[x];
		A[x]+=p2[x][t[x]].w;
		ans2[i]=p2[x][t[x]].i;
		if(++t[x]<p2[x].size())W[x]=log(A[x]+p2[x][t[x]].w)-log(A[x]),que.push(x);
		if(que.empty())while(i<=lim)++i,Ln2[i]=Ln2[i-1];
	}
	int T2,T3;double res=-1e233;
	for(int i=0;i<=lim;++i)if(Ln2[i]+Ln3[lim-i]>res)T2=i,T3=lim-i,res=Ln2[i]+Ln3[lim-i];
	while(T2&&!ans2[T2])--T2;
	while(T3&&!ans3[T3])--T3;
	std::sort(ans2+1,ans2+T2+1,[&](int a,int b){return op[a]<op[b];});
	printf("%d\n",T2+T3);
	for(int i=1;i<=T2;++i)printf("%d ",ans2[i]);
	for(int i=1;i<=T3;++i)printf("%d ",ans3[i]);
	return 0;
}