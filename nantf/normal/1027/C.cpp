#include<bits/stdc++.h>
using namespace std;
int t,n,cnt[10010];
void read(int &x){
	char ch;
	while((ch=getchar()) && !isdigit(ch));
	x=ch^48;
	while((ch=getchar()) && isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48);
}
int main(){
	read(t);
	while(t--){
		memset(cnt,0,sizeof(cnt));
		read(n);
		for(int i=1;i<=n;i++){
			int x;
			read(x);
			cnt[x]++;
		}
		double minn=1e9;
		int ansi,ansj;
		for(int i=1;;){
			if(cnt[i]<2){
				i++;continue;
			}
			cnt[i]-=2;
			int j;
			for(j=i;cnt[j]<2 && j<=10000;j++);
			if(j>10000) break;
			double ans=8+4.0*(i*i+j*j)/(i*j);
			if(minn>ans) minn=ans,ansi=i,ansj=j;
			i=j;
		}
		printf("%d %d %d %d\n",ansi,ansi,ansj,ansj);
	}
}