#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	char c=getchar();
	int s=0,x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*x;
}

int T,n,zs;
const int N=3e5+55;
char a[N];
int sta[N],stb[N],ca[N],cb[N],topa,topb;
bool flag;
signed main(){
//	cout<<read();
//	T=1;
	cin>>T;
	while(T--){
		scanf("%d",&n);
		scanf("%s",a+1);
		topa=topb=flag=0;
		for(int i=1;i<=n;i++){
			if(a[i]=='1')ca[++topa]=i;
			else cb[++topb]=i;
		}
		if(a[1]=='0' || a[n]=='0'){
			puts("NO");continue;
		} 
		if(n%2==1){
			puts("NO");continue;
		}
		if(topa%2==1)flag=1;
		for(int i=1;i<=topa/2;i++){
			sta[ca[i]]=stb[ca[i]]=1;
		}
		for(int i=topa/2+1;i<=topa;i++){
			sta[ca[i]]=stb[ca[i]]=2;
		}
		for(int i=1;i<=topb;i++){
			if(i%2==0){
				sta[cb[i]]=1;
				stb[cb[i]]=2;
			}
			else{
				sta[cb[i]]=2;
				stb[cb[i]]=1;
			}
		}
		int ss=0;
		for(int i=1;i<=n;i++){
			if(ss==0 and sta[i]==2)flag=1,ss--;
			else if(sta[i]==1)ss++;
			else ss--;
		}
		ss=0;
		for(int i=1;i<=n;i++){
			if(ss==0 and stb[i]==2)flag=1,ss--;
			else if(stb[i]==1)ss++;
			else ss--;
		}
		if(flag)puts("NO");
		else{
			puts("YES"); 
			for(int i=1;i<=n;i++){
				if(sta[i]==1)printf("(");
				else printf(")");
			}	
			puts("");
			for(int i=1;i<=n;i++){
				if(stb[i]==1)printf("(");
				else printf(")");
			}	
			puts("");
		}
		 
	}
	return 0;
}