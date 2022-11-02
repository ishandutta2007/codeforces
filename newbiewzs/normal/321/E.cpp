#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<map>
#include<ctime>
#include<bitset>
#include<set>
#define fi first
#define se second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define pil pair<int,long long>
#define pll pair<long long,long long>
#define vi vector<int>
#define vl vector<long long>
#define ci ios::sync_with_stdio(false)
//#define int long long
using namespace std;
typedef long long ll;
const int N=4005;
int n,m,id,a[N][N],s[N][N],f[N][808];
#define mid ((l+r)>>1)
int js(int x,int y){
	return (s[y][y]+s[x-1][x-1]-s[x-1][y]-s[y][x-1])/2;
}
namespace INPUT_SPACE{
	const int BS=(1<<24)+5;char Buffer[BS],*HD,*TL;
    inline int gc()
    {
        if(HD==TL) TL=(HD=Buffer)+fread(Buffer,1,BS,stdin);
        return (HD==TL)?EOF:*HD++;
    }
	inline int inn()
    {
        int x,ch;while((ch=gc())<'0'||ch>'9');x=ch^'0';
        while((ch=gc())>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^'0');return x;
    }
}using INPUT_SPACE::inn;
void cdq(int l,int r,int L,int R){
	
	f[mid][id]=1e9;
	int MID;
	for(int i=L;i<=min(mid,R);i++){
		if(f[i-1][id-1]+js(i,mid)<f[mid][id]){
			f[mid][id]=f[i-1][id-1]+js(i,mid);
			MID=i;
		}
	}
	if(l==r){
		return ;
	}
	cdq(l,mid,L,MID);
	cdq(mid+1,r,MID,R);
}
int main(){
	n=inn();m=inn();
	for(int i=1;i<=n;i++)for(int k=1;k<=n;k++)a[i][k]=inn(),s[i][k]=s[i-1][k]+s[i][k-1]-s[i-1][k-1]+a[i][k];
	for(int i=1;i<=n;i++){
		f[i][0]=1e9;
	}
	for(int i=1;i<=m;i++){
		id=i;
		cdq(1,n,1,n);
	}
	cout<<f[n][m];
	return 0;
}