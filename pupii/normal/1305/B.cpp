#include<bits/stdc++.h>
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
int pow(int x,int y){
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
char S[1010];
int pre[1010],suf[1010];
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int qwq=1;//int qwq=gi();
	while(qwq--){
		std::vector<std::vector<int>>ans;
		std::string S;std::cin>>S;S=' '+S;
		while(1){
			for(int i=1;i<S.size();++i)pre[i]=(S[i]=='(')+pre[i-1];
			suf[S.size()]=0;
			for(int i=S.size()-1;i;--i)suf[i]=(S[i]==')')+suf[i+1];
			int s=0,p;
			for(int i=1;i+1<S.size();++i)if(std::min(pre[i],suf[i+1])>s)s=std::min(pre[i],suf[i+1]),p=i;
			if(!s)break;
			ans.push_back({});
			int L=s,R=s;
			for(int i=1;i<=p;++i)if(L&&S[i]=='(')--L,S[i]='.';
			for(int i=S.size()-1;i>p;--i)if(R&&S[i]==')')--R,S[i]='.';
			for(int i=1;i<S.size();++i)if(S[i]=='.')ans.back().push_back(i);
			S.erase(std::remove(S.begin(),S.end(),'.'),S.end());
		}
		printf("%d\n",ans.size());
		for(auto i:ans){
			printf("%d\n",i.size());
			for(int j:i)printf("%d ",j);
			puts("");
		}
	}
	return 0;
}