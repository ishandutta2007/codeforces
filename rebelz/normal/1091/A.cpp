#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int y,b,r;

int main(){
	cin>>y>>b>>r;
	cout<<3*min(r-2,min(b-1,y))+3<<endl;
	return 0;
}