#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,ans;
char a[1000001];
int s1,s2;
int main(){
	cin>>t;
	while(t--){
		scanf("%s",a+1);
		n=strlen(a+1);
		ans=s1=s2=0;
		for(int i=1;i<=n;i++){
			if(a[i]=='(') s1++;
			else if(a[i]=='[') s2++;
			else if(a[i]==')'){
				if(s1) ans++,s1--;
			}
			else if(s2) ans++,s2--;
		}
		cout<<ans<<endl;
	}
}