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
const int maxn=1e4+5;
int mf[maxn*5];
vector<int> p;
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	for(int i=2;i<maxn*5;i++){
		if(!mf[i]) p.push_back(i);
		for(int j=0;j<(int)p.size()&&i*p[j]<maxn*5;j++){
			mf[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
	int T=readint();
	while(T--){
		int d=readint();
		int a,b;
		a=*lower_bound(p.begin(),p.end(),d+1);
		b=*lower_bound(p.begin(),p.end(),d+a);
		printf("%lld\n",1ll*a*b);
	}
	return 0;
}