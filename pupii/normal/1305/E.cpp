#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cctype>
#include<iostream>
#include<queue>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
#define pr std::pair<int,int>
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
int mod;
int pow(int x,ll y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
int a[5010];
int M[30000000];
struct cmp{bool operator()(pr a,pr b)const{return a.fi==b.fi?a.se>b.se:a.fi<b.fi;}};
std::priority_queue<pr,std::vector<pr>,cmp>que;
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int n=gi(),m=gi();
	a[1]=1;
	int lst=1,flg=1;
	for(int i=2;i<=n;++i){
		lst=2e9;if(i==2)lst=1;
		if(flg){
			if((i-1>>1)>m){
				flg=0;
				for(int j=1;j<i;++j)
					for(int k=j+1;k<i;++k)
						++M[j+k];
				for(int j=i;j<=2*i;++j)if(M[j])que.push({M[j],j});
			}else{a[i]=i;m-=(i-1>>1);continue;}
		}
		while(!que.empty()&&(que.top().se<=a[i-1]||que.top().fi>m||M[que.top().se]!=que.top().fi)){
			if(!M[que.top().se+1])lst=std::min(lst,que.top().se);
			que.pop();
		}
		if(que.empty())a[i]=lst+1;
		else a[i]=que.top().se,m-=que.top().fi;
		for(int j=1;j<i;++j)que.push({++M[a[i]+a[j]],a[i]+a[j]});
	}
	if(m)return puts("-1"),0;
	else for(int i=1;i<=n;++i)printf("%d ",a[i]);
	return 0;
}