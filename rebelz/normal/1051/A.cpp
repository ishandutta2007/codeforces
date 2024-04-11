#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<string.h>

using namespace std;

int n,cnt1,cnt2,cnt3;
char s[100005];

int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>(s+1);
		n=strlen(s+1);
		cnt1=cnt2=cnt3=0;
		for(int i=1;i<=n;i++){
			if(s[i]>='a'&&s[i]<='z')
				cnt1++;
			else if(s[i]>='A'&&s[i]<='Z')
				cnt2++;
			else if(s[i]>='0'&&s[i]<='9')
				cnt3++;
		}
		if(cnt1==0){
			if(cnt2>1){
				bool flag=false;
				for(int i=1;i<=n;i++){
					if(s[i]>='A'&&s[i]<='Z'){
						s[i]='a';
						flag=true;
						break;
					}
				}
				if(flag)
					cnt2--,cnt1++;
				else{
					for(int i=1;i<=n;i++){
						if(s[i]>='0'&&s[i]<='9'){
							s[i]='a',cnt3--,cnt1++;
							break;
						}
					}
				}
			}
			else{
				for(int i=1;i<=n;i++){
					if(s[i]>='0'&&s[i]<='9'){
						s[i]='a',cnt3--,cnt1++;
						break;
					}
				}
			}
		}
		if(cnt2==0){
			if(cnt1>1){
				bool flag=false;
				for(int i=1;i<=n;i++){
					if(s[i]>='a'&&s[i]<='z'){
						s[i]='A';
						flag=true;
						break;
					}
				}
				if(flag)
					cnt1--,cnt2++;
				else{
					for(int i=1;i<=n;i++){
						if(s[i]>='0'&&s[i]<='9'){
							s[i]='A',cnt3--,cnt2++;
							break;
						}
					}
				}
			}
			else{
				for(int i=1;i<=n;i++){
					if(s[i]>='0'&&s[i]<='9'){
						s[i]='A',cnt3--,cnt2++;
						break;
					}
				}
			}
		}
		if(cnt3==0){
			if(cnt1>1){
				bool flag=false;
				for(int i=1;i<=n;i++){
					if(s[i]>='a'&&s[i]<='z'){
						s[i]='0';
						flag=true;
						break;
					}
				}
				if(flag)
					cnt1--,cnt3++;
				else{
					for(int i=1;i<=n;i++){
						if(s[i]>='A'&&s[i]<='Z'){
							s[i]='0',cnt2--,cnt3++;
							break;
						}
					}
				}
			}
			else{
				for(int i=1;i<=n;i++){
					if(s[i]>='A'&&s[i]<='Z'){
						s[i]='0',cnt2--,cnt3++;
						break;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
			cout<<s[i];
		cout<<endl;
	}
	return 0;
}