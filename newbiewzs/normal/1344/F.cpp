#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<queue>
#include<map>
#include<vector>
#include<set>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define vi vector<int>
//#define int long long
using namespace std;
typedef long long ll;
int read(){
	char c=getchar();int s=0;int x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=1005;
int n,m,l,a[N],tr[257],x[N],y[N];
char op[6],c[2];
struct node{
	int c[3][3];
	node friend operator * (node x,node y){
		node z;memset(z.c,0,sizeof(z.c));
		for(int i=1;i<=2;i++){
			for(int k=1;k<=2;k++){
				for(int j=1;j<=2;j++){
					z.c[i][k]=(z.c[i][k]+1ll*x.c[i][j]*y.c[j][k])%2;
				}
			}
		}
		return z;
	}
}t[N],RY,RB,YB;
int top,you[N*2],w[N*2];
bitset<N*2>zuo[N*2];
int main(){
	n=read();m=read();tr['R']=1,tr['Y']=2,tr['B']=3,tr['W']=tr['.']=0;
	for(int i=1;i<=n;i++)t[i].c[1][1]=t[i].c[2][2]=1;
	RY.c[1][2]=RY.c[2][1]=1;
	RB.c[1][1]=RB.c[1][2]=RB.c[2][2]=1;
	YB.c[1][1]=YB.c[2][2]=YB.c[2][1]=1;
	for(int i=1;i<=m;i++){
		scanf("%s",op+1);l=read();for(int k=1;k<=l;k++)a[k]=read();
		if(op[1]=='m'){
			scanf("%s",c+1);
			top++;
			for(int k=1;k<=l;k++){
				int pos=a[k];
				if(t[pos].c[1][1]==1)zuo[top][pos]=1;
				if(t[pos].c[2][1]==1)zuo[top][pos+n]=1;
			}
			you[top]=tr[(int)c[1]]&1;
			top++;
			for(int k=1;k<=l;k++){
				int pos=a[k];
				if(t[pos].c[1][2]==1)zuo[top][pos]=1;
				if(t[pos].c[2][2]==1)zuo[top][pos+n]=1;
			}
			you[top]=((tr[(int)c[1]]&2)>0);
		}
		else if(op[1]=='R' and op[2]=='Y'){
			for(int k=1;k<=l;k++)t[a[k]]=t[a[k]]*RY;
		}
		else if(op[1]=='R' and op[2]=='B'){
			for(int k=1;k<=l;k++)t[a[k]]=t[a[k]]*RB;
		}
		else if(op[1]=='Y' and op[2]=='B'){
			for(int k=1;k<=l;k++)t[a[k]]=t[a[k]]*YB;
		}
	}
	int head=1;
	for(int i=1;head<=top && i<=2*n;i++){
		for(int k=head;k<=top;k++){
			if(zuo[k][i]){
				swap(zuo[head],zuo[k]);
				swap(you[head],you[k]);
				break;
			}
		}
		if(!zuo[head][i])continue;
		for(int k=1;k<=top;k++){
			if(zuo[k][i] and k!=head){
				zuo[k]^=zuo[head];
				you[k]^=you[head];
			}
		}
		head++;
	}
	for(int k=head;k<=top;k++){
		if(you[k]){
			cout<<"NO";
			return 0;
		}
	}
	for(int k=1;k<=top;k++){
		int tou=1;
		for(;tou<=2*n && !zuo[k][tou];tou++);
		w[tou]=you[k];
	}
	puts("YES");
	for(int i=1;i<=n;i++){
		int val=((w[i])|(w[i+n]<<1));
		if(!val)cout<<".";
		if(val==1)cout<<"R";
		if(val==2)cout<<"Y";
		if(val==3)cout<<"B";
	}
	return 0;
}