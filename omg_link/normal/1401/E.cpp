#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MN 100000
#define BW 999999
typedef long long LL;

int n,m;

LL ans=1;

struct h_t{
	int y,tp,ed;
	bool operator < (const h_t &that)const{
		return this->y < that.y; 
	}
}h[MN+5];

struct v_t{
	int x,tp,ed;
	bool operator < (const v_t &that)const{
		if(this->tp != that.tp) return this->tp < that.tp;
		if(this->tp==0){
			return this->ed < that.ed;
		}else{
			return this->ed > that.ed;
		}
	}
}v[MN+5];

struct segmentTree{
	LL T[BW*4+5],tag[BW*4+5];
	void clear(){
		memset(T,0,sizeof(T));
		memset(tag,0,sizeof(tag));
	}
	void pushtag(int k,int l,int r,int w){
		T[k] += 1ll*w*(r-l+1);
		tag[k] += w;
	}
	void pushdown(int k,int l,int r){
		if(!tag[k]) return;
		int mid=(l+r)>>1;
		pushtag(k<<1,l,mid,tag[k]);
		pushtag(k<<1|1,mid+1,r,tag[k]);
		tag[k] = 0;
	}
	void update(int k){
		T[k] = T[k<<1] + T[k<<1|1];
	}
	void add(int k,int l,int r,int L,int R){
		if(l==L&&r==R){
			pushtag(k,l,r,1);
			return;
		}
		int mid=(l+r)>>1;
		pushdown(k,l,r);
		if(R<=mid) add(k<<1,l,mid,L,R);
		else if(L>mid) add(k<<1|1,mid+1,r,L,R);
		else add(k<<1,l,mid,L,mid),add(k<<1|1,mid+1,r,mid+1,R);
		update(k);
	}
	void add(int l,int r){
		add(1,1,BW,l,r);
	}
	LL query(int k,int l,int r,int p){
		if(l==r) return T[k];
		int mid=(l+r)>>1;
		pushdown(k,l,r);
		if(p<=mid) return query(k<<1,l,mid,p);
		else return query(k<<1|1,mid+1,r,p);
	}
	LL query(int p){
		return query(1,1,BW,p);
	}
}ST;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,l,r;i<=n;i++){
		scanf("%d%d%d",&h[i].y,&l,&r);
		if(l==0&&r==1000000){
			h[i].tp = 2;
			ans++;
		}else if(l==0){
			h[i].tp = 0;
			h[i].ed = r;
		}else if(r==1000000){
			h[i].tp = 1;
			h[i].ed = l;
		}else{
			puts("WTF");
		}
	}
	std::sort(h+1,h+1+n);
	for(int i=1,l,r;i<=m;i++){
		scanf("%d%d%d",&v[i].x,&l,&r);
		if(l==0&&r==1000000){
			v[i].tp = 2;
		}else if(l==0){
			v[i].tp = 0;
			v[i].ed = r;
		}else if(r==1000000){
			v[i].tp = 1;
			v[i].ed = l;
		}else{
			puts("WTF");
		}
	}
	std::sort(v+1,v+1+m);
	v[m+1].tp=233333333;
	int l=0,r=0;
	//tp=0
	if(v[r+1].tp==0){
		l=r+1,r=l;
		while(v[r+1].tp==0) r++;
		ST.clear();
		for(int i=l,j=0;i<=r;i++){
			while(j<n&&h[j+1].y<=v[i].ed){
				j++;
				if(h[j].tp==0){
					ST.add(1,h[j].ed);
				}else if(h[j].tp==1){
					ST.add(h[j].ed,BW);
				}else if(h[j].tp==2){
					ST.add(1,BW);
				}else{
					puts("WTF");
				}
			}
			ans += ST.query(v[i].x);
		}
	}
	//tp=1
	if(v[r+1].tp==1){
		l=r+1,r=l;
		while(v[r+1].tp==1) r++;
		ST.clear();
		for(int i=l,j=n+1;i<=r;i++){
			while(j>1&&h[j-1].y>=v[i].ed){
				j--;
				if(h[j].tp==0){
					ST.add(1,h[j].ed);
				}else if(h[j].tp==1){
					ST.add(h[j].ed,BW);
				}else if(h[j].tp==2){
					ST.add(1,BW);
				}else{
					puts("WTF");
				}
			}
			ans += ST.query(v[i].x);
		}
	}
	//tp=2
	if(v[r+1].tp==2){
		l=r+1,r=l;
		while(v[r+1].tp==2) r++;
		ST.clear();
		for(int j=1;j<=n;j++){
			if(h[j].tp==0){
				ST.add(1,h[j].ed);
			}else if(h[j].tp==1){
				ST.add(h[j].ed,BW);
			}else if(h[j].tp==2){
				ST.add(1,BW);
			}else{
				puts("WTF");
			}
		}
		for(int i=l;i<=r;i++){
			ans += ST.query(v[i].x)+1;
		}
	}
	printf("%lld\n",ans);
}