#include<stdio.h>
#include<algorithm>
using namespace std;
int id[55];
int sc[55];
char na[55][1000];
inline int gn(){int n;scanf("%d",&n);return n;}
inline int cmp(int a,int b){return sc[a]>sc[b];}
int main(){
    int n=gn();
    int i;
    for(i=0;i<n;i++){
	scanf("%s",na[i]);
	sc[i]+=100*gn();
	sc[i]+=-50*gn();
	sc[i]+=gn();
	sc[i]+=gn();
	sc[i]+=gn();
	sc[i]+=gn();
	sc[i]+=gn();
	id[i]=i;
    }
    sort(id,id+n,cmp);
    printf("%s\n",na[id[0]]);
}