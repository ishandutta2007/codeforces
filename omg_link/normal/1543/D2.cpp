#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,k;

struct Digit{
	int x;
	Digit(){
		x = 0;
	}
	Digit(int x){
		this->x = x;
	}
	Digit operator + (const Digit& that)const{
		return Digit((this->x+that.x)%k);
	}
	Digit operator - (const Digit& that)const{
		return Digit((this->x-that.x+k)%k);
	}
};

struct Number{
	Digit d[20];
	Number(){
		memset(d,0,sizeof(d));
	}
	Number(int x){
		for(int i=0;i<20;i++){
			d[i] = Digit(x%k);
			x /= k;
		}
	}
	Number operator + (const Number& that)const{
		Number ret;
		for(int i=0;i<20;i++){
			ret.d[i] = this->d[i]+that.d[i];
		}
		return ret;
	}
	Number operator - (const Number& that)const{
		Number ret;
		for(int i=0;i<20;i++){
			ret.d[i] = this->d[i]-that.d[i];
		}
		return ret;
	}
	int toInt()const{
		int base = 1;
		int ret = 0;
		for(int i=0;i<20&&base<=20000000;i++,base*=k){
			ret += d[i].x*base;
		}
		return ret;
	}
};

bool check(int x){
	printf("%d\n",x);
	fflush(stdout);
	scanf("%d",&x);
	if(x==-1) exit(0);
	return x;
}

void solve(){
	scanf("%d%d",&n,&k);
	Number tmp(0);
	bool sgn = 0;
	for(int i=0;i<n;i++){
		Number guess;
		Number ni(i);
		if(sgn) guess = tmp-ni;
		else guess = tmp+ni;
		tmp = guess-tmp;
		sgn = !sgn;
		if(check(guess.toInt())) return;
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}