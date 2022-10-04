#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#define For(i,a,b) for(int i=a;i<=(int)(b);i++)
#define Ford(i,a,b) for(int i=a;i>=(int)(b);i--)
using namespace std;
int n;
char ch;
int num;
vector<int> v; 
int main(){
	char ch,last='W';
	num=0;
	scanf("%d\n",&n);
	For(i,1,n){
		scanf("%c",&ch);
		//printf("%c\n",ch);
		if(ch=='B')
			num++;
		else if(last!=ch){
			v.push_back(num);
			num=0;
		}
		last=ch;
	}
	if(last=='B')v.push_back(num);
	printf("%d\n",v.size());
	For(i,0,v.size()-1)
		printf("%d ",v[i]);
	return 0;
}