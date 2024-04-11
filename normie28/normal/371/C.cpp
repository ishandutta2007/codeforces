#include<bits/stdc++.h>
using namespace std;
int main(){
	char s[105];scanf("%s",s);
	int len=strlen(s),num[5]={0};
	for(int i=0;i<len;i++){
		if(s[i]=='B')num[1]++;
		if(s[i]=='C')num[2]++;
		if(s[i]=='S')num[3]++;
	}
	int nb,nc,ns;scanf("%d %d %d",&nb,&ns,&nc);
	int pb,pc,ps;scanf("%d %d %d",&pb,&ps,&pc);
	long long int r;scanf("%lld",&r);
	long long int ans=0;
	int Max=0,i=-1;
	if(num[1]!=0)
		Max=max(Max,nb/num[1]);
	if(num[2]!=0)
		Max=max(Max,nc/num[2]);
	if(num[3]!=0)
		Max=max(Max,ns/num[3]);
	for(;i<100;i++){
		if((i+1)*num[1]<=nb && (i+1)*num[2]<=nc && (i+1)*num[3]<=ns)continue;
		if((i+1)*num[1]>nb){
			r+=(nb-(i+1)*num[1])*pb;
			nb=(i+1)*num[1];
		}
		if(r<0)break;
		if((i+1)*num[2]>nc){
			r+=(nc-(i+1)*num[2])*pc;
			nc=(i+1)*num[2];
		}
		if(r<0)break;
		if((i+1)*num[3]>ns){
			r+=(ns-(i+1)*num[3])*ps;
			ns=(i+1)*num[3];
		}
		if(r<0)break;
	}
	ans=i;
	ans+=r/(pb*num[1]+pc*num[2]+ps*num[3]);
	cout << ans << endl;
	return 0;
}