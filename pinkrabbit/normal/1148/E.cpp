#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
int n;
int a[MN],b[MN],p[MN];
ll s[MN];
int stk[MN],t;
int q1[MN],q2[MN],q3[MN],q;
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),p[i]=i;
	F(i,1,n)scanf("%d",b+i);
	sort(p+1,p+n+1,[](int i,int j){return a[i]<a[j];});
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	F(i,1,n)a[i]=b[i]-a[i];
	F(i,1,n)s[i]=s[i-1]+a[i];
	F(i,1,n)if(s[i]<0)return puts("NO"),0;
	if(s[n])return puts("NO"),0;
	F(i,1,n){
		if(a[i]>0)stk[++t]=i;
		if(a[i]<0){
			int d=-a[i];
			while(t&&a[stk[t]]<=d)q1[++q]=stk[t],q2[q]=i,d-=q3[q]=a[stk[t--]];
			if(d)q1[++q]=stk[t],q2[q]=i,a[stk[t]]-=q3[q]=d;
		}
	}
	printf("YES\n%d\n",q);
	F(i,1,q)printf("%d %d %d\n",p[q1[i]],p[q2[i]],q3[i]);
	return 0;
}