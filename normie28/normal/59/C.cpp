#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
 
using namespace std;
	int64_t n,m,i,j,jj,k,e,minn,maxx,countt=0,counts=0,page,flag[26],removed=0,temp,op=0;vector <int64_t> a; string s1,s2; char c;
int cmp(int64_t a,int64_t b) {return a>b;}
int main()
{
	cin>>k; for (i=0;i<k;i++) flag[k]=0;
	cin>>s1;
	for (i=0;i<=(s1.length()-1)/2;i++) {
	if ((s1[i]=='?')and(s1[s1.length()-1-i]=='?')) a.push_back(i); else
	if ((s1[i]=='?')and(s1[s1.length()-1-i]!='?')) {flag[s1[s1.length()-1-i]-97]=1; s1[i]=s1[s1.length()-1-i];} else
	if ((s1[i]!='?')and(s1[s1.length()-1-i]=='?')) {flag[s1[i]-97]=1; s1[s1.length()-1-i]=s1[i];} else
	if ((s1[i]!='?')and(s1[s1.length()-1-i]!='?')) if (s1[i]==s1[s1.length()-1-i]) flag[s1[i]-97]=1; else {cout<<"IMPOSSIBLE"; return 0;}
}
	i=a.size()-1; j=k-1;
	if (a.size()>0) while (i>=0) {if ((flag[j]==0)or(j==0)) {c=j+97; s1[a[i]]=c;  s1[s1.length()-1-a[i]]=c; flag[j]=1; i--;} else j--;}
	for (i=0;i<k;i++) if (flag[i]==0) {cout<<"IMPOSSIBLE"; return 0;} 
	cout<<s1;
}