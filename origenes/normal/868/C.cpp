#include <bits/stdc++.h>
using namespace std;
int n, k;
bool flag[16];
int main(){
	scanf("%d%d", &n, &k);
	while(n--){
		int a[4], tmp=0;
		for(int i=0; i<k; i++)
			scanf("%d", &a[i]);
		for(int i=0; i<k; i++)
			if(a[i]) tmp+=1<<i;
		flag[tmp]=true;
	}
	if(flag[0])
		return puts("YES");
	for(int i=1; i<(1<<k-1); i++)
		for(int j=i+1; j<(1<<k)-1; j++)
			if(!(i&j))
				if(flag[i]&&flag[j])
					return puts("YES");
	return puts("NO");
}