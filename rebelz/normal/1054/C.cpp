#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int l,r,s,id;
	bool operator<(const node c)const{
		return s<c.s;
	}
}k[1005];

int n;
int l[1005],r[1005],t[1005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) k[i].l=readint();
	for(int i=1;i<=n;i++) k[i].r=readint();
	for(int i=1;i<=n;i++) l[i]=k[i].l,r[i]=k[i].r,k[i].s=k[i].l+k[i].r,k[i].id=i;
	sort(k+1,k+n+1);
	int now=n; bool flag=true;
	for(int i=1;i<=n;i++){
		if(k[i].s==k[i-1].s) t[k[i].id]=now;
		else now--,t[k[i].id]=now;
	}
//	for(int i=1;i<=n;i++) cout<<k[i].s<<' ';
//	cout<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++) if(t[j]>t[i]) l[i]--;
		for(int j=i+1;j<=n;j++) if(t[j]>t[i]) r[i]--;
		if(l[i]!=0||r[i]!=0) return cout<<"NO"<<endl,0;
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++) cout<<t[i]<<' ';
	cout<<endl;
	return 0;
}