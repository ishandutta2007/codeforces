#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int Maxn=1000005;
char s[Maxn];
int n;
int main(){
	scanf("%s",s);
	n=strlen(s);
	string ans;
	for (int i=0;i<n/4;i++){
		int a=i*2,b=a+1,c=n-a-1,d=c-1;
		if (s[a]==s[c] || s[a]==s[d]){
			ans+=s[a];
		}
		else{
			ans+=s[b];
		}
	}
	if (n%4<=1){
		string rr=ans;
		reverse(rr.begin(),rr.end());
		ans=ans+rr;
		printf("%s\n",ans.c_str());
		return 0;
	}
	string rr=ans;
	reverse(rr.begin(),rr.end());
	ans=ans+s[n/2]+rr;
	printf("%s\n",ans.c_str());
	return 0;
}