#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct node{int x,y;};
int n,D;ll m;
bool operator<(const node&a,const node&b){return a.x<b.x;}
std::set<node>st;
std::set<node>::iterator it;
bool cxk(node a,node _,node c){
	ll k=c.y-a.y,b=(ll)a.y*(c.x-a.x)-(ll)k*a.x;
	return(ll)_.y*(c.x-a.x)>=k*_.x+b;
}
void insert(int x,int y){
	static node o,pr,nx;
	o={x,y};
	if(st.empty()){st.insert(o);return;}
	it=st.lower_bound(o);
	if(it!=st.end()){
		if(it->x==x){
			if(y<it->y)st.erase(it),st.insert(o);
			return;
		}
		nx=*it;
		if(it!=st.begin()){
			pr=*--it;
			if(cxk(pr,o,nx))return;
		}
	}
	while(1){
		it=st.lower_bound(o);
		if(it!=st.begin()){
			nx=*--it;
			if(it!=st.begin())pr=*--it;
			else break;
		}else break;
		if(!cxk(pr,nx,o))break;
		st.erase(++it);
	}
	while(1){
		it=st.lower_bound(o);
		if(it!=st.end()){
			pr=*it++;
			if(it!=st.end())nx=*it;
			else break;
		}else break;
		if(!cxk(o,pr,nx))break;
		st.erase(--it);
	}
	st.insert(o);
}
int main(){
	n=gi(),m=gi();
	st.insert({0,0});int x,a,b,k=0;
	for(int i=1;i<=n;++i){
		x=gi();a=gi(),b=gi();
		a=(a+k)%1000000+1,b=(b+k)%1000000+1;
		if(x==1)insert(a,b);
		else{
			bool flg=0;
			auto it=st.lower_bound({(b+a-1)/a,0});
			if(it==st.end()||it==st.begin())goto ed;
			{
				node nx=*it,pr=*--it;
				ll lk=nx.y-pr.y,lb=(ll)pr.y*(nx.x-pr.x)-lk*pr.x;
				if((ll)m*(nx.x-pr.x)>=lk*b+lb*a)flg=1;
			}
			ed:
			if(flg)puts("YES"),k=i;
			else puts("NO");
		}
	}
	return 0;
}