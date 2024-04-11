#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
int in[310000];
long long jmp[551][551];//block step start
vector<pair<int,int> > que[551];
long long ansr[310000];
int main(){
    int n,i,j,k;
    scanf("%d",&n);
    int nn=(int)(sqrt(n)+1-1e-6);
    for(i=n-1;i>=0;i--)scanf("%d",&in[i]);
    int q,qq;
    scanf("%d",&q);
    for(qq=0;qq<q;qq++){
	int a,b;
	scanf("%d%d",&a,&b);
	a=n-a;
	long long ans=0;
	if(b>=nn){
	    int t=a%b;
	    while(t<=a){
		ans+=in[t];
		t+=b;
	    }
	    ansr[qq]=ans;
	}else{
	    que[b].push_back(make_pair(qq,a));
	}
    }
    for(j=1;j<nn;j++){
	if(que[j].empty())continue;
	for(i=0;i<nn;i++)for(k=0;k<nn;k++)jmp[i][k]=0;
	for(i=0;i<nn;i++){
	    int r=0;
	    for(k=0;k<nn;k++){
		jmp[i][r]+=in[i*nn+k];
		r=((r==j-1)?0:r+1);
	    }
	}
	for(k=0;k<que[j].size();k++){
	    int a=que[j][k].second;
	    int b=j;
	    int t=a%b;
	    long long ans=0;
	    for(i=0;i<a/nn;i++){
		ans+=jmp[i][t];
		t+=((nn+b-1)/b)*b-nn;
		while(t>=b)t-=b;
	    }
	    t+=(a/nn)*nn;
	    while(t<=a){
		ans+=in[t];
		t+=b;
	    }
	    ansr[que[j][k].first]=ans;
	}
    }
    for(i=0;i<q;i++)printf("%I64d\n",ansr[i]);
}