#include<bits/stdc++.h>
using namespace std;
int t,a[26],tmp;
char ch[100010],res[100010];
int main(){
	scanf("%d",&t);
	while (t--){
		scanf("%s",ch);
		int l=strlen(ch);
		for (int i=0;i<l;i++) a[ch[i]-'a']++;
		int tmp=-1;
		for (int i=0;i<26;i++)
		if (a[i]==1){
			tmp=i;
			break;
		}
		if (tmp!=-1){
			printf("%c",'a'+tmp);
			a[tmp]=0;
			for (int i=0;i<26;i++)
			for (int j=0;j<a[i];j++) printf("%c",'a'+i);
		}
		else{
			int head;
			for (int i=0;i<26;i++)
			if (a[i]){
				res[0]='a'+i;
				a[i]--;
				head=i;
				break;
			}
			if (a[head]>l-a[head]){
				//printf("gg\n");
				int h2=-1;
				for (int i=head+1;i<26;i++)
				if (a[i]){
					res[1]='a'+i;
					a[i]--;
					h2=i;
					break;
				}
				if (h2!=-1){
					int h3=-1,tot=1;
					for (int i=h2+1;i<26;i++)
					if (a[i]){
						h3=i;
						break;
					}
					if (h3!=-1){
						for (int i=0;i<a[head];i++) res[++tot]='a'+head;
						a[head]=0;
						res[++tot]='a'+h3;
						a[h3]--;
						for (int i=0;i<a[h2];i++) res[++tot]='a'+h2;
						a[h2]=0;
						for (int i=0;i<26;i++)
						for (int j=0;j<a[i];j++) res[++tot]='a'+i;
					}
					else{
						for (int i=0;i<a[h2];i++) res[2+i]='a'+h2;
						for (int i=0;i<a[head];i++) res[2+a[h2]+i]='a'+head;
					}
				}
				else{ 
					for (int i=0;i<a[head];i++) res[i+1]='a'+head;
				}
			}
			else{
				//printf("gg:%d\n",l);
				res[1]='a'+head;
				a[head]--;
				for (int i=2;i<l;i++){
					for (int j=head+(res[i-1]==res[0]);j<26;j++)
					if (a[j]){
						res[i]='a'+j;
						a[j]--;
						break;
					}
				}
			}
			res[l]=0;
			printf("%s",res);
		}
		printf("\n");
		for (int i=0;i<26;i++) a[i]=0;
	}
}