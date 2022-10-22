#include<bits/stdc++.h>
using namespace std;
const int inf=1000000000;
inline int in(){
	int x=0,f=1;
	char ch;
	do{
		ch=getchar();
		if(ch=='-')
		f=-1;
	}while(ch>'9'||ch<'0');
	do{
		x=(x<<3)+(x<<2)+ch-'0';
		ch=getchar();
	}while(ch<='9'&&ch>='0');
	return f*x;
}
char s,last;
int main(){
	int n=in();
	cin>>last;
	for(int i=1;i<n;i++) {
		cin>>s;
		if(s<last){
			cout<<"YES"<<endl;
			cout<<i<<" "<<i+1<<endl;
			return 0; 
		}
		last =s;
	}
	cout<<"NO";
	return 0;
}