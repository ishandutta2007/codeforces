#include<bits/stdc++.h>
typedef long long ll;
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
std::vector<int>vec[100010],s[2][2],_s[2][2],ans;
char S[100010];
int main(){
	scanf("%s",S+1);int n=strlen(S+1),m=0,sum=0;
	for(int i=1;i<=n;++i)sum+=S[i]=='L'?1:-1;
	for(int i=1;i<=n;++i){
		if(S[i]=='R'){
			if(s[0][0].empty()&&s[1][0].empty())s[1][0].push_back(++m);
			if(s[1][0].size()){
				vec[s[1][0].back()].push_back(i);
				s[1][1].push_back(s[1][0].back());s[1][0].pop_back();
			}else if(s[0][0].size()){
				vec[s[0][0].back()].push_back(i);
				s[0][1].push_back(s[0][0].back());s[0][0].pop_back();
			}
		}else{
			if(s[0][1].empty()&&s[1][1].empty())s[0][1].push_back(++m);
			if(s[0][1].size()){
				vec[s[0][1].back()].push_back(i);
				s[0][0].push_back(s[0][1].back());s[0][1].pop_back();
			}else if(s[1][1].size()){
				vec[s[1][1].back()].push_back(i);
				s[1][0].push_back(s[1][1].back());s[1][1].pop_back();
			}
		}
	}
	printf("%d\n",m-1);
	for(int i=0;i<2;++i)for(int j=0;j<2;++j)_s[i][j]=s[i][j];
	for(int st=0;st<2;++st){
		ans.clear();
		for(int i=0;i<2;++i)for(int j=0;j<2;++j)s[i][j]=_s[i][j];
		auto output=[&](int x){for(int i:vec[x])ans.push_back(i);};
		for(int _=0;_<m;++_){
			if(s[st][!st].size())output(s[st][!st].back()),s[st][!st].pop_back();
			else if(s[st][st].size())output(s[st][st].back()),s[st][st].pop_back(),st^=1;
			else {ans.clear();break;}
		}
		if(!ans.size())continue;
		break;
	}
	sum=0;
	for(int i=1;i<ans.size();++i)assert(S[ans[i-1]]!=S[ans[i]]),sum+=ans[i-1]>ans[i];
	assert(sum==m-1);
	#ifndef DEBUG
	for(int i:ans)printf("%d ",i);
	#endif
	puts("");
	return 0;
}