#include<bits/stdc++.h>
using namespace std;
int n,m,f[20020];
queue<int> q;
int main(){
	scanf("%d%d",&n,&m);
	q.push(n);
	memset(f,0x7f,sizeof(f));
	f[n]=0;
	while (!q.empty()){
		int tmp=q.front();
		q.pop();
		if (tmp>=m) f[m]=min(f[m],tmp-m+f[tmp]);
		else{
			if (f[tmp*2]>f[tmp]+1){
				f[tmp*2]=f[tmp]+1;
				q.push(tmp*2);
			}
			if (f[tmp-1]>20000){
				f[tmp-1]=f[tmp]+1;
				q.push(tmp-1);
			}
		}
	}
	printf("%d\n",f[m]);
}
//[4,19,14,5,-3,1,8,5,11,15]