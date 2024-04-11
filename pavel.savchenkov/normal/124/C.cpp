#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
   char s[2000]; vector <int> k(31,0); 
   char c; int l=0;
   while (cin>>c)
		{k[c-'a']++;l++;s[l]='1';}
		
   s[l+1]='\0'; s[0]=' ';
   int min=100000; int mini;
   for (int i=0;i<=30;i++)
	   if (k[i]<min&&k[i]>0) {mini=i;min=k[i];}
	   
   s[1]=mini+'a'; k[mini]--;
   //for (int i=0;i<=30;i++) printf("%d ",k[i]);printf("\n");
   
   
   for (int i=2;i<=l;i++)
   {
	   if (s[i]=='1') 
	   {
		   int max=-1;int maxi=-1;
		   for (int j=i;j<=l;j+=i)
			   if (s[j]!='1') {
				max=k[s[j]-'a'];
                maxi=s[j]-'a';
                break;				
			   }
			   if (max==-1)
			   {
		         for (int j=0;j<=30;j++)
			     if (k[j]>max&&k[j]>0) {max=k[j];maxi=j;}
			   }
           if (maxi==-1) {printf("NO");}
		   for (int j=i;j<=l;j+=i)
			   {if (s[j]=='1') {s[j]=maxi+'a';k[maxi]--;}}
		   if (k[maxi]<0) {printf("NO");return 0;}
	   }
   }
   printf("YES\n");
   printf("%s",s);
   return 0;
}