#include <stdio.h>
#include <map>
int n,k,nn;
struct data{
	int n,k;
	bool operator < (const data &that)const{
		if(n != that.n) return n < that.n;
		return k < that.k;
	}
};
std::map<data,data> can;

bool isFull(int x){
	x++;
	while((x&1)==0){
		x>>=1;
	}
	return x==1;
}

bool search(int n,int k){
	if(n<0 || k<0) return false;
	if(k==0) return isFull(n);
	if(k==1) return !isFull(n);
	if(can.find(data{n,k}) != can.end()) return true;
	if(n-2>=2&&search(n-2,k-1)&&search(1,0)){
		can[data{n,k}] = data{n-2,k-1};
		return true;
	}
	if(n-4>=6&&search(n-4,k-1)&&search(3,0)){
		can[data{n,k}] = data{n-4,k-1};
		return true;
	}
	for(int dn=0;dn<=n/3;dn++){
		if(n-dn>dn*2&&search(n-dn,k-1)&&search(dn,1)){
			can[data{n,k}] = data{n-dn,k-1};
			return true;
		}
	}
	return false;
}

void buildTree(int n,int rt){
	int bsc = nn;
	printf("%d ",rt);
	for(int i=2;i<=n;i++){
		printf("%d ",(i>>1)+bsc);
	}
	nn += n;
}

void show(int n,int k,int rt){
	if(n<0 || k<0) throw "n<0 || k<0";
	if(k==0){
		if(isFull(n)){
			buildTree(n,rt);
			return;
		}else throw "k=0 but not full";
	}
	if(k==1){
		if(isFull(n)) throw "k=1 but full";
		else{
			buildTree(n,rt);
			return;
		}
	}
	if(can.find(data{n,k}) == can.end()) throw "wtf?";
	data ls = can[data{n,k}];
	data rs = data{n-1-ls.n,k-1-ls.k};
	printf("%d ",rt);
	int me = ++nn;
	show(ls.n,ls.k,me);
	show(rs.n,rs.k,me);
}

void no(){
	puts("NO");
	exit(0);
}

int main(){
	try{
		scanf("%d%d",&n,&k);
		if((n&1)==0) no();
		if(k>std::max(0,(n-3)/2)) no();
		if(search(n,k)){
			puts("YES");
			show(n,k,0);
		}else{
			puts("NO");
		}
	}catch(const char *err){
		puts("---------[ERROR]---------");
		printf("%s",err);
		return 3;
	}
}