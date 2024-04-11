#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll readint(){
	ll x=0;
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
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=readint();
	while(T--){
		int n=readint();
		int ml=2e9,mnl=0,mrl=0,mnrl=0,mr=0,mnr=0;
		for(int i=1;i<=n;i++){
			int l,r,a;
			l=readint();
			r=readint();
			a=readint();
			if(l<ml){
				ml=l;
				mnl=a;
				mrl=r;
				mnrl=a;
			}
			else if(l==ml){
				mnl=min(mnl,a);
				if(r>mrl){
					mrl=r;
					mnrl=a;
				}
				else if(r==mrl) mnrl=min(mnrl,a);
			}
			if(r>mr){
				mr=r;
				mnr=a;
			}
			else if(r==mr) mnr=min(mnr,a);
			if(mrl==mr) printf("%d\n",min(mnrl,mnl+mnr));
			else printf("%d\n",mnl+mnr);
		}
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}