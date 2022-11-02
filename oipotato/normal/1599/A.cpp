#include<bits/stdc++.h>
using namespace std;
int n,a[200020],mi,ma,wh;
char ch[200020];
vector<int> ans;
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	scanf("%s",ch);
	mi=ma=1;
	ans.push_back(1);
	for (int i=1;i<n;i++){
		if (ch[i]!=ch[i-1]){
			ma++;
			ans.push_back(ma);
		}
		else{
			mi--;
			ans.push_back(mi);
		}
	}
	for (int i=0;i<n;i++){
		printf("%d ",a[ans[i]-mi]);
		if ((ans[i]&1)==(ma&1)){
			printf("%c\n",ch[n-1]);
		}
		else{
			if (ch[n-1]=='L') printf("R\n");
			else printf("L\n");
		}
	}
}