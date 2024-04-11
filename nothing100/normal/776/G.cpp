#include<bits/stdc++.h>
#define LL long long
#define mo 65535
using namespace std;
char ch[20];
int t,a[2000000];
LL ans,dp[20][20][1<<16],bo[20][20][1<<16];
LL f(int x,int y,int z){
	if (bo[x][y][z]) return dp[x][y][z];
	if (x==0){
		if (z&(1<<y)) dp[x][y][z]=1;
		bo[x][y][z]=1;
		return dp[x][y][z];
	}
	bo[x][y][z]=1;
	for (int i=0;i<16;i++) dp[x][y][z]+=f(x-1,max(y,i),a[(z<<4)+i]);
	return dp[x][y][z];
}
LL get(){
	LL res=0;
	int l=strlen(ch);
	int tmp=0,o,big=0;
    for (int i=0;i<l;i++){
		if (ch[i]>='0'&&ch[i]<='9') o=ch[i]-'0';
		else o=ch[i]-'a'+10;
		for (int j=0;j<o;j++){
			res+=dp[l-i-1][max(big,j)][a[(tmp<<4)+j]];
		}
		tmp=a[(tmp<<4)+o];
		big=max(big,o);
    }
    res+=dp[0][big][tmp];
    return res;
}
int check(){
	LL tmp=0,bit=0;
	for (int i=0;i<strlen(ch);i++){
		if (ch[i]>='0'&&ch[i]<='9'){
			tmp=tmp*16+ch[i]-'0';
			bit|=1<<(ch[i]-'0');
		}
		else{
			tmp=tmp*16+ch[i]-'a'+10;
			bit|=1<<(ch[i]-'a'+10);
		}
	}
	return tmp>(tmp^bit);
}
int main(){
	scanf("%d",&t);
	for (int i=0;i<65536*16;i++) a[i]=i&mo;
	f(16,0,0);
	while (t--){
		scanf("%s",ch);
		ans=0;
		ans-=get();
		ans+=check();
		scanf("%s",ch);
		ans+=get();
		printf("%lld\n",ans);
	}
}