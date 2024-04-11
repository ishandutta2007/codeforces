#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=1e5+5;
int n,k;
map<int,int> cnt;
int cnt2[maxn];
struct node{
	int l,r;
	node* ch[2];
	int s,sum;
	node(int l,int r):l(l),r(r){
		if(l==r){
			s=cnt2[r];
			sum=r*cnt2[r];
			return;
		}
		int mid=l+(r-l)/2;
		ch[0]=new node(l,mid);
		ch[1]=new node(mid+1,r);
		s=ch[0]->s+ch[1]->s;
		sum=ch[0]->sum+ch[1]->sum;
	}
	void modify(int x,int k){
		s+=k;
		sum+=x*k;
		if(l==r) return;
		if(x<=ch[0]->r) ch[0]->modify(x,k);
		else ch[1]->modify(x,k);
	}
	int query(int x){
		if(l==r) return min(s,x/r);
		if(x<=ch[0]->sum) return ch[0]->query(x);
		else return ch[0]->s+ch[1]->query(x-ch[0]->sum);
	}
}*rt;
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		k=read();
		cnt.clear();
		for(int i=1;i<=n;i++) cnt[read()]++;
		for(int i=1;i<=n;i++) cnt2[i]=0;
		for(auto i:cnt) cnt2[i.second]++;
		rt=new node(1,n);
		int cnt3=0,ans=2e9;
		for(int i=0;i<=n&&cnt3<=k;i++){
			ans=min(ans,rt->s-rt->query(k));
			if(cnt[i]) rt->modify(cnt[i],-1);
			else cnt3++;
		}
		printf("%d\n",ans);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}