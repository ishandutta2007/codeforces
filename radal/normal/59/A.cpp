#include <iostream>
#include <algorithm>
using namespace std;
bool friends(int a,int b){
	if (a%b==0 || b%a==0){
		return 1;
	}
	return 0;
}
string uppercase(string a){
	for (int i=0; i<a.size(); i++){
		if (int(a[i])>=int('a')){
			a[i]=char(int (a[i])-int('a')+int('A'));
		}
	}
	return a; 
}
string down(string a){
	for (int i=0; i<a.size(); i++){
		if (int(a[i])>=int('A') and int(a[i])<int('a')){
			a[i]=char(int (a[i])+int('a')-int('A'));
		}
	}
	return a; 
}
int main(){
	string a;
	int tc=0,ts=0;
	cin>>a;
	for (int i=0; i<a.size(); i++){
		if (int(a[i])>=int('a')){
			ts+=1;
		}
		if (int(a[i])>=int('A') and int(a[i])<int('a')){
			tc+=1;
		}
	}
	if (tc>ts){
		cout<<uppercase(a);
	}
	else{
		cout<<down(a);
	}
}