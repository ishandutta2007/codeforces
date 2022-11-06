#include <cstdio>
#include <algorithm>
using namespace std;
const int Maxn=100;
int n;
int a[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		int flag=1;
		int last=0,pos;
		while(1){
			pos=0;
			for(int j=1;j<=n;j++){
				if(j==last||a[j]==0){
					continue;
				}
				if(pos==0||a[j]>a[pos]){
					pos=j;
				}
			}
			if(pos==0){
				break;
			}
			flag^=1;
			last=pos;
			a[pos]--;
		}
		if(flag==1){
			puts("HL");
		}
		else{
			puts("T");
		}
	}
	return 0;
}