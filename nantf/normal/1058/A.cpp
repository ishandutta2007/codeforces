#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(x) return puts("HARD"),0;
	}
	puts("EASY");
}