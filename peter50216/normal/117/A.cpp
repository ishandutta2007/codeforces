#include<stdio.h>
#include<limits.h>
int s,f,t;
int n,m;
inline int solve(){
    if(s==f)return t;
    s--;f--;
    int t1=(t-s+2*m-3)/(2*m-2)*(2*m-2)+s;
    int t2=(t-(2*m-2-s)+2*m-3)/(2*m-2)*(2*m-2)+(2*m-2-s);
    if(t1>t2)t1=t2;
    int t3=(t1-f+2*m-3)/(2*m-2)*(2*m-2)+f;
    int t4=(t1-(2*m-2-f)+2*m-3)/(2*m-2)*(2*m-2)+(2*m-2-f);
    if(t3>t4)t3=t4;
    return t3;
}
int main(){
    scanf("%d%d",&n,&m);
    while(n--){
	scanf("%d%d%d",&s,&f,&t);
	printf("%d\n",solve());
    }
}