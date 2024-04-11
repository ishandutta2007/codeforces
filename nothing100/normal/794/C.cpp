#include<bits/stdc++.h> 
using namespace std;
char ch[600030],ans[600030];
int a[666],b[666],ama,ami,bma,bmi;
void get(){
	ama=0,ami=25,bma=0,bmi=25;
		for (int j=0;j<26;j++) if (a[j]) ama=j;
		for (int j=0;j<26;j++)
		if (a[j]){
			ami=j;
			break;
		}
		for (int j=0;j<26;j++) if (b[j]) bma=j;
		for (int j=0;j<26;j++)
		if (b[j]){
			bmi=j;
			break;
		}
}
int main(){
	scanf("%s",ch);
	int n=strlen(ch);
	for (int i=0;i<n;i++) {
	if (ch[i] < 'a' || ch[i] > 'z') while(1);
	a[ch[i]-'a']++;
	}
	scanf("%s",ch);
	
	if (strlen(ch) != n) while(1);
	for (int i=0;i<n;i++) {
		b[ch[i]-'a']++;
		if (ch[i] < 'a' || ch[i] > 'z') while(1);
	}
	for (int i=0;i<n;i++){
		get();
		if (bma<=ami){
			if ((n-i)&1){
				for (int j=i;j<n;j+=2){
					get();
					if (i&1){ans[j]='a'+bma;b[bma]--;}
					else {ans[j]='a'+ami;a[ami]--;}
				}
				for (int j=i+1;j<n;j+=2){
					get();
					if (i&1){ans[j]='a'+ami;a[ami]--;}
					else {ans[j]='a'+bma;b[bma]--;}
				}
			}
			else{
				for (int j=i+1;j<n;j+=2){
					get();
					if (i&1){ans[j]='a'+bma;b[bma]--;}
					else {ans[j]='a'+ami;a[ami]--;}
				}
				for (int j=i;j<n;j+=2){
					get();
					if (i&1){ans[j]='a'+ami;a[ami]--;}
					else {ans[j]='a'+bma;b[bma]--;}
				}
			}
			break;
		}
		else{
			if (i&1){ans[i]='a'+bma;b[bma]--;}
			else {ans[i]='a'+ami;a[ami]--;}
		}
	}
	if (strlen(ans) != n) while(1);
	printf("%s",ans);
}