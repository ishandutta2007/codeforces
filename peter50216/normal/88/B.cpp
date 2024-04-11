#include<stdio.h>
#include<string.h>
int can[30],canb[30];
char in[33][33];
char tmp[500010];
int main(){
    int n,m,i,j,k,l;
    int x;
    scanf("%d%d%d",&n,&m,&x);
    for(i=0;i<n;i++)scanf("%s",in[i]);
    bool hass=0;
    for(i=0;i<n;i++){
	for(j=0;j<m;j++){
	    if(in[i][j]=='S'){
		hass=1;
		for(k=0;k<n;k++){
		    for(l=0;l<m;l++){
			if((k-i)*(k-i)+(l-j)*(l-j)<=x*x&&in[k][l]!='S'){
			    canb[in[k][l]-'a']=1;
			}
		    }
		}
	    }else{
		can[in[i][j]-'a']=1;
	    }
	}
    }
    int q;
    scanf("%d%s",&q,tmp);
    int ans=0;
    for(i=0;i<q;i++){
	if(tmp[i]>='A'&&tmp[i]<='Z'){
	    if(!hass)break;
	    if(canb[tmp[i]-'A']){
	    }else if(can[tmp[i]-'A']){
		ans++;
	    }else break;
	}else{
	    if(can[tmp[i]-'a']){
	    }else break;
	}
    }
    if(i<q)puts("-1");
    else printf("%d\n",ans);
}