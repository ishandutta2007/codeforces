#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
pii st,en;

pii nxt(pii x){
	if(x.se==m) x.fi++,x.se=1;
	else x.se++;
	return x;
}

pii lst(pii x){
	if(x.se==1) x.fi--,x.se=m;
	else x.se--;
	return x;
}

int main(){
	n=readint(); m=readint();
	st=mp(1,1),en=mp(n,m);
	while(st!=en){
		printf("%d %d\n",st.fi,st.se);
		st=nxt(st);
		if(st==en) break;
		printf("%d %d\n",en.fi,en.se);
		en=lst(en);
	}
	printf("%d %d\n",st.fi,st.se);
	return 0;
}