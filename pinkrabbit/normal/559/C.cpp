#include<bits/stdc++.h>
#define F(i,a,b) for(int i=(a);i<=(b);++i)
typedef long long ll;

const int Mod = 1000000007;
int h,w,n;
int frc[200001]={1,1},inv[200001]={1,1};
struct ff{
	int x,y;
}a[2005];
bool cmp(ff a,ff b){return a.x==b.x?a.y<b.y:a.x<b.x;}
int f[2005];
inline int C(int x,int y){
	return (ll)frc[x]*inv[y]%Mod*inv[x-y]%Mod;
}

int main(){
	for(int i=2;i<=200000;++i) frc[i]=frc[i-1]*(ll)i%Mod, inv[i]=(Mod-Mod/i)*(ll)inv[Mod%i]%Mod;
	for(int i=2;i<=200000;++i) inv[i]=(ll)inv[i-1]*inv[i]%Mod;
	scanf("%d%d%d",&h,&w,&n);
	F(i,1,n) scanf("%d%d",&a[i].x,&a[i].y);
	std::sort(a+1,a+n+1,cmp); a[n+1].x=h, a[n+1].y=w;
	F(i,1,n+1) f[i]=C(a[i].x+a[i].y-2,a[i].x-1); 
	F(i,1,n){
		F(j,i+1,n+1){
			if(a[j].x>=a[i].x&&a[j].y>=a[i].y){
				f[j]=((ll)f[j]-(ll)f[i]*C(a[j].x-a[i].x+a[j].y-a[i].y,a[j].x-a[i].x)%Mod+Mod)%Mod;
			}
		}
		f[i]=0;
	}
	printf("%d",f[n+1]);
	return 0;
}