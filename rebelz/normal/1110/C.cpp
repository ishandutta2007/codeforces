#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int q,n,fl,ans;
int d[]={0,0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401};

int gcd(int x,int y){
	if(y==0) return x;
	return gcd(y,x%y);
}

int main(){
	q=readint();
	while(q--){
		n=readint();
		fl=0;
		for(int i=1;i<=25;i++) if(n==(1<<i)-1) fl=i;
		if(!fl){
			for(int i=1;i<=25;i++) if(n>=(1<<i)&&n<(1<<(i+1))) ans=(1<<(i+1))-1;
			cout<<ans<<endl;
		}
		else{
			cout<<d[fl]<<endl;
		}
	}
	return 0;
}