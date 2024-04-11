#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
struct qaq{int a,b,i;}s[100010];
ll pre[100010],suf[100010];
ll pre_mn[100010];
std::priority_queue<int,std::vector<int>,std::greater<int>>que;
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),p=gi(),k=gi();
	for(int i=1;i<=n;++i)s[i].a=gi(),s[i].b=gi(),s[i].i=i;
	std::sort(s+1,s+n+1,[](qaq a,qaq b){return a.b==b.b?a.a<b.a:a.b>b.b;});
	ll sum=0;
	for(int i=n;i>=n-(p-k)+2;--i)sum+=s[i].b;
	for(int i=n-(p-k)+1;i;--i)sum+=s[i].b,suf[i]=sum,sum-=s[i+(p-k)-1].b;
	sum=0;
	for(int i=1;i<=k;++i)sum+=s[i].a,que.push(s[i].a);
	for(int i=k;i<=n;++i){
		pre[i]=sum;pre_mn[i]=que.top();
		sum+=s[i+1].a,que.push(s[i+1].a);
		sum-=que.top(),que.pop();
	}
	ll ans=0,ANS1=0,ANS2=0;
	for(int i=k;i<=n-(p-k);++i)if(pre[i]>ANS1||(pre[i]==ANS1&&suf[i+1]>ANS2))ANS1=pre[i],ANS2=suf[i+1],ans=i;
	int cnt=k;
	for(int i=1;i<=ans;++i)if(cnt&&s[i].a>pre_mn[ans])--cnt,printf("%d ",s[i].i);
	for(int i=1;i<=ans;++i)if(cnt&&s[i].a==pre_mn[ans])--cnt,printf("%d ",s[i].i);
	for(int i=ans+1;i<=ans+p-k;++i)printf("%d ",s[i].i);
	return 0;
}