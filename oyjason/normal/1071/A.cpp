#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
	int nm=0,fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) if(cw=='-') fh=-fh;
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return nm*fh;
}
int n,m,p[1000000],tot,sum,now,res;
set<int>K;
int main(){
	n=read(),m=read();
	for(int i=1;true;i++){
		if(now+i<=n) now+=i,K.insert(i);
		else{
			auto it=K.lower_bound(now+i-n);
			if(it!=K.end()){
				if(*it+sum<=m){
					now+=i-*it,p[++tot]=*it,sum+=*it;
					K.erase(it),K.insert(i);
				}
				else break;
			}
			else if(sum+i<=m) sum+=i,p[++tot]=i;
			else break;
		}
	}
	printf("%d\n",K.size());
	for(auto i=K.begin();i!=K.end();i++) printf("%d ",*i); puts("");
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++) printf("%d%c",p[i],i==tot?'\n':' ');
	return 0;
}