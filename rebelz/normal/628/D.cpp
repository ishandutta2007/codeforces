#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
int m,k;
ll d[2005][2005][2];

ll mod(ll x){return x>=cys?x-cys:x;}

ll solve(char *s){
	int l=strlen(s+1);
	memset(d,0,sizeof(d));
	d[0][0][1]=1;
	for(int i=0;i<l;i++){
		for(int j=0;j<m;j++){
			for(int c=0;c<=1;c++){
				if((i+1)%2==0&&(c?s[i+1]-'0':9)>=k) d[i+1][(j*10+k)%m][c&(k==s[i+1]-'0')]=mod(d[i+1][(j*10+k)%m][c&(k==s[i+1]-'0')]+d[i][j][c]);
				else if((i+1)%2==1){
					for(int num=0;num<=(c?s[i+1]-'0':9);num++){
						if(num!=k) d[i+1][(j*10+num)%m][c&(num==s[i+1]-'0')]=mod(d[i+1][(j*10+num)%m][c&(num==s[i+1]-'0')]+d[i][j][c]);
					}
				}
			}
		}
	}
	ll ret=mod(d[l][0][0]+d[l][0][1]);
//	cout<<ret<<endl;
	return ret;
}

char s[2005],t[2005];

int main(){
	m=readint(); k=readint();
	scanf("%s%s",s+1,t+1);
	int l=strlen(s+1);
	bool fl=true;
	for(int i=1;i<=l;i++) if(s[i]==k+'0'&&i%2!=0) fl=false;
	for(int i=1;i<=l;i++) if(s[i]!=k+'0'&&i%2==0) fl=false;
	ll now=0;
	for(int i=1;i<=l;i++) now=(now*10+s[i]-'0')%cys;
	if(now%m) fl=false;
	cout<<(solve(t)-solve(s)+fl+cys)%cys<<endl;
	return 0;
}