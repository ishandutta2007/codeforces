#include <stdio.h>
#include <algorithm>
#include <vector>
#define MN 100000

int n,tn;
int p[MN+5],pc[MN+5],cp;

void print(int mask,int pos,int res,bool flag){
	if(pos>cp){
		if(!flag)
			printf("%d ",res);
		return;
	}
	if(mask&(1<<(pos-1))){
		for(int i=1,tmp=p[pos];i<=pc[pos];i++,tmp*=p[pos]){
			if(i<pc[pos])
				print(mask,pos+1,res*tmp,false);
			else
				print(mask,pos+1,res*tmp,flag);
		}
	}else{
		print(mask,pos+1,res,flag);
	}
}

void putbin(int x){
	for(int i=cp;i>=0;i--){
		printf("%d",x&(1<<i)?1:0);
	}
}

void putall(int x,bool flag=false){
	print(x,1,1,flag);
}


void bitroll(int pos,std::vector<int> &v,int mask=0,int re=0){
	for(auto &x:v) x<<=1;
	if(pos==cp-2){
		if(!re){
			putall((mask<<3)|1);
			putall((mask<<3)|3);
			putall((mask<<3)|2);
			putall((mask<<3)|6);
			putall((mask<<3)|4);
			for(auto x:v)
				putall(x<<2);
			v.clear();
			putall((mask<<3)|7);
			putall((mask<<3)|5);
		}else{
			putall((mask<<3)|5);
			putall((mask<<3)|7);
			for(auto x:v)
				putall(x<<2);
			v.clear();
			putall((mask<<3)|4);
			putall((mask<<3)|6);
			putall((mask<<3)|2);
			putall((mask<<3)|3);
			putall((mask<<3)|1);
		}
	}else{
		if(!re){
			bitroll(pos+1,v,mask<<1,0);
			v.push_back(mask<<1|1);
			bitroll(pos+1,v,mask<<1|1,1);
		}else{
			v.push_back(mask<<1|1);
			bitroll(pos+1,v,mask<<1|1,0);
			bitroll(pos+1,v,mask<<1,1);
		}
	}
}

void solve(){
	scanf("%d",&n);
	tn = n;
	cp = 0;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			p[++cp] = i;
			pc[cp] = 0;
			while(n%i==0){
				n /= i;
				pc[cp]++;
			}
		}
	}
	if(n!=1){
		p[++cp] = n;
		pc[cp] = 1;
	}
	if(cp==1){
		putall(1);
		puts("\n0");
		return;
	}
	if(cp==2){
		if(pc[1]==1&&pc[2]==1){
			printf("%d %d %d",p[1],p[2],p[1]*p[2]);
			puts("\n1");
		}else{
			if(pc[2]>pc[1]){
				std::swap(p[2],p[1]);
				std::swap(pc[2],pc[1]);
			}
			putall(2);
			putall(3,true);
			putall(1);
			printf("%d",tn);
			puts("\n0");
		}
		return;
	}
	if(cp>2){
		bitroll(1,*new std::vector<int>);
		puts("\n0");
		return;
	}
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}