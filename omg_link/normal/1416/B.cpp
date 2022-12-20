#include <stdio.h>
#include <vector>
#define MN 10000

int n,sum,a[MN+5];

struct opt{
	int i,j,x;
	opt(int i=0,int j=0,int x=0){
		this->i = i;
		this->j = j;
		this->x = x;
	}
};
std::vector<opt> ans;

void addOpt(int i,int j,int x){
	ans.push_back(opt(i,j,x));
	int t = i*x;
	a[i] -= t;
	a[j] += t;
	if(a[i]<0)
		throw "err1";
}

void solve(){
	scanf("%d",&n);
	sum = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	if(sum%n){
		puts("-1");
		return;
	}
	ans.clear();
	int avg = sum/n;
	for(int i=2;i<=n;i++){
		addOpt(1,i,(i-a[i]%i)%i);
		addOpt(i,1,a[i]/i);
	}
	for(int i=2;i<=n;i++)
		addOpt(1,i,avg);
	for(int i=1;i<=n;i++)
		if(a[i]!=a[1])
			throw "err2";
	printf("%d\n",(int)ans.size());
	for(auto x:ans){
		printf("%d %d %d\n",x.i,x.j,x.x);
	}
}

int main(){
	//try{
		int T; scanf("%d",&T);
		while(T--) solve();
	//}catch(const char *err){
	//	puts(err);
	//}
}