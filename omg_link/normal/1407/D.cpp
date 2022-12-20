#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stack>
#define MN 300000

int n,a[MN+5],f[MN+5];
std::stack<int> in,de;

int main(){
	memset(f,0x7f,sizeof(f));
	scanf("%d",&n);
	f[1] = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		while((!in.empty())&&a[i]<a[in.top()]){
			f[i] = std::min(f[i],f[in.top()]+1);
			in.pop();
		}
		if(!in.empty()){
			f[i] = std::min(f[i],f[in.top()]+1);
			if(a[i]==a[in.top()]) in.pop();
		}
		in.push(i);
		while((!de.empty())&&a[i]>a[de.top()]){
			f[i] = std::min(f[i],f[de.top()]+1);
			de.pop();
		}
		if(!de.empty()){
			f[i] = std::min(f[i],f[de.top()]+1);
			if(a[i]==a[de.top()]) de.pop();
		}
		de.push(i);
	}
	printf("%d\n",f[n]);
}