#include<stdio.h>
#include<algorithm>
using namespace std;
int p[4];
inline int f(int x){return x%p[0]%p[1]%p[2]%p[3];}
inline int solve(int i){
    int x=0;
    do{
	if(f(i)==i)x++;
    }while(next_permutation(p,p+4));
    return x>=7;
}
int main(){
    int i,a,b;
    for(i=0;i<4;i++)scanf("%d",p+i);
    sort(p,p+4);
    scanf("%d%d",&a,&b);
    int ans=0;
    for(i=a;i<=b;i++)if(solve(i))ans++;
    printf("%d\n",ans);
}