#include<stdio.h>
#include<algorithm>
#include<queue>
using namespace std;
char in[50010];
struct XD{
    int pc,id;
    XD(int pp,int ii):pc(pp),id(ii){}
    bool operator<(const XD& b)const{
	return pc>b.pc;
    }
};
priority_queue<XD> que;
int main(){
    scanf("%s",in);
    int i;
    long long ans=0;
    int d=0;
    for(i=0;in[i];i++){
	if(in[i]=='(')d++;
	else if(in[i]==')')d--;
	else{
	    int a,b;
	    scanf("%d%d",&a,&b);
	    in[i]=')';
	    ans+=b;
	    que.push(XD(a-b,i));
	    d--;
	}
	if(d<0){
	    if(que.empty())break;
	    d+=2;
	    in[que.top().id]='(';
	    ans+=que.top().pc;
	    que.pop();
	}
    }
    if(in[i]||d)puts("-1");
    else{
	printf("%I64d\n%s\n",ans,in);
    }
}