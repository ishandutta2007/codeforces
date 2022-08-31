#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int mina,sum,lmax,rmax,maxa,lazy;
}t[600000];

int n,q;
int a[200005];
set<int> s[200005];

void update(int id){
	t[id].maxa=max(t[id<<1].maxa,t[id<<1|1].maxa);
	if(t[id<<1].mina==t[id<<1|1].mina){
		t[id].mina=t[id<<1].mina,t[id].lmax=t[id<<1].lmax,t[id].rmax=t[id<<1|1].rmax;
		t[id].sum=t[id<<1].sum+t[id<<1|1].sum+max(t[id<<1].rmax,t[id<<1|1].lmax);
	}
	else if(t[id<<1].mina<t[id<<1|1].mina){
		t[id].mina=t[id<<1].mina,t[id].lmax=t[id<<1].lmax,t[id].rmax=max(t[id<<1].rmax,t[id<<1|1].maxa);
		t[id].sum=t[id<<1].sum;
	}
	else{
		t[id].mina=t[id<<1|1].mina,t[id].rmax=t[id<<1|1].rmax,t[id].lmax=max(t[id<<1|1].lmax,t[id<<1].maxa);
		t[id].sum=t[id<<1|1].sum;
	}
}

void pushdown(int id){
	if(t[id].lazy){
		t[id<<1].lazy+=t[id].lazy,t[id<<1].mina+=t[id].lazy;
		t[id<<1|1].lazy+=t[id].lazy,t[id<<1|1].mina+=t[id].lazy;
		t[id].lazy=0;
	}
}

void change(int id,int l,int r,int x,int c){
	if(l==r) return (void)(t[id].maxa=t[id].lmax=c);
	pushdown(id);
	int mid=(l+r)/2;
	if(x<=mid) change(id<<1,l,mid,x,c);
	else change(id<<1|1,mid+1,r,x,c);
	update(id);
}

void add(int id,int l,int r,int ql,int qr,int c){
	if(l==ql&&r==qr) return (void)(t[id].mina+=c,t[id].lazy+=c);
	pushdown(id);
	int mid=(l+r)/2;
	if(qr<=mid) add(id<<1,l,mid,ql,qr,c);
	else if(ql>mid) add(id<<1|1,mid+1,r,ql,qr,c);
	else add(id<<1,l,mid,ql,mid,c),add(id<<1|1,mid+1,r,mid+1,qr,c);
	update(id);
}

int main(){
	n=readint(); q=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) s[a[i]].insert(i);
	for(int i=1;i<=200000;i++) if(s[i].size()>=1) change(1,1,n,*s[i].begin(),s[i].size());
	for(int i=1;i<=200000;i++) if(s[i].size()>=2) add(1,1,n,*s[i].begin(),*(--s[i].end())-1,1);
	printf("%d\n",n-t[1].sum-t[1].lmax-t[1].rmax);
	int x,y;
	for(int i=1;i<=q;i++){
		x=readint(); y=readint();
		auto it=s[a[x]].lower_bound(x);
		if(it==s[a[x]].begin()){
			auto it1=it; it1++;
			change(1,1,n,x,0);
			if(it1!=s[a[x]].end()){
				change(1,1,n,*it1,s[a[x]].size()-1);
				add(1,1,n,x,*it1-1,-1);
			}
		}
		else if(s[a[x]].size()>=2){
			change(1,1,n,*s[a[x]].begin(),s[a[x]].size()-1);
			auto it1=it; it1++;
			if(it1==s[a[x]].end()){
				auto it2=it; it2--;
				add(1,1,n,*it2,x-1,-1);
			}
		}
		s[a[x]].erase(x);
		a[x]=y;
		s[a[x]].insert(x);
		it=s[a[x]].lower_bound(x);
		if(it==s[a[x]].begin()){
			auto it1=it; it1++;
			if(it1!=s[a[x]].end()) change(1,1,n,*it1,0);
			change(1,1,n,x,s[a[x]].size());
			if(it1!=s[a[x]].end()) add(1,1,n,x,*it1-1,1);
		}
		else if(s[a[x]].size()>=2){
			change(1,1,n,*s[a[x]].begin(),s[a[x]].size());
			auto it1=it; it1++;
			if(it1==s[a[x]].end()){
				auto it2=it; it2--;
				add(1,1,n,*it2,x-1,1);
			}
		}
		printf("%d\n",n-t[1].sum-t[1].lmax-t[1].rmax);
	}
	return 0;
}