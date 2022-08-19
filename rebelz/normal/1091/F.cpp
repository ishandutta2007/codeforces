#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,g,w,ans;
ll a[100005];
char s[100005];
bool fw;

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='G'){
			if(w>=a[i]) ans+=2*a[i],w-=a[i],g+=2*a[i];
			else ans+=2*w,g+=a[i]+w,ans+=3*(a[i]-w),w=0;
		}
		else if(s[i]=='W'){
			w+=a[i];
			ans+=2*a[i];
			fw=true;
		}
		else{
			if(w==0&&g==0){
				if(fw) ans+=a[i]*3;
				else ans+=a[i]*5;
			}
			else if(w==0){
				if(g>=a[i]) g-=a[i],ans+=2*a[i];
				else if(fw) ans+=2*g+3*(a[i]-g),g=0;
				else ans+=2*g+5*(a[i]-g),g=0;
			}
			else{
				if(w>=a[i]) w-=a[i],ans+=a[i];
				else if(g>=a[i]-w) g-=a[i]-w,ans+=w+2*(a[i]-w),w=0;
				else ans+=w+2*g+3*(a[i]-w-g),w=g=0;
			}
			ans+=a[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}