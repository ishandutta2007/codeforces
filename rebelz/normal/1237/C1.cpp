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

bool chkmax(int &x,int y){return x<y?x=y,true:false;}
bool chkmin(int &x,int y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct node{
	int x,y,z,id;
	bool operator<(const node c)const{
		if(z!=c.z) return z<c.z;
		if(x!=c.x) return x<c.x;
		return y<c.y;
	}
}a[50005],lst[50005];

int n,m;

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i].x=readint(),a[i].y=readint(),a[i].z=readint(),a[i].id=i;
	sort(a+1,a+n+1);
	node bef=a[1];
	for(int i=2;i<=n;i++){
		if(a[i].z!=bef.z) lst[++m]=bef,bef=a[i];
		else{
			while(i<n&&a[i].z==a[i+1].z&&a[i].x==a[i+1].x) printf("%d %d\n",a[i].id,a[i+1].id),i+=2;
			if(a[i].z==bef.z){
				printf("%d %d\n",bef.id,a[i].id);
				bef=a[i+1];
				i++;
			}
			else lst[++m]=bef,bef=a[i];
		}
	}
	if(m&1) lst[++m]=a[n];
	for(int i=1;i<=m;i+=2) printf("%d %d\n",lst[i].id,lst[i+1].id);
	return 0;
}