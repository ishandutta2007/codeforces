#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,k;

struct node{
	int siz;
	int mina[15],maxa[15];
	bool operator<(const node c)const{
		for(int i=1;i<=k;i++) if(maxa[i]>c.mina[i]) return false;
		return true;
	}
}x;

set<node> s;
set<node>::iterator it;

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++) x.mina[j]=x.maxa[j]=readint();
		x.siz=1;
		while((it=s.find(x))!=s.end()){
			x.siz+=it->siz;
			for(int j=1;j<=k;j++){
				x.mina[j]=min(x.mina[j],it->mina[j]);
				x.maxa[j]=max(x.maxa[j],it->maxa[j]);
			}
			s.erase(it);
		}
		s.insert(x);
		printf("%d\n",(--s.end())->siz);
	}
	return 0;
}