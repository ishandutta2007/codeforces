#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
struct vector{ll x,y;}x[100010];
il vector operator+(const vector&a,const vector&b){return(vector){a.x+b.x,a.y+b.y};}
il vector operator-(const vector&a,const vector&b){return(vector){a.x-b.x,a.y-b.y};}
il ll operator^(const vector&a,const vector&b){return a.x*b.y-a.y*b.x;}
bool yes[100010];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),p,p2;
	for(int i=1;i<=n;++i)x[i].x=gi(),x[i].y=gi();
	
	memset(yes,0,sizeof yes);
	for(int i=1;i<=n;++i)if(((x[1]-x[2])^(x[1]-x[i]))==0)yes[i]=1;
	p=p2=0;
	for(int i=1;i<=n;++i)
		if(!yes[i]){
			if(!p)p=i;
			else if(!p2){p2=i;break;}
		}
	if(!p2)return puts("YES"),0;
	for(int i=p2+1;i<=n;++i)if(((x[p]-x[p2])^(x[p]-x[i]))&&!yes[i])goto GG1;
	return puts("YES"),0;GG1:;
	
	memset(yes,0,sizeof yes);
	for(int i=1;i<=n;++i)if(((x[1]-x[3])^(x[1]-x[i]))==0)yes[i]=1;
	p=p2=0;
	for(int i=1;i<=n;++i)
		if(!yes[i]){
			if(!p)p=i;
			else if(!p2){p2=i;break;}
		}
	if(!p2)return puts("YES"),0;
	for(int i=p2+1;i<=n;++i)if(((x[p]-x[p2])^(x[p]-x[i]))&&!yes[i])goto GG2;
	return puts("YES"),0;GG2:;
	
	memset(yes,0,sizeof yes);
	for(int i=1;i<=n;++i)if(((x[2]-x[3])^(x[2]-x[i]))==0)yes[i]=1;
	p=p2=0;
	for(int i=1;i<=n;++i)
		if(!yes[i]){
			if(!p)p=i;
			else if(!p2){p2=i;break;}
		}
	if(!p2)return puts("YES"),0;
	for(int i=p2+1;i<=n;++i)if(((x[p]-x[p2])^(x[p]-x[i]))&&!yes[i])goto GG3;
	return puts("YES"),0;GG3:;
	
	return puts("NO"),0;
}