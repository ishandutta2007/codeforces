#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
int n,f[300030],fi[300030],pos,ans,l,r,q[300030];
char ch[300030];
pair<int,int> mi;
int main(){
	scanf("%d",&n);
	scanf("%s",ch);
	mi=make_pair(0,0);
	for (int i=0;i<n;i++){
		if (ch[i]=='(') f[i+1]=f[i]+1;
		else f[i+1]=f[i]-1;
		if (f[i+1]<mi.fi){
			mi=make_pair(f[i+1],1);
			pos=i+1;
		}
		else if (f[i+1]==mi.fi) mi.se++;
	}
	if (f[n]!=0){
		printf("0\n1 1\n");
		return 0;
	}
	ans=mi.second;
	l=r=0;
	int tail=0,tmp=0;
	q[tail]=0;
	for (int i=pos;i<n;i++){
		if (ch[i]=='('){
			tmp++;
			q[++tail]=1;
			fi[tail]=i;
		}
		else{
			if (tmp==1&&q[tail]>ans){
				ans=q[tail];
				l=fi[tail];
				r=i;
			}
			else if (tmp==2&&mi.se+q[tail]>ans){
				ans=mi.se+q[tail];
				l=fi[tail];
				r=i;
			}
			tmp--;
			q[--tail]+=1;
		}
	}
	for (int i=0;i<pos;i++){
		if (ch[i]=='('){
			tmp++;
			q[++tail]=1;
			fi[tail]=i;
		}
		else{
			if (tmp==1&&q[tail]>ans){
				ans=q[tail];
				l=fi[tail];
				r=i;
			}
			else if (tmp==2&&mi.se+q[tail]>ans){
				ans=mi.se+q[tail];
				l=fi[tail];
				r=i;
			}
			tmp--;
			q[--tail]+=1;
		}
	}
	printf("%d\n%d %d\n",ans,l+1,r+1);
}