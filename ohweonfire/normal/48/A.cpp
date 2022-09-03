#include <iostream>
#include <string.h>
using namespace std;
string a,b,c;
string s[3]={"rock","scissors","paper"};// 
int num[3];
int main(){
	cin>>a>>b>>c;
	for(int i=0;i<3;i++){
			if(a==s[i])num[i]++;
			if(b==s[i])num[i]++;
			if(c==s[i])num[i]++;
	}
	string ans;
	if(num[0]==1&&num[1]==2)ans=s[0];
	else if(num[1]==1&&num[2]==2)ans=s[1];
	else if(num[2]==1&&num[0]==2)ans=s[2];
	else {cout<<"?"<<endl;return 0;}
	if(a==ans)cout<<"F"<<endl;
	else if(b==ans)cout<<"M"<<endl;
	else cout<<"S"<<endl;
	//system("pause");
	return 0;
}