#include <stdio.h>
#include <vector>
typedef std::vector<int> BLOCK;

int n;

struct OPT{
	int x,y;
};

std::vector<OPT> ol;

std::vector<BLOCK> bl;

void opt(int x,int y){
	ol.push_back((OPT){x,y});
}

void uniteBlock(BLOCK& b1,const BLOCK& b2){
	if(b1.size()!=b2.size())
		throw "error";
	for(int i=0;i<(int)b2.size();i++){
		opt(b1[i],b2[i]);
		b1.push_back(b2[i]);
	}
}

BLOCK subBlock(BLOCK& b,int size){
	if(size>(int)b.size())
		throw "error";
	BLOCK tmp;
	for(int i=0;i<size;i++){
		tmp.push_back(b.back());
		b.pop_back();
	}
	return tmp;
}

BLOCK formBlock(int l,int r){
	if(r-l==1){
		BLOCK b;
		b.push_back(l);
		return b;
	}
	int mid=(l+r)>>1;
	BLOCK b1 = formBlock(l,mid);
	BLOCK b2 = formBlock(mid,r);
	uniteBlock(b1,b2);
	return b1;
}

int main(){
	scanf("%d",&n);
	for(int i=0,s=1;s<=n;i++){
		if(n&(1<<i)){
			bl.push_back(formBlock(s,s+(1<<i)));
			s += (1<<i);
		}
	}
	for(int i=1;i<(int)bl.size()-1;i++){
		while(bl[0].size()!=bl[i].size()){
			uniteBlock(bl[0],subBlock(bl[bl.size()-1],bl[0].size()));
		}
		uniteBlock(bl[0],bl[i]);
	}
	printf("%d\n",(int)ol.size());
	for(int i=0;i<(int)ol.size();i++)
		printf("%d %d\n",ol[i].x,ol[i].y);
}