#include<bits/stdc++.h>
#define il inline
#define vd void
#define ll unsigned long long
il ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::vector<int>vec[1010];int s;
std::map<std::string,int>mmp;
std::map<std::string,ll>key;
std::vector<std::string>ANS;
ll Key[1010];
std::string a[1010],b[1010],c[1010];
char op[1010];
std::map<ll,std::string>calced;
std::set<std::string>used;
il std::string newstr(){
	std::string ret("test");
	static char ran[]="qwertyuiopasdfghjklzxcvbnm1234567890";
	while(1){
		ret[0]='a'+rand()%26;
		for(int i=1;i<4;++i)ret[i]=ran[rand()%36];
		if(used.find(ret)==used.end()){used.insert(ret);break;}
	}
	return ret;
}
il std::string solve(std::string res,int n){
	if(mmp.find(res)==mmp.end())return res;
	int p=mmp[res];
	auto it=std::lower_bound(vec[p].begin(),vec[p].end(),n);
	if(it==vec[p].begin())return res;
	n=*--it;
	if(calced.find(Key[n])!=calced.end())return calced[Key[n]];
	if(op[n]=='%')return calced[Key[n]]=solve(b[n],n);
	else{
		std::string ret=newstr();
		ANS.push_back(ret+'='+solve(b[n],n)+op[n]+solve(c[n],n));
		return calced[Key[n]]=ret;
	}
}
il ll calc(ll a,ll b,char c){return (a+c*3131441)*(b+c*2332424);}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	srand(time(NULL));
	int n=gi();
	for(int i=1;i<=n;++i){
		std::string yyb;std::cin>>yyb;
		int j,p;
		for(j=p=0;j<yyb.size();++j)
			if(yyb[j]=='=')p=j,a[i]=yyb.substr(0,j);
			else if(yyb[j]=='$'||yyb[j]=='^'||yyb[j]=='#'||yyb[j]=='&')b[i]=yyb.substr(p+1,j-p-1),c[i]=yyb.substr(j+1,yyb.size()-j-1),op[i]=yyb[j];
		if(!op[i])op[i]='%',b[i]=yyb.substr(p+1,yyb.size()-p-1);
		if(mmp.find(a[i])==mmp.end())mmp[a[i]]=++s;
		if(key.find(b[i])==key.end())key[b[i]]=1llu*rand()*rand();
		if(!c[i].empty()&&key.find(c[i])==key.end())key[c[i]]=1llu*rand()*rand();
		if(op[i]=='%')key[a[i]]=key[b[i]];
		else key[a[i]]=calc(key[b[i]],key[c[i]],op[i]);
		Key[i]=key[a[i]];
		used.insert(a[i]);used.insert(b[i]);used.insert(c[i]);
		vec[mmp[a[i]]].push_back(i);
	}
	for(int i=1;i<=s;++i)std::sort(vec[i].begin(),vec[i].end());
	std::string r=solve("res",n+1);
	if(r!="res"){
		for(int i=ANS.size()-1;~i;--i)if(~ANS[i].find(r)){ANS[i].replace(0,r.size(),"res");goto ed;}
		ANS.push_back("res="+r);ed:;
	}
	printf("%d\n",ANS.size());
	for(auto i:ANS)std::cout<<i<<std::endl;
	return 0;
}