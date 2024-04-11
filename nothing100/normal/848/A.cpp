#include<bits/stdc++.h>
#define LL long long
#define mo 1000000007
using namespace std;
int k;
int main() {
	scanf("%d",&k);
		for (int i=0;i<26;i++){
			for (int j=0;j<=k;j++){
				printf("%c",'a'+i);
				k-=j;
			}
		}
}