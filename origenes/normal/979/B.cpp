#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=123456;
const string ans[]={"Kuro", "Shiro", "Katie"};
char s[3][maxn];
int cnt[3][256], mmax[3];
int n;
int main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(nullptr);
	cin>>n;
	scanf("%s%s%s", s[0], s[1], s[2]);
	int len=strlen(s[0]);
	for(int i=0; i<3; i++){
		for(int j=0; j<len; j++){
			cnt[i][s[i][j]-'A']++;
		}
	}
	for(int i=0; i<3; i++)
		for(int j=0; j<256; j++)
			mmax[i]=max(mmax[i], cnt[i][j]);
	for(int i=0; i<3; i++){
		if(mmax[i]==len&&n==1){
			mmax[i]--;
		}else{
			mmax[i]+=n;
		}
		mmax[i]=min(mmax[i], len);
	}
	int p=0;
	bool flag=false;
	for(int i=1; i<3; i++){
		if(mmax[i]>mmax[p]){
			p=i;
			flag=false;
		}
		else if(mmax[i]==mmax[p]) flag=true;
	}
	if(flag) puts("Draw");
	else{
		cout<<ans[p]<<endl;
	}
	return 0;
}