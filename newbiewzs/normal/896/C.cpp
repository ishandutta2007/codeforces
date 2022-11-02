#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<set>
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define int long long
#define ci ios::sync_with_stdio(false)
//#define int long long
using namespace std;
typedef long long ll;
const int N=1e5+55;
const int moo=1e9+7;
int ret,seed,op,l,r,x,y;
int rnd(){
	ret=seed;
	seed=(1ll*seed*7%moo+13)%moo;
	return ret;
}
int n,m,mod,a[N];
struct node{
	int l,r;
	mutable int v;
	friend bool operator < (node x,node y){
		return x.l<y.l;
	}
};
set<node>s;
int ksm(int x,int k,int mo){
	int base=1;
	while(k){
		if(k&1)base=1ll*base*x%mo;
		x=1ll*x*x%mo;
		k>>=1;
	}
	return base;
}
set<node>::iterator split(int pos){
	set<node>::iterator it;
	it=s.lower_bound(node{pos,0,0});
	if(it->l == pos and it!=s.end())return it;
	it--;
	int l=it->l;
	int r=it->r;
	int val=it->v;
	s.erase(it);
	s.insert((node){l,pos-1,val});
	it=s.insert((node){pos,r,val}).fi;
	return it;
}
void assign(int l,int r,int val){
	set<node>::iterator it1,it2;
	it1=split(l);it2=split(r+1);
	s.erase(it1,it2);
	s.insert((node){l,r,val});
}
void add(int l,int r,int val){
	set<node>::iterator it1,it2;
	it1=split(l);it2=split(r+1);
	for(;it1!=it2;it1++){
		it1->v+=val;
	}
}
int top;
struct stt{
	int len,val;
}st[N];
int cmp(stt x,stt y){
	return x.val<y.val;
}
int kth(int l,int r,int x){
	set<node>::iterator it1,it2;
	it1=split(l);it2=split(r+1);
	top=0;
	for(;it1!=it2;it1++){
		st[++top]={it1->r-it1->l+1,it1->v};
	}
	sort(st+1,st+top+1,cmp);
	for(int k=1;k<=top;k++){
		if(x<=st[k].len){
			return st[k].val;
		}
		x-=st[k].len;
	}
}
int sum(int l,int r,int x,int mo){
	set<node>::iterator it1,it2;
	it1=split(l);it2=split(r+1);
	int ans=0;
	for(;it1!=it2;it1++){
		ans=(ans+1ll*ksm((it1->v)%mo,x,mo)*(it1->r-it1->l+1)%mo)%mo;
	}
	return ans;
}
signed main(){
	cin>>n>>m>>seed>>mod;
	for(int i=1;i<=n;i++){
		a[i]=(rnd()%mod)+1;
		node z={i,i,a[i]};
		s.insert(z);
	}
	s.insert(node{n+1,n+1,-1});
	int js=0;
	for(int i=1;i<=m;i++){
		op=(rnd()%4)+1;
		l=(rnd()%n)+1;
		r=(rnd()%n)+1;
		if(l>r)swap(l,r);
		if(op==3){
			x=(rnd()%(r-l+1))+1;
			js++;
		}
		else{
			x=(rnd()%mod)+1;
		}
		if(op==4 and js==100){
			new char;
		}
		if(op==4){
			y=(rnd()%mod)+1;
			js++;
		}
		if(js==158){
			new char;
		}
		if(op==1)add(l,r,x);
		if(op==2)assign(l,r,x);
		if(op==3)printf("%lld\n",kth(l,r,x));
		if(op==4)printf("%lld\n",sum(l,r,x,y));
	}
	return 0;
}