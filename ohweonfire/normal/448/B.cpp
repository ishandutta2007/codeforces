#include <iostream>
#include <string>
using namespace std;
string a,b;
int c1[26],c2[26];
void init(){
	 for(int i=0;i<a.size();i++)c1[a[i]-'a']++;
	 for(int i=0;i<b.size();i++)c2[b[i]-'a']++;
}
bool needtree(){
	 for(int i=0;i<26;i++)if(c2[i]>c1[i])return true;
	 return false;
}
bool array(){
	 for(int i=0;i<26;i++)if(c2[i]!=c1[i])return false;
	 return true;
}
bool automaton(){
	 int g=0;
	 for(int i=0;i<b.size();i++){
	 		 while(g<a.size()&&a[g]!=b[i])g++;
	 		 if(g==a.size())return false;
g++;
	}
	return true;
}
int main(){
	cin>>a>>b;
	init();
	if(needtree())cout<<"need tree";
	else if(array())cout<<"array";
	else if(automaton())cout<<"automaton";
	else cout<<"both";
	//system("pause");
	return 0;
}