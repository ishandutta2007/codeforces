#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::mt19937 rnd(time(NULL));
#define rand rnd
#define pr std::pair<int,int>
#define all(x) (x).begin(),(x).end()
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
char map[11][11];
void fuck(int x,int y){
	map[x][y]=(map[x][y]-'0')%9+'1';
}
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	int qwq=gi();
	while(qwq--){
		for(int i=1;i<10;++i)scanf("%s",map[i]+1);
		fuck(1,1);
		fuck(4,2);
		fuck(7,3);
		fuck(2,4);
		fuck(5,5);
		fuck(8,6);
		fuck(3,7);
		fuck(6,8);
		fuck(9,9);
		for(int i=1;i<10;++i)printf("%s\n",map[i]+1);
	}
	return 0;
}