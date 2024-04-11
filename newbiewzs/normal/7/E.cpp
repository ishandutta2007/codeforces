#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define bc(x) __builtin_popcount(x)
#define fl fflush(stdout)
#define re register
#define il inline
#define pii pair<int,int>
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define mem0(x) memset(x,0,sizeof(x))
#define mem0x3f(x) memset(x,0x3f,sizeof(x))
// #pra gma GCC opti mize(3)
//#define int long long
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
namespace IO_BUFF{
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
	inline int gc(){
	    if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
	    return (HD==TL)?EOF:*HD++;
	}
	inline int inn(){
	    int x,ch;while((ch=gc())<'0'||ch>'9');x=ch^'0';
	    while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x;
	}
	char ss[19999999],tt[20];int ssl,ttl;
    inline int print(int x)
    {
        if(x<0)ss[++ssl]='-',x=(-x);
		if(!x) ss[++ssl]='0';for(ttl=0;x;x/=10) tt[++ttl]=char(x%10+'0');
        for(;ttl;ttl--) ss[++ssl]=tt[ttl];return ss[++ssl]='\n';
    }
	inline int Flush(){return fwrite(ss+1,sizeof(char),ssl,stdout),ssl=0,0;}
	int read(){
		char c=getchar();int x=1;int s=0;
		while(c<'0' || c>'9'){if(c=='-')x=-1;c=getchar();}
		while(c>='0' && c<='9'){
			s=s*10+c-'0';c=getchar();
		}
		return s*x;
	}
}using namespace IO_BUFF;
const int N=105;
map<string,int>ma;
int n,m;
string x,y,a;
int st[N],top,f[N];
int solve(string s){
	if(!s.length())return 1;
	bool fa=0;int add=0,mul=0;
	int len=s.length();top=0;
	for(int i=0;i<len;i++){
		if(s[i]=='('){
			st[++top]=i;
		}
		if(s[i]==')'){
			if(top){
				if(i==len-1 && st[top]==0)fa=1;
				top--;
			}
		}
		if(s[i]=='+' || s[i]=='-'){
			if(!top)add=i;
		}
		if(s[i]=='*' || s[i]=='/'){
			if(!top)mul=i;
		}
	}
	int ta,tb;
	if(fa){
		if(solve(s.substr(1,len-2))==-1)return -1;
		else return 1;
	}
	else if(add){
		ta=solve(s.substr(0,add));
		tb=solve(s.substr(add+1,len));
		if(s[add]=='+'){
			if(ta!=-1 && tb!=-1)return 2;
			return -1;
		}
		else{
			if(ta==-1 || tb==-1)return -1;
			if(tb==2)return -1;
			return 2;
		}
	}
	else if(mul){
		ta=solve(s.substr(0,mul));
		tb=solve(s.substr(mul+1,len));
		if(s[mul]=='*'){
			if(ta==-1 || tb==-1)return -1;
			if(ta==2 || tb==2)return -1;
			return 3;
		}
		else{
			if(ta==-1 || tb==-1)return -1;
			if((ta==3||ta==1) && tb==1)return 3;
			return -1;
		}
	}
	else if(ma[s]){
		return f[ma[s]];
	}
	return 1;
}
int main(){
	#ifdef newbiewzs
	#else
	#endif
	n=read();
	if(n==0){
		puts("OK");return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>x;y.clear();
		if(x.length()==1)cin>>x;
		cin>>x;char ch=getchar();
		while(ch!='\r' && ch!='\n'){
			if(ch!=' ')y+=ch;
			ch=getchar();
		}
		f[i]=solve(y);ma[x]=i;
	}
	char ch=getchar();
	while(ch!='\r' && ch!='\n' && ch!=EOF){
		if(ch!=' ')a+=ch;
		ch=getchar();
	}
	if(solve(a)==-1)puts("Suspicious");
	else puts("OK");
	return 0;
}