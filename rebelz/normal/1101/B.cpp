#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
char s[500005];

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int f1=-1,f2=-1,s1=-1,s2=-1;
	for(int i=1;i<=n;i++){
		if(s[i]=='['){
			f1=i;
			break;
		}
	}
	for(int i=n;i>=1;i--){
		if(s[i]==']'){
			f2=i;
			break;
		}
	}
	for(int i=f1+1;i<=f2-1;i++){
		if(s[i]==':'){
			s1=i;
			break;
		}
	}
	for(int i=f2-1;i>=s1+1;i--){
		if(s[i]==':'){
			s2=i;
			break;
		}
	}
	if(f1<0||f2<0||s1<0||s2<0||f1>f2) return printf("-1\n"),0;
	int cnt=0;
	for(int i=s1+1;i<=s2-1;i++) cnt+=(s[i]=='|');
	cout<<cnt+4<<endl;
	return 0;
}