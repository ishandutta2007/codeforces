#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int s[5007],h[5007],f[5007],l[5007],r[5007];
long long brl[5007],brr[5007],bro[5007];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<m;i++) cin>>f[i]>>h[i];
	for(int i=0;i<m;i++)
	{
		int c=h[i],t=-1;
		while(c && t<n) {t++; if(s[t]==f[i]) c--;}
		if(t==n) l[i]=-1;
		else l[i]=t;
		c=h[i]; t=n;
		while(c && t>=0) {t--; if(s[t]==f[i]) c--;}
		if(t==-1) r[i]=-1;
		else r[i]=t;
	}
	int res=0; long long sol=1;
	for(int i=0;i<m;i++) if(l[i]!=-1)
	{
		int t=0; long long br=1;
		for(int j=0;j<=n;j++) brl[j]=brr[j]=bro[j]=0;
		for(int j=0;j<m;j++) if(i!=j) if(r[j]!=-1)
		{
			if(l[j]<l[i]) brl[f[j]]++;
			if(r[j]>l[i]) brr[f[j]]++;
			if(l[j]<l[i] && r[j]>l[i]) bro[f[j]]++;
		}
		brl[f[i]]=1; bro[f[i]]=0;
		for(int j=1;j<=n;j++) if(brl[j]) t++;
		for(int j=1;j<=n;j++) if(brr[j]) t++;
		for(int j=1;j<=n;j++) if(brl[j]==1 && bro[j]==1 && brr[j]==1) t--;
		if(t>res) {res=t; sol=0;} 
		if(t==res) 
		{
			for(int j=1;j<=n;j++) if(brl[j] || brr[j])
			{
				if(!brl[j]) {br=(br*brr[j])%MOD; continue;}
				if(!brr[j]) {br=(br*brl[j])%MOD; continue;}
				if(brl[j]==1 && brr[j]==1 && bro[j]==1) {br=(br*2)%MOD; continue;}
				br=(br*((brl[j]*brr[j]-bro[j])%MOD))%MOD;
			}
			sol=(sol+br)%MOD;
		}
	}
	int t=0; long long br=1;
	for(int j=0;j<=n;j++) brl[j]=brr[j]=bro[j]=0;
	for(int j=0;j<m;j++) if(r[j]!=-1) brr[f[j]]++;
	for(int j=1;j<=n;j++) if(brr[j]) t++;
	if(t>res) {res=t; sol=0;} 
	if(t==res) 
	{
		for(int j=1;j<=n;j++) if(brr[j]) br=(br*brr[j])%MOD;
		sol=(sol+br)%MOD;
	}
	if(res==0) sol=1;
	cout<<res<<" "<<sol;
}