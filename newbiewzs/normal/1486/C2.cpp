#include<bits/stdc++.h>
#define int long long
#define fl fflush(stdout)
#define cl fflush(stdout)
using namespace std;
inline int read(){
	char c=getchar();int s=0;while(c<'0' or c>'9')c=getchar();
	while(c>='0' and c<='9')s=s*10+c-'0',c=getchar();return s;
}
const int N=1e5+55; 
int T,n,x,y;
int pd[N];
map<int,int>ma[N];
#define mid ((l+r)>>1)
int ask(int l,int r){
	if(l>=r)return -1;
	int q;
	cout<<"? "<<l<<" "<<r<<endl;
	cl;
	cin>>q;
	return q;
}
void cdqr(int l,int r,int u){
	if(l+1==r){
		int q;
		q=ask(u,l);
		if(q==u){
			cout<<"! "<<l;
		}
		else cout<<"! "<<r;
		exit(0);
	}
	if(l==r){
		cout<<"! "<<l+1;
		exit(0);
	}
	int g=0;
	if(mid!=u){
	cout<<"? "<<u<<" "<<mid<<endl;
	cl;
	
	cin>>g;}
	else g=u;
	cl;
	if(g!=u){
		cdqr(mid,r,u);
	}
	else{
		cdqr(l,mid,u);
	}
}
void cdql(int l,int r,int u){
	if(l==r){
		cout<<"! "<<l-1;
		exit(0);
	} 
	if(l+1==r){
		int q;
		q=ask(r,u);
		if(q==u){
			cout<<"! "<<r;
		}
		else cout<<"! "<<l;
		exit(0);
	}
	int g=0;
	if(mid!=u){
	cout<<"? "<<mid<<" "<<u<<endl;
	cl;
	cin>>g;}
	else g=u;
	cl;
	if(g!=u){
		cdql(l,mid,u);
	}
	else{
		cdql(mid,r,u);
	}
}
signed main(){
	memset(pd,-1,sizeof(pd));
		n=read();
		
		int l=1;int r=n;
		cout<<"? "<<l<<" "<<r<<endl;
		
		cl;
		cin>>x;ma[l][r]=x;
		cl;
		if(n==2){
			if(x==1)cout<<"! "<<2;
			else cout<<"! "<<1;
			return 0; 
		}
		int zuo,you;
		int ll=1;int rr=x;
		pd[x]=0;
		if(x!=1){
			if(!ma[ll][rr]){
			cout<<"? "<<ll<<" "<<rr<<endl;
			cl;
			cin>>y;}
			else y=ma[ll][rr];
			ma[ll][rr]=y;
			if(y==x){
				zuo=1;you=x;
				cdql(1,x,x);
			}
		} 
		pd[x]=0;
		ll=x;rr=n;
		cdqr(x,n,x);
	return 0;
}