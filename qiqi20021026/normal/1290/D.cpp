#include<bits/stdc++.h>
using namespace std;

int read();

int n,m,l,s,cnt; bool bo[1109];

void clr(){ puts("R"); fflush(stdout); }

bool check(int x){
	char ch[9]; printf("? %d\n",x); fflush(stdout); scanf("%s",ch); return ch[0]=='Y';	
}

int main(){
	scanf("%d%d",&n,&l);
	int i,j,k;
	if (l==1){
		for (i=1; i<n; i++)
			for (j=i+1; j<=n; j++){
				clr();
				check(i); if (check(j)) bo[j]=1;
			}
	}
	else{
		s=l/2; m=n/s;
		for (i=1; i<=m; i++)
			for (j=1; j<=i && j+i<=m; j++){
				clr();
				for (k=j; k<=m; k+=i)
					for (int x=(k-1)*s+1; x<=k*s; x++) if (check(x)) bo[x]=1;
			}
	}
	int ans=0;
	for (i=1; i<=n; i++) ans+=(!bo[i]);
	printf("! %d\n",ans); fflush(stdout);
	return 0;
}

int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}