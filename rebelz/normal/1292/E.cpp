#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
char a[55];

void init(){
	for(int i=1;i<=n;i++) a[i]='?';
}

bool nothing(){
	for(int i=1;i<=n;i++) if(a[i]!='?') return false;
	return true;
}

char turn(char c){
	return c=='a'?'C':c=='b'?'H':'O';
}

void print(){
	cout<<"! ";
	for(int i=1;i<=n;i++) printf("%c",turn(a[i]));
	cout<<endl;
	fflush(stdout);
}

void ask(string s){
	for(int i=0;i<s.size();i++) if(s[i]=='?') s[i]=a[i+1];
	cout<<"? ";
	for(int i=0;i<s.size();i++) printf("%c",turn(s[i]));
	cout<<endl;
	fflush(stdout);
	int m=readint();
	if(m==-1) exit(0);
	for(int i=1;i<=m;i++){
		int x=readint();
		for(int j=x;j<x+s.size();j++) a[j]=s[j-x];
	}
}

void corner_case(){
	ask("aa"),ask("ab"),ask("ac"),ask("bc");
	if(nothing()){
		ask("ccc"),ask("cbb");
		if(nothing()){
			ask("bbba"),ask("bbbb");
			if(nothing()) cout<<"! OOHC"<<endl,fflush(stdout);
			else print();
		}
		else{
			if(a[1]=='?'){
				ask("a???"),ask("b???");
				if(a[1]=='?') a[1]='c',print();
				else print();
			}
			else if(a[4]=='?'){
				ask("???a"),ask("???b");
				if(a[4]=='?') a[4]='c',print();
				else print();
			}
			else print();
		}
	}
	else{
		int cnt=0;
		for(int i=1;i<=4;i++) if(a[i]=='?') cnt++;
		if(cnt==0) print();
		else if(cnt==1){
			int pl=0;
			for(int i=1;i<=4;i++) if(a[i]=='?') pl=i;
			string tmp="????";
			for(int i=0;i<4;i++) tmp[i]=a[i+1];
			tmp[pl-1]='a';
			ask(tmp);
			tmp[pl-1]='b';
			ask(tmp);
			if(a[pl]=='?') a[pl]='c';
			print();
		}
		else{
			if(a[2]=='?'){
				string tmp="???";
				tmp[1]=a[3],tmp[2]=a[4];
				tmp[0]='a';
				ask(tmp);
				tmp[0]='b';
				ask(tmp);
				if(a[2]=='?') a[2]='c';
				tmp="????";
				for(int i=0;i<4;i++) tmp[i]=a[i+1];
				tmp[0]='a';
				ask(tmp);
				tmp[0]='b';
				ask(tmp);
				if(a[1]=='?') a[1]='c';
				print();
			}
			else if(a[3]=='?'){
				string tmp="???";
				tmp[0]=a[1],tmp[1]=a[2];
				tmp[2]='a';
				ask(tmp);
				tmp[2]='b';
				ask(tmp);
				if(a[3]=='?') a[3]='c';
				tmp="????";
				for(int i=0;i<4;i++) tmp[i]=a[i+1];
				tmp[3]='a';
				ask(tmp);
				tmp[3]='b';
				ask(tmp);
				if(a[4]=='?') a[4]='c';
				print();
			}
			else{
				string tmp="???";
				tmp[1]=a[2],tmp[2]=a[3];
				tmp[0]='a';
				ask(tmp);
				tmp[0]='b';
				ask(tmp);
				if(a[1]=='?') a[1]='c';
				tmp="????";
				for(int i=0;i<4;i++) tmp[i]=a[i+1];
				tmp[3]='a';
				ask(tmp);
				tmp[3]='b';
				ask(tmp);
				if(a[4]=='?') a[4]='c';
				print();
			}
		}
	}
}

void work(int n){
	ask("aa"),ask("ab"),ask("ac"),ask("bc"),ask("cb");
	for(int i=1;i<n-1;i++){
		if(a[i]=='c'&&a[i+1]=='?') a[i+1]='c';
		if(a[i]=='b'&&a[i+1]=='?') a[i+1]='b';
	}
	string tmp;
	tmp.resize(n-1);
	for(int i=0;i<n-1;i++) tmp[i]=a[i+1];
	for(int i=0;i<n-1;i++) if(tmp[i]=='?') tmp[i]='b';
	ask(tmp);
	if(a[1]=='?') for(int i=0;i<n-1;i++) if(a[i+1]=='?') a[i+1]='c';
	tmp.resize(n);
	for(int i=0;i<n;i++) tmp[i]=a[i+1];
	tmp[n-1]='a';
	ask(tmp);
	if(a[n]=='?') a[n]=a[n-1]=='c'?'c':'b';
	print();
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		init();
		if(n==4) corner_case();
		else work(n);
		int x=readint();
		if(!x) return 0;
	}
	return 0;
}