#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll d[20][15][5],b[20];

ll work(ll x){
	memset(d,0,sizeof(d));
	int len=0; ll ret=0;
	for(;x;b[++len]=x%10,x/=10);
	reverse(b+1,b+len+1);
	d[0][0][1]=1;
	for(int i=0;i<=len-1;i++)
		for(int j=0;j<=9;j++)
			for(int c=0;c<=1;c++)
				for(int num=0;num<=(c?b[i+1]:9);num++)
					d[i+1][j+(num!=0)][c&(num==b[i+1])]+=d[i][j][c];
	for(int j=0;j<=3;j++) ret+=d[len][j][0]+d[len][j][1];
	return ret;
}

int main(){
	ll t,l,r;
	t=readint();
	while(t--){
		l=readint(); r=readint();
		cout<<work(r)-work(l-1)<<endl;
	}
	return 0;
}