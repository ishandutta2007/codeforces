#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define per(i,a,b) for(int i=(b)-1;i>=(a);i--)
using namespace std;
const int N=(int)2e5+9;
int vis[N],L[N],R[N],color[N],cnt;
char s[N],ans[N];
int main()
{
	int n,k,tot=0;
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	int l=0,r=0,flag=1;
	rep(i,1,n)if(s[i]==s[i-1]){
		flag=0;
		break;
	}
	if(flag&&(~n&1)){
		if(k&1)rep(i,0,n)ans[i]=(s[i]=='W')?'B':'W';
		else rep(i,0,n)ans[i]=(s[i]=='B')?'B':'W';
		printf("%s",ans);
		return 0;
	}
	int last=n; 
	per(i,1,n)if(s[i]==s[0])l=i,vis[i]=1,ans[i]=s[i],tot++,last=i;
	else break;
	if(l==1){
		printf("%s",s);
		return 0;
	}
	rep(i,1,n){
		if(vis[i])break;
		vis[i]=1;
		if(s[i]==s[l]){
			tot++;
			r=i;
		}
		else if(tot){
			L[cnt]=l;
			R[cnt]=r;
			color[cnt]=s[l];
			tot=0;
			if(l>r){
				rep(j,0,r+1)ans[j]=s[l];
			}
			else {
				rep(j,l,r+1)ans[j]=s[l];
			}
			l=i;
			cnt++;
		}
		else{
			l=i;
		}
	}
	if(tot){
		L[cnt]=l;
		R[cnt]=last-1;
		color[cnt]=s[l];
		rep(i,l,last)ans[i]=s[l];
		cnt++;
	}
//	rep(i,0,n)cout<<ans[i];
//	cout<<"ans\n";
	L[cnt]=L[0];
	if(L[cnt]<R[cnt-1])L[cnt]+=n;
	color[cnt]=color[0];
	rep(i,1,cnt+1){
		int len=L[i]-R[i-1]-1;
	//	cout<<len<<"len\n";
		if(len&1){
			len>>=1;
			if(len>=k){
				rep(j,R[i-1]+1,R[i-1]+1+k)ans[j%n]=color[i];
				per(j,L[i]-k,L[i])ans[j%n]=color[i];
				int t=0;
				rep(j,R[i-1]+1+k,L[i]-k){
					if(t&1)ans[j%n]=color[i];
					else ans[j%n]=(color[i]=='W')?'B':'W';
					t++;
				}
			}
			else {
				rep(j,R[i-1]+1,L[i])ans[j%n]=color[i];
			}
		}
		else{
			len>>=1;
			if(len>=k){
				rep(j,R[i-1]+1,R[i-1]+1+k)ans[j%n]=color[i-1];
				per(j,L[i]-k,L[i])ans[j%n]=color[i];
				int t=0;
				rep(j,R[i-1]+1+k,L[i]-k){
					if(t&1)ans[j%n]=color[i-1];
					else ans[j%n]=(color[i-1]=='W')?'B':'W';
					t++;
				}
			}
			else {
				rep(j,R[i-1]+1,R[i-1]+1+len)ans[j%n]=color[i-1];
				per(j,L[i]-len,L[i])ans[j%n]=color[i];
			}
		}
	//	cout<<ans[1]<<"??\n";
	}
	printf("%s",ans);
 }