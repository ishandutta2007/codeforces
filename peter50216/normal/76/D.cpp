#include<stdio.h>
const int mask=(1<<24);
struct XD{
    int a[3];
    void operator+=(const XD& b){
	int i;
	for(i=0;i<3;i++)a[i]+=b.a[i];
	for(i=0;i<3;i++)if(a[i]>=mask){
	    a[i]-=mask;
	    a[i+1]++;
	}
    }
    int get(int k){
	return (a[k/24]>>(k%24))&1;
    }
    void set(int k,int c){
	a[k/24]-=(get(k)<<(k%24));
	a[k/24]+=(c<<(k%24));
    }
    void input(){
	unsigned long long x;
	scanf("%I64u",&x);
	a[0]=x%mask;
	a[1]=(x/mask)%mask;
	a[2]=x/mask/mask;
    }
}a,b,c;
int main(){
    a.input();
    b.input();
    c=a;
    c+=b;
    unsigned long long x=0,y=0;
    int i;
    try{
	if(c.get(0))throw "XD";
	for(i=0;i<64;i++){
	    if(c.get(i+1)==0){
		if(b.get(i))throw "XD";
	    }else{
		if(b.get(i))y+=(((unsigned long long)1)<<i);
		else{
		    x+=(((unsigned long long)1)<<i);
		    y+=(((unsigned long long)1)<<i);
		}
	    }
	}
	printf("%I64u %I64u\n",x,y);
    }catch(...){
	puts("-1");
    }
}