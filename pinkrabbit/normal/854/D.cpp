#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#define F(i,a,b) for(int i=a;i<=b;++i)
#define dF(i,a,b) for(int i=a;i>=b;--i)
#define F2(i,a,b) for(int i=a;i<b;++i)
using namespace std;
int n,m,k,d[100001],f[100001],t[100001],c[100001],I[100001];
inline int Min(int x,int y){return x<y?x:y;}
inline long long Min(long long x,long long y){return x<y?x:y;}
inline bool cmp(int p1,int p2){return d[p1]<d[p2];}
int Dep[100001],Depnum,Arr[100001],Arrnum;
int Minmeet=-1,Maxmeet=-1,Mini,Maxi;
int CityD[100001],CityA[100001];
long long MinDC[100001],MinAC[100001],Ans=9999999999999999ll;
void init(){
	scanf("%d%d%d",&n,&m,&k);
	F(i,1,m) scanf("%d%d%d%d",d+i,f+i,t+i,c+i),I[i]=i;
	sort(I+1,I+m+1,cmp);
//	puts("====");
//	F(i,1,m) printf("%d %d %d %d\n",d[I[i]],f[I[i]],t[I[i]],c[I[i]]);
//	puts("====");
}
int main(){
	init();
	F(i,1,m){
		if(t[I[i]]==0){
			CityD[f[I[i]]]=Min(CityD[f[I[i]]],c[I[i]]);
			if(!Dep[f[I[i]]])
				CityD[f[I[i]]]=c[I[i]], Dep[f[I[i]]]=1, ++Depnum;
		}
		if(Depnum==n) {Minmeet=d[I[i]]+1; Mini=i; break;}
	}
	dF(i,m,1){
		if(f[I[i]]==0){
			CityA[t[I[i]]]=Min(CityA[t[I[i]]],c[I[i]]);
			if(!Arr[t[I[i]]])
				CityA[t[I[i]]]=c[I[i]], Arr[t[I[i]]]=1, ++Arrnum;
		}
		if(Arrnum==n) {Maxmeet=d[I[i]]-1; Maxi=i; break;}
	}
//	printf("Meeting: %d - %d\n",Minmeet,Maxmeet);
	if(Minmeet==-1||Maxmeet==-1||Maxmeet-Minmeet+1<k) {puts("-1"); return 0;}
	F(i,1,n) MinDC[Mini]+=CityD[i];
	F(i,1,n) MinAC[Maxi]+=CityA[i];
	F(i,Mini+1,m){
		MinDC[i]=MinDC[i-1];
		if(t[I[i]]==0)
			if(CityD[f[I[i]]]>c[I[i]]) MinDC[i]-=CityD[f[I[i]]]-c[I[i]], CityD[f[I[i]]]=c[I[i]];
	}
	dF(i,Maxi-1,1){
		MinAC[i]=MinAC[i+1];
		if(f[I[i]]==0)
			if(CityA[t[I[i]]]>c[I[i]]) MinAC[i]-=CityA[t[I[i]]]-c[I[i]], CityA[t[I[i]]]=c[I[i]];
	}
//	F(i,Mini,m) printf("%I64d ",MinDC[i]); puts("");
//	F(i,1,Maxi) printf("%I64d ",MinAC[i]); puts("");
	for(int i=Mini,j=Mini;i<=Maxi&&j<=Maxi;++i){
		while(j<=Maxi&&d[I[j]]-d[I[i]]-1<k) ++j;
		if(j>Maxi) break;
		Ans=Min(Ans,MinDC[i]+MinAC[j]);
	}
	cout<<Ans;
	return 0;
}