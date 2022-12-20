#include <stdio.h>
#include <map>
#define MN 200000
typedef long long LL;

int n;
int tp[MN+5],d[MN+5];

LL tot;

int vn=0;
std::map<int,int> vti;
int itv[MN+5];

struct node{
	int c[2],ct;
	LL st;
	node operator + (const node &that)const{
		node ret;
		ret.c[0] = this->c[0] + that.c[0];
		ret.c[1] = this->c[1] + that.c[1];
		ret.ct = this->ct + that.ct;
		ret.st = this->st + that.st;
		return ret;
	}
}T[MN*4+5];

void update(int k){
	T[k].c[0] = T[k<<1].c[0] + T[k<<1|1].c[0];
	T[k].c[1] = T[k<<1].c[1] + T[k<<1|1].c[1];
	T[k].ct = T[k<<1].ct + T[k<<1|1].ct;
	T[k].st = T[k<<1].st + T[k<<1|1].st;
}

void add(int k,int l,int r,int p,int w,int tp){
	if(l==r){
		T[k].c[tp] += w;
		T[k].ct += w;
		T[k].st += w*itv[l];
		return;
	}
	int mid=(l+r)>>1;
	if(p<=mid) add(k<<1,l,mid,p,w,tp);
	else add(k<<1|1,mid+1,r,p,w,tp);
	update(k); 
}

node queryMax(int k,int x){
	if(x==0) throw "queryMax: x=0";
	if(x==T[k].ct) return T[k];
	if(x>T[k<<1|1].ct) return queryMax(k<<1,x-T[k<<1|1].ct)+T[k<<1|1];
	else return queryMax(k<<1|1,x);
}

int findKth1(int k,int l,int r,int rk){
	if(rk==0) throw "findKth1: rk=0";
	if(l==r) return itv[l];
	int mid=(l+r)>>1;
	if(rk>T[k<<1|1].c[1]) return findKth1(k<<1,l,mid,rk-T[k<<1|1].c[1]);
	else return findKth1(k<<1|1,mid+1,r,rk);
}

int findFirst0(int k,int l,int r){
	if(T[k].c[0]==0) return 0;
	if(l==r) return itv[l];
	int mid=(l+r)>>1;
	if(T[k<<1|1].c[0]) return findFirst0(k<<1|1,mid+1,r);
	else return findFirst0(k<<1,l,mid);
}

int main(){
	try{
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&tp[i],&d[i]);
			if(d[i]>0) vti[d[i]]=-1;
		}
		for(auto &p:vti){
			p.second = (++vn);
			itv[vn] = p.first;
		}
		for(int i=1,tc=0;i<=n;i++){
			if(d[i]>0){
				add(1,1,vn,vti[d[i]],1,tp[i]);
				if(tp[i]) tc++;
				tot += d[i];
			}else{
				d[i] = -d[i];
				add(1,1,vn,vti[d[i]],-1,tp[i]);
				if(tp[i]) tc--;
				tot -= d[i];
			}
			if(tc){
				node x = queryMax(1,tc);
				if(x.c[0]==0){
					int v1 = findKth1(1,1,vn,tc);
					int v2 = findFirst0(1,1,vn);
					printf("%lld\n",tot+x.st-v1+v2);
				}else{
					printf("%lld\n",tot+x.st);
				}
			}else{
				printf("%lld\n",tot);
			}
		}
	}catch(const char* err){
		fputs("[Error]\n",stderr);
		fputs(err,stderr);
		return 1;
	}
}