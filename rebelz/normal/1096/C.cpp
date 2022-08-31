#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int t,n;

int main(){
	t=readint();
	while(t--){
		n=readint();
		bool flag=true;
		for(int i=180;i>=1;i--){
			if(360%i==0&&(1.0*n/(1.0*i/2)==(int)(1.0*n/(1.0*i/2)))&&180-i>=n){//360/i
				printf("%d\n",360/i); flag=false;
				break;
			}
		}
		if(flag) printf("-1\n");
	}
	return 0;
}