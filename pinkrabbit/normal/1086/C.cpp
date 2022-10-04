#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)

int n,q,m,k;
char a[3000005],b[3000005],s[3000005];
char t[205];

int p[26],ip[26];

inline bool Get(int i,int a,int b=-2){
	if(b==-2)b=a;
	F(j,a,b)if(ip[j]==-1){p[i]=j;ip[j]=i;return 1;}
	return 0;
}

inline void Print(){
	puts("YES");
	F(i,0,k){
		if(p[i]==-1)Get(i,0,k);
		printf("%c",p[i]+'a');
	}puts("");
/*	F2(i,0,n)t[i]=p[s[i]-'a']+'a';
	int ok1=1,ok2=1;
	F2(i,0,n)if(t[i]<a[i]){ok1=0;break;}else if(t[i]>a[i])break;
	F2(i,0,n)if(t[i]>b[i]){ok2=0;break;}else if(t[i]<b[i])break;
	if(!ok1||!ok2)puts("GG");*/
}

bool s1(int now){
//	printf("1now=%d\n",now);
	if(now==n){
		Print();
		return 1;
	}
	int x=s[now]-'a';
	if(~p[x]){
		if(p[x]<a[now]-'a')return 0;
		else if(p[x]==a[now]-'a'){return s1(now+1);}
		else{Print();return 1;}
	}
	if(Get(x,a[now]-'a'+1,k)){Print();return 1;}
	if(!Get(x,a[now]-'a'))return 0;
	return s1(now+1);
}

bool s2(int now){
//	printf("2now=%d\n",now);
	if(now==n){
		Print();
		return 1;
	}
	int x=s[now]-'a';
	if(~p[x]){
		if(p[x]>b[now]-'a')return 0;
		else if(p[x]==b[now]-'a'){return s2(now+1);}
		else{Print();return 1;}
	}
	if(Get(x,0,b[now]-'a'-1)){Print();return 1;}
	if(!Get(x,b[now]-'a'))return 0;
	return s2(now+1);
}

void sol(int now){
//	printf("now=%d\n",now);
	if(now==n){
		Print();
		return;
	}
	int x=s[now]-'a';
	if(~p[x]){
		if(p[x]<a[now]-'a'||p[x]>b[now]-'a'){puts("NO");return;}
		else{
			if(a[now]==b[now]){sol(now+1);return;}
			else if(p[x]==a[now]-'a'){
				if(s1(now+1))return;
				else{puts("NO");return;}
			}
			else if(p[x]==b[now]-'a'){
				if(s2(now+1))return;
				else{puts("NO");return;}
			}
			else{Print();return;}
		}
	}
	else if(a[now]==b[now]){
		if(Get(x,a[now]-'a')){sol(now+1);return;}
		else{puts("NO");return;}
	}
	else if(a[now]<b[now]-1){
		if(Get(x,a[now]-'a'+1,b[now]-'a'-1)){Print();return;}
	}
	int tp[26],itp[26];
	F(i,0,k)tp[i]=p[i],itp[i]=ip[i];
	if(Get(x,a[now]-'a'))if(s1(now+1))return;
	F(i,0,k)p[i]=tp[i],ip[i]=itp[i];
	if(Get(x,b[now]-'a'))if(s2(now+1))return;
	puts("NO");
}

int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%d",&k);--k;
		scanf("%s%s%s",s,a,b);
		n=strlen(s);
		int ok=1;
		for(int i=0;i<n;++i)if(a[i]>b[i]){ok=0;break;}else if(a[i]<b[i])break;
		if(!ok){puts("NO");continue;}
		memset(p,-1,sizeof p);
		memset(ip,-1,sizeof ip);
		sol(0);
	}
	return 0;
}