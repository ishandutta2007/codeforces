#include <bits/stdc++.h>
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
int a[1005];
int main(){
	int n,x,ans=0;
	n=read();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			x=read();
			if(i==j)a[i]=x,ans+=x;
		}
	}
	ans%=2;
	int y,m;
	m=read();
	for(int i=0;i<m;i++){
		x=read();
		if(x!=3){
			y=read();
			if(a[y]){
				ans--;a[y]=0;
			}else{
				ans++;a[y]=1;
			}
			while(ans<0)ans+=2;
			ans%=2;
		}else{
			putchar((char)(ans+'0'));
		}
	}
	return 0;
}