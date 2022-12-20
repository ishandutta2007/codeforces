#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
typedef long long LL;

int n;
std::vector<int> p0,p1;

int A(LL x=1){
	if(x>n) return 0;
	printf("A %lld\n",x);
	fflush(stdout);
	int r;
	scanf("%d",&r);
	return r;
}

int B(LL x){
	if(x>n) return 0;
	printf("B %lld\n",x);
	fflush(stdout);
	int r;
	scanf("%d",&r);
	return r;
}

void C(int x){
	printf("C %d\n",x);
	fflush(stdout);
	exit(0);
}

bool isPrime(int x){
	for(int i=2;i*i<=x;i++){
		if(x%i==0) return false;
	}
	return true;
}

int main(){
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		if(isPrime(i)){
			if(i<=316)
				p0.push_back(i);
			else
				p1.push_back(i);
		}
	}
	int ans = 1;
	for(auto x:p0){
		B(x);
		for(int t=x;;t*=x){
			if(A(t)) ans *= x;
			else break;
		}
	}
	if(ans != 1){
			for(int i=0,snum=p1.size()+2;i<(int)p1.size();i+=100){
				for(int j=i;j<std::min(i+100,(int)p1.size());j++){
					if(A(1ll*ans*p1[j])) C(1ll*ans*p1[j]);
				}
			}
			C(ans);
		}else{
			for(int i=0,snum=p1.size()+1;i<(int)p1.size();i+=100){
				for(int j=i;j<std::min(i+100,(int)p1.size());j++){
					B(p1[j]);
				}
				snum -= std::min(100,(int)p1.size()-i);
				if(A()!=snum){
					for(int j=i;j<std::min(i+100,(int)p1.size());j++){
						if(A(p1[j])) C(p1[j]);
					}
				}
			}
			C(1);
		}
}