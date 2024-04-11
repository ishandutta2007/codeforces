#include<bits/stdc++.h>

#define IT set<node>::iterator

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	ll x,y; double ang;
	node(ll xx=0,ll yy=0,double aa=0):x(xx),y(yy),ang(aa){}
	node operator-(const node c)const{return node(x-c.x,y-c.y);}
	ll operator*(const node c)const{return 1ll*x*c.y-1ll*c.x*y;}
	bool operator<(const node c)const{return ang==c.ang?x<c.x:ang<c.ang;}
};

int n,nowx,nowy,xx[5],yy[5];
set<node> s;
IT lst,nxt;

IT pre(IT x){return x==s.begin()?--s.end():--x;}
IT suc(IT x){return (++x)==s.end()?s.begin():x;}

void ins(node x){
	if((*nxt-x)*(x-*lst)>=0) return;
	s.insert(x);
	auto it=s.find(x),it1=pre(it),it2=pre(it1);
	while((x-*it1)*(*it2-x)<=0) s.erase(it1),it1=it2,it2=pre(it2);
	it1=suc(it),it2=suc(it1);
	while((x-*it1)*(*it2-x)>=0) s.erase(it1),it1=it2,it2=suc(it2);
}

int main(){
	n=readint()-3;
	int opt,x,y;
	for(int i=1;i<=3;i++){
		opt=readint(); xx[i]=readint()*3; yy[i]=readint()*3;
		nowx+=xx[i]/3,nowy+=yy[i]/3;
	}
	for(int i=1;i<=3;i++) s.insert(node(xx[i],yy[i],atan2(yy[i]-nowy,xx[i]-nowx)));
	for(int i=1;i<=n;i++){
		opt=readint(); x=readint()*3; y=readint()*3;
		nxt=s.lower_bound(node(x,y,atan2(y-nowy,x-nowx)));
		if(nxt==s.end()) nxt=s.begin();
		lst=pre(nxt);
		if(opt==1) ins(node(x,y,atan2(y-nowy,x-nowx)));
		else if((*nxt-node(x,y,atan2(y-nowy,x-nowx)))*(node(x,y,atan2(y-nowy,x-nowx))-*lst)>=0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}