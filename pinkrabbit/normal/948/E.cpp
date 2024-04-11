#include<bits/stdc++.h>
#define F(i,a,b) for(int i=a;i<=(b);++i)
using namespace std;

char str1[100005],str2[100005];
int len1,len2;
int sbc1[100005],sbc2[100005];
int sua1[100005],sua2[100005];
int Q;

int main(){
	scanf("%s%s",str1+1,str2+1);
	len1=strlen(str1+1), len2=strlen(str2+1);
	F(i,1,len1) sbc1[i]=sbc1[i-1]+(str1[i]=='B'||str1[i]=='C');
	F(i,1,len2) sbc2[i]=sbc2[i-1]+(str2[i]=='B'||str2[i]=='C');
	F(i,1,len1) sua1[i]=str1[i]=='A'?sua1[i-1]+1:0;
	F(i,1,len2) sua2[i]=str2[i]=='A'?sua2[i-1]+1:0;
	scanf("%d",&Q);
	while(Q--){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int sumbc1=sbc1[b]-sbc1[a-1], sumbc2=sbc2[d]-sbc2[c-1];
		int sufa1=min(sua1[b],b-a+1), sufa2=min(sua2[d],d-c+1);
		if((sumbc1&1)!=(sumbc2&1)||sumbc1>sumbc2||sufa1<sufa2) {putchar('0'); continue;}
		if(sumbc1==sumbc2)
			if(sufa1%3==sufa2%3) putchar('1');
			else putchar('0');
		else
			if(sumbc1==0) putchar(sufa1>sufa2?'1':'0');
			else putchar('1');
	}
	return 0;
}