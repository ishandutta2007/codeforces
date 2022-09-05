#include<bits/stdc++.h>
using namespace std;

char s[100010];
int n,ql[100010],qr[100010],t[100010],rl,rr,ll,lr,cntl,cntr,pl,pr,ans,st,T[100010],t1[100010],t2[100010],t1n,t2n;
vector<int> vl,vr;

bool cmpR(int a,int b) {return (s[T[a]]=='L')<(s[T[b]]=='L');}
bool cmpL(int a,int b) {return (s[T[a]]=='R')<(s[T[b]]=='R');}

int main()
{
	scanf("%s",s),n=strlen(s),ans=0;
	rl=1,ll=1,lr=rr=0,cntl=cntr=0;
	for (int i=0; i<n; i++) t[i]=-1;
	for (int i=0; i<n; i++) 
		if (s[i]=='L')
		{
			cntl++;
			if (rl>rr) vl.push_back(i),ans++;
			else t[qr[rl++]]=i;
			ql[++lr]=i;
		} else
		{
			cntr++;
			if (ll>lr) vr.push_back(i),ans++;
			else t[ql[ll++]]=i;
			qr[++rr]=i;
		}
	printf("%d\n",ans-1);
	for (int i=0,sz=vl.size(); i<sz; i++) 
	{
		st=vl[i];
		while (t[st]!=-1) st=t[st];
		T[vl[i]]=st;
	}
	for (int i=0,sz=vr.size(); i<sz; i++) 
	{
		st=vr[i];
		while (t[st]!=-1) st=t[st];
		T[vr[i]]=st;
	}
	sort(vl.begin(),vl.end(),cmpR);
	sort(vr.begin(),vr.end(),cmpL);
	pl=pr=0;
	if (cntl>cntr) st=vl[pl++]; else 
	if (cntl<cntr) st=vr[pr++]; else
	{
		if (vl.size()&&s[T[vl[vl.size()-1]]]!='R') st=vl[pl++]; else 
		if (vr.size()&&s[T[vr[vr.size()-1]]]!='L') st=vr[pr++]; else
		{
			if (!vl.size()) st=vr[pr++]; else
			if (!vr.size()) st=vl[pl++]; else
			{
				t1[t1n=1]=vl[vl.size()-1];
				t2[t2n=1]=vr[vr.size()-1];
				while (t[t1[t1n]]!=-1) t1[t1n+1]=t[t1[t1n]],t1n++;
				while (t[t2[t2n]]!=-1) t2[t2n+1]=t[t2[t2n]],t2n++;
				if (t1[t1n]>t2[t2n]) t[t1[t1n-1]]=-1,t[t2[t2n]]=t1[t1n];
				else t[t2[t2n-1]]=-1,t[t1[t1n]]=t2[t2n];
				st=vl[pl++];
			}
		}
	}
	while (1) 
	{
		printf("%d ",st+1);
		if (t[st]==-1)
		{
			if (s[st]=='L') {if (pr<vr.size()) t[st]=vr[pr++]; else break;}
			else {if (pl<vl.size()) t[st]=vl[pl++]; else break;}
		}
		st=t[st];
	}
	return puts(""),0;
}